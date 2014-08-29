//Brandon Pollack
//2375-4365
#include "BinaryTree.h"

void BinaryTree::preOrder(int n) const
{
	if(n > listSize-1) return;
	else
	{
		cout << element[n] << ' ';
		preOrder(nleft(n));
		preOrder(nright(n));
	}
}

void BinaryTree::inOrder(int n) const
{
	if(n > listSize-1) return;
	else
	{
		inOrder(nleft(n));
		cout << element[n] << ' ';
		inOrder(nright(n));
	}
}

void BinaryTree::postOrder(int n) const
{
	if(n > listSize-1) return;
	else
	{
		postOrder(nleft(n));
		postOrder(nright(n));
		cout << element[n] << ' ';
	}
}

void BinaryTree::place_bottom(int elem)
{
	insert(listSize,elem);
}

const int BinaryTree::get_number_of_nodes() const
{
	return listSize;
}

int inline BinaryTree::nleft(int k) const
{
	return 2*k+1;
}

int inline BinaryTree::nright(int k) const
{
	return 2*k+2;
}

/*int inline BinaryTree::nparent(int k) const
{
	if(k >= 0)
	{
		if(k%2 == 0) //if even
		{
			return (k-2)/2;
		}
		else //odd
		{
			return (k-1)/1;
		}
	}
	else return 0;
}*/