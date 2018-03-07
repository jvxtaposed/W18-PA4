// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

/*
1- Traverse the given array from i= 0 to n-1 elements
     Go to index arr[i]%n and increment its value by n.
3- Now traverse the array again and print all those 
   indexes i for which arr[i]/n is greater than 1.

This approach works because all elements are in range
from 0 to n-1 and arr[i]/n would be greater than 1
only if a value "i" has appeared more than once.

*/

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>    
#include <stdlib.h> 
#include <map>

int serial(std::vector<int> nums) {
	std::map<int,int> store;
	for(int i = 0; i < nums.size(); i++){
		if(store.insert(std::pair<int,int>(nums[i],i)).second == false){
			return nums[i];
		}
		else{
			store.insert(std::pair<int,int>(nums[i],i))
		}
	}

	/*

	for(auto it = store.begin(); it != store.end(); it++){
		std::cout <<"key: " << it->first <<" elem: " << it->second << std::endl;
	}

	for( int i = 0; i< nums.size(); i++){
		if()
	}
	*/


/*
	for(int i = 0; i < nums.size(); i++) { 

		int index = nums[i]%nums.size(); 
		nums[index] += nums.size();
		std::cout<<"index:" << nums[i]%nums.size() <<"\t nums[index]:" <<
			nums[index] << std::endl;
		
	}
	for(int i = 0; i < nums.size(); i++) { 
		std::cout<<"nums[i]/n" << (nums[i]/nums.size()) <<"\t " << std::endl;
		if((nums[i]/nums.size()) > 1){
			std::cout<<"in if:nums[i] " << nums[i] <<"" << std::endl;
			return nums[i];
		}
	}
	*/
  return 0;
}
#endif
