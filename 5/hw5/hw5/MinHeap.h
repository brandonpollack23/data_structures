//Brandon Pollack
//2375-4365
#ifndef MINHEAP
#define MINHEAP
#include "BinaryTree.h"

class minheap : public BinaryTree
{
public:
	minheap() : BinaryTree() {};
	void initialize(const arrayList* init, int size);
	void add_to_heap(int elem);
private:
	void setup();
	void setup(int currentNode, bool doParent = true);
protected:
	void bubble_up();
	void bubble_up(int currentNode);
	void bubble_down(int currentNode = 0);
};
#endif