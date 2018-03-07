// CSE 101 Winter 2018, PA 4
//
// Name: Ishan Goyal, Jennifer Fung
// PID: A12094992, A12099804
// Sources of Help: None
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include <algorithm>
#include "Tennis.hpp"
#include "Graph.hpp"
#include <iostream>
struct myclass{
bool operator()(Interval i, Interval j) {
	return i.start < j.start;
}
} myobject;

int tennis(std::vector<Interval> lessons) {
	std::sort ( lessons.begin(), lessons.end(), myobject);
	std::vector<std::vector<Interval>> courts;
	std::vector<Interval> first;
	courts.push_back(first);
	for(auto it = lessons.begin(); it != lessons.end(); it++){
	//	std::cout << "lesson: " << it->start << " " << it->end << std::endl;
		if(courts.at(0).size() == 0){
			courts.at(0).push_back(*it);
		}
		else{
			bool inserted = false;
			for(auto i = courts.begin(); i != courts.end(); i++){
				Interval temp = (*i).back();
				if(it->start >= temp.end){
				//	std::cout<< "in else if \n";
					i->push_back(*it);
					inserted = true;
					break;
				}
			}
			if(inserted == false){
//			std::cout << "in if \n";	
				std::vector<Interval> newVector;
				newVector.push_back(*it);
				courts.push_back(newVector); 
			}
		}

	}
/*
	for(auto jj = courts.begin(); jj!= courts.end(); jj++){
		for( auto c = jj->begin(); c != jj->end(); c++){
			std::cout << c->start << "," << c->end << " " << std::endl;
		} 
	}
*/


		
 return courts.size();
}
#endif
