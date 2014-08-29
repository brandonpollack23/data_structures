//Brandon Pollack
//2375-4365
#ifndef MAXWINNERTREE
#define MAXWINNERTREE
#include "BinaryTree.h"
#include <algorithm>

class MaxWinnerTree : public BinaryTree
{
private:
	int height;
	int nextHeight();
public:
	MaxWinnerTree(int binCap, int height = 6); // there will be 2^(h-1) leaves default 32

	Bin* runTourney(Node* node);
	void runTourney() { root->bin = runTourney(root); };

	Node* firstFittingNode(int value);

	void addContender(); //makes the next leaf who's current cap is 0 into another bin

	void addLayer(Node* node);
	void addLayer() { addLayer(root); }//add a layer of 2^(newh-1) nodes

	void printNonEmptyLeaves();
};
#endif