/* 
Brandon Pollack
2375-5365
Discussion Section: 1087 
*/
//the main file which includes the definition of print_factiorial()

#include <iostream>
#include "header.h"

using namespace std;

int main(void)
{
	print_factorial();
	cout << "You have left the game!" << endl;
	return 0;
}

void print_factorial() {
	char x = 0;
	do
	{
		cout << "Enter a number(or enter 'q' to quit): ";
		cin >> x;
		
		if (x != 'q')
		{
			int y = (int)x-'0';	
			cout << x << "! = ";
			cout << factorial(y);
			cout << endl;
		}
	}while(x != 'q');
}