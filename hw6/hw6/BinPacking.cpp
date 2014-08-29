//Brandon Pollack
//2375-4365
#include "BinPacking.h"

BinPacker::BinPacker(int capacity)
{
	this->capacity = capacity;
}

/*******************/
BinPackerFirst::BinPackerFirst(int capacity) : BinPacker(capacity)
{
	tree = new MaxWinnerTree(capacity);
}

void BinPackerFirst::packValue(int value)
{
	Node* toPack = tree->firstFittingNode(value);
	toPack->bin->add(value);
	tree->runTourney();
}

void BinPackerFirst::printBins()
{
	tree->printNonEmptyLeaves();
}

/***********************/
BinPackerBest::BinPackerBest(int capacity) : BinPacker(capacity)
{
	tree = new BinarySearchTree(capacity);
}

void BinPackerBest::packValue(int value)
{
	tree->pack(value);
}

void BinPackerBest::printBins()
{
	tree->print();
}

