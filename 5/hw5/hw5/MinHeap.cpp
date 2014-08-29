//Brandon Pollack
//2375-4365
#include "MinHeap.h"
#include <algorithm>

void minheap::initialize(const arrayList* init, int size)
{
	for(int i = 0; i < init->size(); i++)
	{
		insert(listSize, *(init->get(i))); //listSize starts at 0 so we are just copying over
	}

	//TODO order n algorithm
	setup();
}

void minheap::setup()
{
	int first = nparent(listSize-1);
	setup(first);
}

void minheap::setup(int currentNode, bool doParent)
{
	if(nleft(currentNode) > listSize-1 && nright(currentNode) > listSize-1) return; //if this node has no children at all return

	int *a = NULL;
	int *b = NULL;
	if(nleft(currentNode) < listSize) a = &element[nleft(currentNode)]; //store those nodes to compare
	if(nright(currentNode) < listSize) b = &element[nright(currentNode)];

	if(a != NULL && b != NULL && (*a < element[currentNode] || *b < element[currentNode]))
	{
		if(*a < *b) std::swap(*a,element[currentNode]); 
		else std::swap(*b,element[currentNode]); //swap with the min one, bubble up the mins
	}
	else
	{
		if(a == NULL && b != NULL && *b < element[currentNode])
		{
			std::swap(*b,element[currentNode]);
		}
		else if(b == NULL && a != NULL && *a < element[currentNode])
		{
			std::swap(*a,element[currentNode]);
		}
	}

	//now run it again on the children if they exist
	setup(nleft(currentNode),false);
	setup(nright(currentNode),false); //because these are recursive steps to check baby nodes, no need to go and infinite loop between parent and left node
	
	//now we have to run recursively on the parent of this node
	if(currentNode != 0 && doParent)
	{
		setup(nparent(currentNode));
	}
	else return;
}

void minheap::bubble_up()
{
	int currentNode = listSize-1;
	bubble_up(currentNode);
}

void minheap::bubble_up(int currentNode)
{
	if(currentNode == 0) return;
	else if(element[nparent(currentNode)] > element[currentNode]) //if parent is bigger swap with parent
	{
		std::swap(element[nparent(currentNode)],element[currentNode]);
		bubble_up(element[nparent(currentNode)]); //then run on that parent node
	}
	else return;
}

void minheap::bubble_down(int currentNode)
{
	if(nleft(currentNode) > listSize-1) return;

	int *a = &element[nleft(currentNode)];
	int *b = &element[nright(currentNode)];

	if (*a < *b && (*a < element[currentNode] || *b < element[currentNode]))
	{
		std::swap(*a,element[currentNode]);
		bubble_down(nleft(currentNode));
	}
	else if(*b < *a && (*a < element[currentNode] || *b < element[currentNode]))
	{
		std::swap(*b,element[currentNode]);
		bubble_down(nright(currentNode));
	}
}

void minheap::add_to_heap(int elem)
{
	place_bottom(elem);
	bubble_up();
}
