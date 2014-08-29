//Brandon Pollack
//2375-4365
//1087
#include "queue.h"
using namespace std;
/*
myQueue::myQueue(int initialCapacity = 100)
{
	// Constructor.
	try
	{
   		if (initialCapacity < 1)
   		{
			ostringstream s;
    			s << "Initial capacity = " 
      				<< initialCapacity << " Must be > 0";
    			throw illegalParameterValue(s.str());
		}
	}
	catch(illegalParameterValue& e){
		e.outputMessage();
		return;
	} 

	arrayLength = initialCapacity;
   	element = new int[arrayLength];
   	listSize = 0;
	arrayList(initialCapacity);
}

myQueue::myQueue(const arrayList& theList)
{
	// Copy constructor.
   	arrayLength = theList.capacity();
   	listSize = theList.size();
   	element = new int[arrayLength];
   	copy(theList.get(0), theList.get(listSize), element);
}*/

void myQueue::push(int item)
{
	insert(listSize,item);
}

int myQueue::pop()
{
	int popped = peek();
	erase(0);
	return popped;
}

int myQueue::peek()
{
	return element[0];
}

int myQueue::back()
{
	return element[size()-1];
}