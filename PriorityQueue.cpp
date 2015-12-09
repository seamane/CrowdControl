/*
 * PriorityQueue.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: ericseaman
 */

#include "PriorityQueue.h"
#include <stdexcept>
#include <iostream>
//#define NULL 0

PriorityQueue::PriorityQueue(int size) {
	// TODO Auto-generated constructor stub
	pq = new Control[size];
	pqSize = 0;
}

PriorityQueue::~PriorityQueue() {
	// TODO Auto-generated destructor stub
}

void PriorityQueue::balance(int index)
{
	int i = index + 1;
	int leftIndex = i * 2 - 1;
	int rightIndex = i * 2;
	int smallest = index;
	if(leftIndex <= pqSize - 1  && pq[leftIndex].beginTime < pq[index].beginTime)
	{
		smallest = leftIndex;
	}
	if(rightIndex <= pqSize - 1 && pq[rightIndex].beginTime < pq[smallest].beginTime)
	{
		smallest = rightIndex;
	}
	if(smallest != index)
	{
		Control c = pq[index];
		pq[index] = pq[smallest];
		pq[index].index = index;
		pq[smallest] = c;
		c.index = smallest;
		balance(smallest);
	}

}

void PriorityQueue::insert(Control c)
{
    c.index = pqSize;
    ++pqSize;
    pq[pqSize - 1] = c;
    decreaseKey(c);
}

void PriorityQueue::decreaseKey(Control c)
{
    int i = c.index + 1;
    int parentIndex = (i / 2) - 1;
    while(c.index > 0 && pq[parentIndex].beginTime > pq[c.index].beginTime)
    {
        pq[c.index] = pq[parentIndex];
        pq[c.index].index = c.index;
        pq[parentIndex] = c;
        c.index = parentIndex;
        i = c.index + 1;
        parentIndex = (i / 2) - 1;
    }

}

Control PriorityQueue::deleteMin()
{
    Control min = pq[0];
    pq[0] = pq[pqSize - 1];
//    pq[pqSize - 1] = NULL;
//    delete &pq[pqSize-1];
    --pqSize;
    balance(0);
    return min;
}

int PriorityQueue::size()
{
	return pqSize;
}

Control PriorityQueue::getIndex(int index)
{
	try
	{
		return pq[index];
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}

	throw std::out_of_range("");
}
