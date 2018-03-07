// CSE 101 Winter 2018, PA 4
//
// Name: Ishan Goyal, Jennifer Fung
// PID: A12094992, A12099804
// Sources of Help: None
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>
/*
 *Input: Sorted list of consecutively increasing factory serial numbers (int)
	 in increasing order, with one serial number printed multiple times
 *
 *Output: The serial number that is printed multiple times 
 */

//Numbers will be non-negative, guranteed a duplicate
//Use binary search to find the duplicate
int serial(std::vector<int> nums) {
  int size = nums.size();
  int middle = (size/2);
  int low = 0;
  int high = size;
  while(low < high)
  {
	middle = (low + high)/2;
	if(nums.at(middle+1)==nums.at(middle))
  	{
		//std::cout<<nums.at(middle-1)<<","<<nums.at(middle)<<std::endl;
    		return nums.at(middle);
  	}
  	else
  	{
		//go right
		if(middle == nums.at(middle)-nums[0])
		{
			low = middle;
		}
		//go left
		else
		{
			high = middle;
		}
  	}
  }
  return 0;
}
#endif
