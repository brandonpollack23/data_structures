//Brandon Pollack
//2375-4365
//1087
#ifndef QUEUE_
#define QUEUE_
#include "Arraylist.h"


class myQueue : public arrayList
{
public:
	myQueue(int initialCapacity = 100):arrayList(initialCapacity){}
	myQueue(const arrayList& initList):arrayList(initList){}
	~myQueue() { delete[] element; }
	void push(int item);
	int pop();
	int back();
	int peek();
};
#endif