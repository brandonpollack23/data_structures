//Brandon Pollack
//2375-4365
#include "BinarySearchTree.h"
#include <deque>

BinarySearchTree::BinarySearchTree(int binCap)
{
	this->binCap = binCap;
	root = new Node(binCap);
}

void BinarySearchTree::insert(Bin* bin)
{
	if(root == NULL) {root = new Node(bin); return;}
	Node* current = root;
	while(true)
	{
		if(current->bin->spaceRemaining() > bin->spaceRemaining())
		{
			if(current->left != NULL)
			{
				current = current->left;
				continue;
			}
			else
			{
				BSTNode* newNode = new BSTNode(bin);
				newNode->parent = current;
				current->left = newNode;
				break;
			}
		}
		else if(current->bin->spaceRemaining() < bin->spaceRemaining())
		{
			if(current->right != NULL)
			{
				current = current->right;
				continue;
			}
			else
			{
				BSTNode* newNode = new BSTNode(bin);
				newNode->parent = current;
				current->right = newNode;
				break;
			}
		}
		else //can go left or right
		{
			if(current->left == NULL)
			{
				BSTNode* newNode = new BSTNode(bin);
				newNode->parent = current;
				current->left = newNode;
				break;
			}
			else if(current->right == NULL)
			{
				BSTNode* newNode = new BSTNode(bin);
				newNode->parent = current;
				current->right = newNode;
				break;
			}
			else
			{
				current = current->left;
				continue;
			}
		}
	}
}

BSTNode* BinarySearchTree::find(Bin* bin)
{
	std::deque<Node*> nodes;
	BSTNode* current = (BSTNode*)root;
	while(!nodes.empty())
	{
		if(current->bin == bin)
		{
			return current;
		}
		if(current->left != NULL)
		{
			nodes.push_back(current->left);
		}
		if(current->right != NULL)
		{
			nodes.push_back(current->right);
		}
	}
	return NULL; //DNE
}

void BinarySearchTree::eraseLeaf(BSTNode* node)
{
	if(node == root){ delete root; root = NULL; return;}
	Node* parent = node->parent;
	if(parent->left == node)
	{
		parent->left = NULL;
	}
	else
	{
		parent->right = NULL;
	}
	delete node; //have to be sure to save the bin inside!
}

void BinarySearchTree::eraseDegreeOne(BSTNode* node)
{
	if(node == root)
	{
		if(node->left != NULL)
		{
			root = node->left;
		}
		else
		{
			root = node->right;
		}
	}
	else
	{
		Node* parent = node->parent;

		if(parent->right == node)
		{
			if(node->right != NULL)
			{
				parent->right = node->right;
			}
			else
			{
				parent->right = node->left;
			}
		}
		else
		{
			if(node->right != NULL)
			{
				parent->left = node->right;
			}
			else
			{
				parent->left = node->left;
			}
		} 
	}
	delete node;
}

void BinarySearchTree::erase(BSTNode* node)
{
	if(node->left == NULL && node->right == NULL) //leaf
	{
		eraseLeaf(node);	
	}
	else if(node->left != NULL && node->right != NULL) //degree 2
	{
		Node* current = node->left;

		while(current->right != NULL)
		{
			current = current->right;
		}

		node->bin = current->bin;

		if(node->left != NULL || node->right != NULL)
		{
			eraseDegreeOne(node);
		}
		else
		{
			eraseLeaf(node);
		}
	}
	else //degree 1
	{
		eraseDegreeOne(node);
	}
}

void BinarySearchTree::pack(int value)
{
	Node* current = root;
	std::deque<Node*> previous;
	Node* previousFit = NULL;
	while(true)
	{
		if(current->bin->willFit(value)) //if we fit into this node
		{
			if(current->left != NULL) //there are nodes to the left, and therefore perhaps a better fitting node
			{
				previousFit = current;
				previous.push_back(current);
				current = current->left;
				continue;
			}
			else //there are no nodes to the left, and therefore this node is the best fit
			{
				Bin* insertMe = current->bin; //save the bin
				erase((BSTNode*)current); //get rid of the old node
				insertMe->add(value); //add the value
				insert(insertMe); //reinsert in sorted order
				break;
			}
		}
		else //does not fit in current node
		{
			if(current->right != NULL)
			{
				previous.push_back(current);
				current = current->right;
				continue;
			}
			else//we have visited a node where we fit in the past or no nodes ever fit
			{
				if(previousFit == NULL) //no nodes ever fit we need to insert a brand new Bin
				{
					insert(new Bin(binCap,value));
					break;
				}

				else 
				{
					for(current = previous.back();current != previousFit; previous.pop_back()) //at the end here current will be the last thing that fit before we traversed this tree
					{
						current = previous.back();
					}
					
					Bin* insertMe = current->bin;
					erase((BSTNode*)current);
					insertMe->add(value);
					insert(insertMe);
					break; 					
				}
				
			}
		}
	}
}

void BinarySearchTree::print(Node* node, int& count)
{
	//Inorder print bins that are not 10 (just in case nothing was packed into initial bin)
	int thisCount = count;
	if(node->bin->spaceRemaining() < binCap)
	{
		std::cout << "Bin #" << thisCount << ' ';
		node->bin->print();
		std::cout << std::endl;
	}
	if(node->left != NULL) print(node->left, ++count);
	if(node->right != NULL) print(node->right, ++count);
}