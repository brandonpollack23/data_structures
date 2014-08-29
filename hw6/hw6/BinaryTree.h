//Brandon Pollack
//2375-4365
#ifndef BINARYTREE
#define BINARYTREE
#include <vector>
#include <iostream>

struct Bin
{
	int capacity;
	int currentValue;

	std::vector<int> values;

	Bin(int binCap, int initVal = 0)
	{
		capacity = binCap;
		currentValue = 0;
		values.clear();
		add(initVal);
	}

	Bin() : capacity(0), currentValue(0){};

	const int spaceRemaining()
	{
		return capacity - currentValue;
	}

	bool willFit(int newVal)
	{
		return capacity >= (newVal + currentValue);
	}

	void add(int value)
	{
		if(value > 0)
		{
			values.push_back(value);
			currentValue += value;
		}
	}

	void print()
	{
		std:: cout << "Bin has these elements: \n";
		for(std::vector<int>::iterator it = values.begin(); it != values.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
	}
};

struct Node
{
	Bin* bin;
	Node* left;
	Node* right;

	Node(int binCap)
	{
		bin = new Bin(binCap);
		left = NULL;
		right = NULL;
	}

	Node(Bin* bin)
	{
		this->bin = bin;
		left = NULL;
		right = NULL;
	}

	Node()
	{
		bin = new Bin();
		left = NULL;
		right = NULL;
	}
};

class BinaryTree
{
protected:
	Node* root;
	int binCap;
public:
	BinaryTree();
};
#endif