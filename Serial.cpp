// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

/*
traverse the list for i= 0 to n-1 elements
{
  check for sign of A[abs(A[i])] ;
  if positive then
     make it negative by   A[abs(A[i])]=-A[abs(A[i])];
  else  // i.e., A[abs(A[i])] is negative
     this   element (ith element of list) is a repetition
}
*/

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>    
#include <stdlib.h> 

int serial(std::vector<int> nums) {
	for(int i = 0; i < nums.size(); i++){
		std::cout<< nums[i] << std::endl;
	}

	for(int i = 0; i < nums.size(); i++) { 
		std::cout<<"[ " << nums[nums[i]] <<" ] " << std::endl;
		if(nums[nums[i]] < 0){
			return nums[nums[i]]*-1;
		}
		else{
			nums[nums[i]] = nums[nums[i]]*-1;
		}
	}
  return 0;
}
#endif
