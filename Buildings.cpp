
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

	//	std::cout << "queue size: " << q.size() << std::endl;
		Interval *w = new Interval(popped->start, popped->end);
		Interval *e = new Interval(popped->start, popped->end);

		//explore go left
		while(survey.at(w->start, w->end) == 1 && w->end >= 0){
			std::cout<< " in west col: " << w->end << std::endl;
			survey.at(w->start, w->end) = 0;
			survey.printOut();
			//explore north
			int north = survey.at(w->start+1, w->end);
			if(north == 1 && w->start+1 >= 0){
				Interval *temp = new Interval(w->start+1, w->end);
				std::cout<<"WN pushing: " << temp->start <<","<<temp->end<< std::endl;
				q.push(temp);
			}
			//explore south
			int south = survey.at(w->start-1, w->end);
			if(south == 1 && w->start-1 >= 0){
				Interval *tempNs = new Interval(w->start-1, w->end);
				std::cout<<"WS pushing: " << tempNs->start <<","<<tempNs->end <<std::endl;		
				q.push(tempNs);
			}
			w->end = w->end-1;
			//survey.at(w->start, w->end) != nullptr || survey.at(w0>start, w->end) != 0

		}

		//explore right
		while(survey.at(e->start, e->end) == 1 && e->end >= 0){
			std::cout<< "in east col: "<< e->end << std::endl;
			survey.at(e->start, e->end) = 0;
			survey.printOut();
			//explore north
			int north = survey.at(e->start+1, e->end);
			if(north == 1 && e->start+1 >= 0){
				Interval *tempEn = new Interval(e->start+1, e->end);
				std::cout<<"EN pushing: " << tempEn->start <<","<<tempEn->end <<std::endl;		
				q.push(tempEn);
			}
			//explore south
			int south = survey.at(e->start-1, e->end);
			if(south == 1 && e->start-1 >= 0){
				Interval *tempEs = new Interval(e->start-1, e->end);
				std::cout<<"ES pushing: " << tempEs->start <<","<<tempEs->end <<std::endl;		
				q.push(tempEs);
			}
			e->end = e->end+1;
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
