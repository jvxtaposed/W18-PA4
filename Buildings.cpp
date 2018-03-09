
// CSE 101 Winter 2018, PA 4
//
// Name: Ishan Goyal, Jennifer Fung
// PID: A12094992, A12099804
// Sources of Help: None
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include <queue>
#include <iostream>
#include "Interval.hpp"
#include "Buildings.hpp"

/* interval: start == rows, end == cols

*/

static int b = 0;

static void floodfill(TwoD_Array<int> survey, int r, int c){
	Interval *node = new Interval(r, c);
	std::queue<Interval*> q;
	q.push(node);
	while(!q.empty()){

		Interval *popped = q.front();
		std::cout<< "popping: " << popped->start<<","<<popped->end << std::endl; 
		q.pop();
		survey.at(popped->start, popped->end) = 0;
		survey.printOut();
		//go down
		int south = survey.at(popped->start+1, popped->end);
		if(south == 1 && popped->start+1 < survey.getNumRows()){
			survey.at(popped->start+1, popped->end) = 0;
			Interval *s = new Interval(popped->start+1, popped->end);
			std::cout<<"south pushing: " << s->start <<","<<s->end<< std::endl;
			q.push(s);
			}
		//go up
		int north = survey.at(popped->start-1, popped->end);
		if(north == 1 && popped->start-1 >= 0){
			survey.at(popped->start-1, popped->end) = 0;
			Interval *n = new Interval(popped->start-1, popped->end);
			std::cout<<"north pushing: " << n->start <<","<<n->end<< std::endl;
			q.push(n);
		}
		//go right
		int east = survey.at(popped->start, popped->end+1);
		if(east ==1 && popped->end+1 < survey.getNumCols()){
			survey.at(popped->start, popped->end+1) = 0;
			Interval *e = new Interval(popped->start, popped->end+1);
			std::cout<<"east pushing: " << e->start <<","<<e->end<< std::endl;
			q.push(e);
		}
		//go left
		int west = survey.at(popped->start, popped->end-1);
		if(west ==1 && popped->end-1 >= 0){
			survey.at(popped->start, popped->end-1) = 0;
			Interval *w = new Interval(popped->start, popped->end-1);
			std::cout<<"west pushing: " << w->start <<","<<w->end<< std::endl;
			q.push(w);
		}

	}
	b++;
			std::cout<<"b: " << b << std::endl;	
}

int buildings(TwoD_Array<int> survey) {
	//auto arr = new TwoD_Array<int>(grid.getNumRows(), grid.getNumCols());
	for(int row = 0; row < survey.getNumRows(); row++){
		for(int col = 0; col < survey.getNumCols(); col++){
			if(survey.at(row,col) == 1){
				floodfill(survey, row, col);
		//		b++;
	
			}
		}
	}
  return b;
}
#endif
