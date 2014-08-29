//Brandon Pollack
//23754365
#ifndef BINARY_TREE
#define BINARY_TREE

#include "Arraylist.h"

using namespace std;

class BinaryTree : public arrayList
{
public:
	BinaryTree() : arrayList() {};

	void preOrder(int n = 0) const;
	void inOrder(int n = 0) const;
	void postOrder(int n = 0) const;
	void place_bottom(int elem);
	//const int get_height() const;
	const int get_number_of_nodes() const;
	//BinaryTree clone() const;
	//const bool is_clone(const BinaryTree otherTree) const
protected:
	int inline nleft(int k) const;
	int inline nright(int k) const;
	int inline nparent(int k) const 
	{		
		if(k >= 0)
		{
			if(k%2 == 0) //if even
			{
				return (k-2)/2;
			}
			else //odd
			{
				return (k-1)/2;
			}
		}
		else return 0;
	}
};

#endif