/*
 * SeverityQueue.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#include "SeverityQueue.h"
#include <iostream>
#include <stdexcept>
//#define NULL 0

SeverityQueue::SeverityQueue(int size)
{
	// TODO Auto-generated constructor stub
	pq = new Control[size];
	pqSize = 0;
}

SeverityQueue::~SeverityQueue()
{
	// TODO Auto-generated destructor stub
}

void SeverityQueue::balance(int index)
{
	int i = index + 1;
	int leftIndex = i * 2 - 1;
	int rightIndex = i * 2;
	int largest = index;
	if(leftIndex <= pqSize - 1  && pq[leftIndex].severity > pq[index].severity)
	{
		largest = leftIndex;
	}
	if(rightIndex <= pqSize - 1 && pq[rightIndex].severity > pq[largest].severity)
	{
		largest = rightIndex;
	}
	if(largest != index)
	{
		Control c = pq[index];
		pq[index] = pq[largest];
		pq[index].index = index;
		pq[largest] = c;
		c.index = largest;
		balance(largest);
	}

}

void SeverityQueue::insert(Control c)
{
	c.index = pqSize;
	++pqSize;
	pq[pqSize - 1] = c;
	increaseKey(c);
}

void SeverityQueue::increaseKey(Control c)
{
	int i = c.index + 1;
	int parentIndex = (i / 2) - 1;
	while(c.index > 0 && pq[parentIndex].severity < pq[c.index].severity)
	{
		pq[c.index] = pq[parentIndex];
		pq[c.index].index = c.index;
		pq[parentIndex] = c;
		c.index = parentIndex;
		i = c.index + 1;
		parentIndex = (i / 2) - 1;
	}

}

Control SeverityQueue::deleteMin()
{
	Control min = pq[0];
	pq[0] = pq[pqSize - 1];
//	pq[pqSize - 1] = NULL;
//	delete &pq[pqSize-1];
	--pqSize;
	balance(0);
	return min;
}

void SeverityQueue::deleteControl(Control c)
{
	Control toDelete = pq[0];
	int i = 0;
	while(toDelete != c)
	{
		++i;
		toDelete = pq[i];
	}

	pq[i] = pq[pqSize-1];
	--pqSize;
	balance(i);
}

int SeverityQueue::size()
{
	return pqSize;
}

Control SeverityQueue::getIndex(int index)
{
	if(index >= pqSize)
	{
		Control empty;
		return empty;
	}
	return pq[index];
}
