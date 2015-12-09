/*
 * CrowdControlSolver.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#ifndef CROWDCONTROLSOLVER_H_
#define CROWDCONTROLSOLVER_H_

#include <string>
#include "PriorityQueue.h"
#include "SeverityQueue.h"

using namespace std;

class CrowdControlSolver {
public:
	CrowdControlSolver(string,int);
	~CrowdControlSolver();

	void run();

private:
	string input;
	PriorityQueue pq;
	SeverityQueue sq;
	Control currentSevereControl;


	void parseInput();
	void produceOutput();

};

#endif /* CROWDCONTROLSOLVER_H_ */
