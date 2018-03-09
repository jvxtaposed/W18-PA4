// CSE 101 Winter 2018, PA 4
//
// Name: Ishan Goyal, Jennifer Fung
// PID: A12094992, A12099804
// Sources of Help: None
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"
#include <algorithm>
#include <iostream>
#include <climits>

/*
 * Input: MxN matrix of temperatures for rooms in a warehouse
 * Output: Minimum amount of ice needed to start with in the top left room
 * 	   and make it to the bottom right with atleast one unit of ice
 */

//Cannot allow the value of ice to reach 0, can only move down or right
int ice(TwoD_Array<int> rooms) {
  int numRows = rooms.getNumRows();
  int numCols = rooms.getNumCols();
  //Error checking
  if(numRows <= 0 || numCols <= 0)
  {
  	return 0;
  } 
  //Create a new 2D array in memory
  TwoD_Array<int> * iceArray = new TwoD_Array<int>(numRows+1, numCols+1);
  //Initialize the 2D array
  for(int i = 0; i <= numRows; i++)
  {
  	for(int j = 0; j <= numCols; j++)
  	{
		//Set outer limits to the grid to infinity
  		if(i==numRows || j==numCols)
  		{
  			iceArray->at(i,j) = INT_MAX;
  		}
		//Otherwise initialize the score to 0
		else
		{
			iceArray->at(i,j) = 0;
		}
  	}
  }
  //Populate score array starting at index (numRows,numCols)
  for(int b = numCols-1; b >= 0; b--)
  {
  	for(int a = numRows-1; a >= 0; a--)
	{
		//std::cout << "Coordinates = ("<<a<<","<<b<<")"<<std::endl;
		//Set bottom left score to 1+temperature in bottom left room
		if(a==numRows-1 && b==numCols-1)
		{
			//We add one because we need at least one ice to exit
			iceArray->at(a,b) = rooms.at(numRows-1,numCols-1)+1;
		}
		else
		{
			//Check the cells below and to the right 
			//Take the minimum value of sum of temp & score
			iceArray->at(a,b) = std::min((rooms.at(a,b)+
					    iceArray->at(a+1,b)),(rooms.at(a,
					    b)+iceArray->at(a,b+1)));
			//Since we cannot have negative or 0 ice, set = 1
			if(iceArray->at(a,b) <= 0)
			{
				iceArray->at(a,b) = 1;
			}
		}
	}
  }
  //Return the minimum amount needed to start with
  int retval = iceArray->at(0,0);
  return retval;	
}
#endif