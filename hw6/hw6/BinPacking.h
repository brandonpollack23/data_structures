//Brandon Pollack
//2375-4365
#ifndef BINPACKING
#define BINPACKING
#include "MaxWinnerTree.h"
#include "BinarySearchTree.h"
#include <deque>

class BinPacker
{
private:
	BinaryTree* tree;
	int capacity;
public:
	BinPacker(int capacity);

	virtual void printBins() = 0;

	virtual void packValue(int value) = 0;
};

class BinPackerFirst : public BinPacker
{
private:
	MaxWinnerTree* tree;
public:
	BinPackerFirst(int capacity);

	void printBins();

	void packValue(int value);
};

class BinPackerBest : public BinPacker
{
private:
	BinarySearchTree* tree;
public:
	BinPackerBest(int capacity);

	void printBins();

	void packValue(int value);
};
#endif