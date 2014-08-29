//Brandon Pollack
//2375-4365
#ifndef BSTREE
#define BSTREE
#include "BinaryTree.h"

struct BSTNode : public Node
{
	Node* parent;

	BSTNode(Bin* bin) : Node(bin) {};
};

class BinarySearchTree : public BinaryTree
{
private:
	void eraseLeaf(BSTNode* node);
	void eraseDegreeOne(BSTNode* node);
public:
	BinarySearchTree(int binCap);

	void insert(Bin* bin);

	void pack(int value);

	void erase(BSTNode* node);

	BSTNode* find(Bin* bin);

	void print(Node* node, int& count);
	void print() {int count = 1; print(root,count);};
};
#endif