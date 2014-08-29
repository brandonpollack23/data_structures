//Chain.h containing the prototype methods, just like Arraylist.h
//Brandon Pollack
//2375-4365
#include "Linearlist.h"
#include "ChainNode.h"

using namespace std; 

class Chain: public linearList 
{
public:
	Chain();
	Chain(const Chain&);
	Chain(int initSize);
	~Chain()
	{
		while(firstNode != NULL)
		{
			ChainNode* nextNode = firstNode->nextNode;
			delete firstNode;
			firstNode = nextNode;
		}
	}

    virtual bool empty() const;
    virtual int size() const;
    virtual int* get(int theIndex) const;
    virtual int indexOf(const int& theElement)const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex, const int& theElement);
	virtual void traverse();
	virtual void MaxMin();

	ChainNode* getFirstNode() const;

protected:
	ChainNode *firstNode;
	int chainSize;
};