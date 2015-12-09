/*
 * PriorityQueue.h
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Control.h"
#define NULL 0

using namespace std;

class PriorityQueue {
public:
	PriorityQueue(){pq = NULL;pqSize=0;}
	PriorityQueue(int);
	~PriorityQueue();

	void insert(Control);
	Control deleteMin();
	void balance(int);
	void decreaseKey(Control);
	int size();
	Control getIndex(int);

private:
	Control* pq;
	int pqSize;
};

#endif /* PRIORITYQUEUE_H_ */
