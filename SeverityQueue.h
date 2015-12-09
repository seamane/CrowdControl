/*
 * SeverityQueue.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#ifndef SEVERITYQUEUE_H_
#define SEVERITYQUEUE_H_

#include "Control.h"
#define NULL 0

using namespace std;

class SeverityQueue {
public:
	SeverityQueue(){pq = NULL;pqSize = 0;}
	SeverityQueue(int);
	~SeverityQueue();

	void insert(Control);
	Control deleteMin();
	void balance(int);
	void increaseKey(Control);
	int size();
	Control getIndex(int);
	void deleteControl(Control);

private:
	Control* pq;
	int pqSize;
};

#endif /* SEVERITYQUEUE_H_ */
