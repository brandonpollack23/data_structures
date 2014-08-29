//Brandon Pollack
//2375-4365
#include "PriorityQueue.h"

const int PriorityQueue::top() const
{
	return element[0];
}

void PriorityQueue::pop()
{
	element[0] = element[listSize-1];
	erase(listSize-1);
	bubble_down();
}

void PriorityQueue::put(const int elem)
{
	add_to_heap(elem);
}

void PriorityQueue::sort()
{
	while(!empty())
	{
		std::cout << top() << ' ';
		pop();
	}
}