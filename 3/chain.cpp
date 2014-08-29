//Chain method implementations
//Brandon Pollack
//2375-4365
#include "Chain.h"

using namespace std;

Chain::Chain()
{
	firstNode = NULL;
	chainSize = 0;
}

Chain::Chain(const Chain& initChain)
{
	chainSize = initChain.size();
	firstNode = initChain.getFirstNode();
}

Chain::Chain(int initSize)
{
	if(initSize >= 0)
	{
		Chain();
	}
	else cout << "Size must be a number greater than or equal to 0";
}

bool Chain::empty() const
{
	if(firstNode == NULL) return true;
	else return false;
}

int Chain::size() const
{
	return chainSize;
}

int* Chain::get(int theIndex) const
{
	if(theIndex < chainSize)
	{
		struct ChainNode* answerNode = firstNode;
		for(int i = 0; i < theIndex; i++)
		{
			answerNode = answerNode->nextNode;
		}
		return &(answerNode->data);
	}
	else cout << "Index " << theIndex << " is out of bounds" << endl;
}

int Chain::indexOf(const int& theElement) const
{
	struct ChainNode* currentNode = firstNode;
	for(int i = 0; i < chainSize; i++)
	{
		if (theElement == currentNode->data) return i;
		currentNode = currentNode->nextNode;
	}
	return -1;
}

void Chain::erase(int theIndex) // TO FIX THIS
{
	if(theIndex == 0 && theIndex < chainSize)
	{
		struct ChainNode* deleteNode = firstNode;
		firstNode = firstNode->nextNode;
		delete deleteNode;
		chainSize--;
	}
	else if(theIndex < chainSize)
	{
		struct ChainNode* currentNode = firstNode;
		for(int i = 0; i < theIndex; i++)
		{
			currentNode = currentNode->nextNode; 
		} //iterate until the node before the one we want to delete

		struct ChainNode* deleteNode = currentNode;
		currentNode->nextNode = deleteNode->nextNode;
		delete deleteNode;
		chainSize--;
	}
	else cout << "The index " << theIndex << " is out of range" << endl;
}

void Chain::insert(int theIndex, const int& theElement)
{
	if(chainSize == 0)
	{
		firstNode = new ChainNode;
		firstNode->data = theElement;
		firstNode->nextNode = NULL;
		chainSize++;
	}
	else if(theIndex == 0)
	{
		ChainNode* newFirstNode = new ChainNode;
		newFirstNode->nextNode = firstNode;
		firstNode = newFirstNode;
		firstNode->data = theElement;
		chainSize++;
	}
	else if(theIndex < chainSize)
	{
		struct ChainNode* currentNode = firstNode;
		for(int i = 0; i < theIndex; i++)
		{
			currentNode = currentNode->nextNode;
		}
		struct ChainNode* afterNew = currentNode->nextNode; //hold the pointer for the new node to point to
		currentNode->nextNode = new ChainNode; //allocate a new chain there after the current
		currentNode->nextNode->nextNode = afterNew; //link it into the chain after the new
		currentNode->nextNode->data = theElement; //shove that data in
		chainSize++;
	}
	else if(theIndex == chainSize) //if this is the end of the list then go ahead and just make that first node not all NULL
	{
		ChainNode* currentNode = firstNode;
		while(currentNode->nextNode != NULL)
		{
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = new ChainNode;
		currentNode->nextNode->nextNode = NULL;
		currentNode->nextNode->data = theElement;
		chainSize++;
	}
	else cout << "The index " << theIndex << " is out of bounds";
}

void Chain::traverse()
{
	if(chainSize == 0)
	{
		cout << "The linked list is empty" << endl;
	}
	else
	{
		struct ChainNode* currentNode = firstNode;
		for(int i = 0; i < chainSize; i++)
		{
			cout << (currentNode->data) << ' ';
			currentNode = currentNode->nextNode;
		}
		//cout << (currentNode->data);
	}
}

void Chain::MaxMin()
{
	struct ChainNode* currentNode = firstNode;
	int max = currentNode->data;
	int min = currentNode->data;
	while(currentNode->nextNode != NULL)
	{
		if(currentNode->data > max) max = currentNode->data;
		if(currentNode->data < min) min = currentNode->data;
		currentNode = currentNode->nextNode;
	}
	if(currentNode->data > max) max = currentNode->data;
	if(currentNode->data < min) min = currentNode->data;

	cout << "Max: " << max <<  " Min: " << min;
}

ChainNode* Chain::getFirstNode() const
{
	return firstNode;
}

