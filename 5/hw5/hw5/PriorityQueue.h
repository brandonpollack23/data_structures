//Brandon Pollack
//2375-4365

//dont forget initialize method

#ifndef PRIORITYQUEUE
#define PRIORITYQUEUE
#include "MinHeap.h"

class PriorityQueue : public minheap
{
public:
	PriorityQueue() : minheap() {};
	const int top() const;
	void pop();
	void put(const int elem);
	void sort();
};

#endif