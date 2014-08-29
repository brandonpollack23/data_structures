/*Brandon Pollack
Section 1087
2375-4365
Assignment 2
*/
#include <iostream>
#include "ArrayLinearList.h"

using namespace std;

int main()
{
	ArrayLinearList<int> *list; //create a pointer to my list in scope
	try
	{
	list = new ArrayLinearList<int>(); //instantiate one object and allocate memory
	}
	catch(exception& e) 
	{
		cout << e.what();
		return 0;
	}
	for(int i = 0; i < 10; i++)
	{
		(*list)[i] = (i+1); //make it from 1 to 10
	}

	//test begin
	char menu;
	int input, index;

	cout << "welcome to assignment 2!\n";

	do
	{
		cout << "Please enter  your command(I, D, P, E, S, M, Q):";
		cin >> menu;
		switch (tolower(menu))
		{
		case 'i':
			cin >> input >> index; //input indexing from 1
			list->insertElement(input,index-1);
			break;
		case 'd':
			cin >> index; //input indexing from 1
			list->deleteElement(index-1);
			break;
		case 'p':
			list->toString();
			break;
		case 's':
			list->printSize();
			break;
		case 'm':
			list->printMax();
			list->printMin();
			break;
		case 'e':
			cin >> index;
			//list.printElement(index); //replaced with operator override
			list->printElement(index-1);
			break;
		case 'q':
			menu = 'q';
			break;
		default:
			cout << "That is not an option\n";
		}
	}while(menu != 'q');
	cout << "The program is going to quit!";
}