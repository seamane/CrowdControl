/*
 * CrowdControlSolver.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#include "CrowdControlSolver.h"
#include <iostream>
#include <sstream>

CrowdControlSolver::CrowdControlSolver(string input, int numEntries) : pq(numEntries) , sq(numEntries)
{
	// TODO Auto-generated constructor stub
	this->input = input;
	sq.setMode(PriorityQueue<int>::DESCENDING);
}

CrowdControlSolver::~CrowdControlSolver() {
	// TODO Auto-generated destructor stub
}

void CrowdControlSolver::run()
{
	parseInput();
	produceOutput();
}

void CrowdControlSolver::parseInput()
{
	int numEntries;
	stringstream ss(input);
	ss >> numEntries;

	int beginTime;
	int duration;
	int severity;

	while(ss >> beginTime >> duration >> severity)
	{
		Control c(beginTime,duration,severity,true);
		pq.insert(c);
	}
}
void CrowdControlSolver::produceOutput()
{
	cout << endl;
	Control cc;
	int currentTime = 0;
	while(pq.size() > 0)
	{
		do
		{
			cc = pq.deleteMin();//grab next cc to be handled
			currentTime = cc.beginTime;
			if(!cc.active)//if the cc hasn't been started yet
			{
				cc.beginTime += cc.duration;
				cc.active = true;
				pq.insert(cc);
				cc.compareTime = false;
				sq.insert(cc);
			}
			else
			{
				sq.deleteObject(cc);
			}
		}
		while(pq.getIndex(0).beginTime == currentTime);

		if(sq.getIndex(0) != currentSevereControl)
		{
			currentSevereControl = sq.getIndex(0);
			cout << currentTime << " " << currentSevereControl.severity << endl;
		}
	}
}

