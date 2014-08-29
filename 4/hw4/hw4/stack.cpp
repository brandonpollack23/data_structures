//Brandon Pollack
//2375-4365
//1087
#include "stack.h"

using namespace std;

/*myStack::myStack(int initialCapacity = 100)
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

myStack::myStack(arrayList& theList)
{
	// Copy constructor.
   	arrayLength = theList.capacity();
   	listSize = theList.size();
   	element = new int[arrayLength];
   	copy(theList.get(0), theList.get(listSize), element);
}*/

void myStack::push(int item)
{
	insert(0, item);
}

int myStack::pop()
{
	int popped = peek();
	erase(0);
	return popped;
}

int myStack::peek()
{
	return element[0];
}