//Brandon Pollack
//2375-4365
#include "MaxWinnerTree.h"
#include <deque>
#include <iostream>

MaxWinnerTree::MaxWinnerTree(int binCap, int height) : BinaryTree() //CONSTRUCTION NOT WORKING CORRECTLY, need to set root, duh
{
	this->height = height;
	this->binCap = binCap;
	std::deque<Node*> nodes;

	nodes.push_back(new Node(binCap)); //first node is only one with a bin amount

	for(int i = 1; i < pow(2,height-1); ++i)
	{
		nodes.push_back(new Node());
	}
	if (nodes.size() > 1)
	{
		while(nodes.size() > 1) //need to make root's left and right nodes point to the last two who were added
		{
			Node* node = new Node();
			node->left = nodes.front();
			nodes.pop_front();
			node->right = nodes.front();
			nodes.pop_front();
			nodes.push_back(node);
		} 
	}

	root = nodes.front();

	runTourney();
}

Node* MaxWinnerTree::firstFittingNode(int value)
{
	//returns the node that the value fits in first
	//checks current node, if it cant fit adds contender
	//then if it does fit checks left, if it doesnt fit check right
	//keep iterating down until it wont fit any more

	//so iterate down with left priority essentially
	Node* current = root;
	std::deque<Node*> nodes;
	nodes.push_back(current);

	if(!current->bin->willFit(value))
	{
		//IF IT WILL NOT FIT MAKE A NEW BIN FOR IT TO GO IN
		addContender();
		runTourney(); //and then get the new node values
	}

	while(true)
	{
		current = nodes.front();
		nodes.pop_front();

		Node* left = current->left;
		Node* right = current->right;
		if(left == NULL && right == NULL)
		{
			return current;
		}

		if(left->bin->willFit(value))
		{
			nodes.push_back(left);
		}
		if(right->bin->willFit(value))
		{
			nodes.push_back(right);
		}
	}
}

void MaxWinnerTree::addContender() //TODO case where there arent enough children
{
	std::deque<Node*> nodes;

	nodes.push_back(root);
	while(true)
	{
		Node* current = nodes.front();
		if(current->left == NULL && current->right == NULL && current->bin->capacity == 0)
		{
			current->bin->capacity = binCap;
			break;
		}
		if(nodes.empty())
		{
			addLayer();
		}
		nodes.pop_front();
		if(current->left != NULL)
		{
			nodes.push_back(current->left);
		}
		if(current->right != NULL)
		{
			nodes.push_back(current->right);
		}
	}
}

void MaxWinnerTree::addLayer(Node* node)
{
	if(node->left == NULL && node->right == NULL)
	{
		node->left = new Node();
		node->right = new Node();
		return;
	}
	addLayer(node->left);
	addLayer(node->right);
}

int MaxWinnerTree::nextHeight()
{
	return ++height;
}

Bin* MaxWinnerTree::runTourney(Node* node)
{
	if(node->left == NULL && node->right == NULL)
	{
		return node->bin;
	}

	if(node->left != NULL)
	{
		node->left->bin = runTourney(node->left);
	}
	if(node->right != NULL)
	{
		node->right->bin = runTourney(node->right);
	}

	if(node->left->bin->spaceRemaining() > node->right->bin->spaceRemaining())
	{
		return node->left->bin;
	}
	else
	{
		return node->right->bin;
	}
}

void MaxWinnerTree::printNonEmptyLeaves()
{
	std::deque<Node*> nodes;
	std::deque<Node*> prints;
	nodes.push_back(root);
	while(!nodes.empty())
	{
		Node* current = nodes.front();
		if(binCap && current->left == NULL && current->right == NULL)
		{
			if(current->bin->capacity > 0) prints.push_back(current);
			else break;
		}
		if(current->left != NULL)
		{
			nodes.push_back(current->left);
		}
		if(current->right != NULL)
		{
			nodes.push_back(current->right);
		}
		nodes.pop_front();
	}
	int num = 1;
	for(std::deque<Node*>::iterator it = prints.begin(); it != prints.end(); ++it)
	{
		std::cout << "Bin #" << num++ << std::endl;
		Bin* bin = (*it)->bin;
		bin->print(); 
		std::cout << std::endl;
	}
}