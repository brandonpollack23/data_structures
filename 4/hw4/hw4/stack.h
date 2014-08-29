//Brandon Pollack
//2375-4365
//1087
#ifndef STACK
#define STACK
#include "Arraylist.h"

class myStack : public arrayList
{
public:
	myStack(int initialSize = 100):arrayList(initialSize){}
	myStack(arrayList& theList):arrayList(theList){}
	~myStack() { delete[] element; }
	void push(int item);
	int pop();
	int peek();
};
#endif