// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include <queue>
#include "Interval.hpp"
#include "Buildings.hpp"

/* interval: start == rows, end == cols

*/

static void floodfill(TwoD_Array<int> survey, Interval node, int target, int replace){
	if (target == replace){
		return;
	}
	if (survey.at.(node->start, node->end) != target){
		return;
	}
	std::queue<Interval> q;
	q.push(node);
	while(!q.empty()){
		Interval popped = q.top();
		q.pop();
		int w = survey.at(popped->start, popped->end);
		int e = survey.at(popped->start, popped->end);
		for(int i = popped->end ; i< survey.getNumCols(); i++){

		}
		for(int i = popped->end; i >= 0; i--){
			
		}
	}


}

int buildings(TwoD_Array<int> survey) {
	arr = new TwoD_Array<int>(survey.getNumRows(), survey.getNumCols());

  return 0;
}
#endif
