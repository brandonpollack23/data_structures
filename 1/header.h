/* 
Brandon Pollack
2375-5365
Discussion Section: 1087 
*/
//header file for assignment 1

#include <iostream>

#ifndef FACTORIAL
#define FACTORIAL
int factorial(int fact)
{
	if (fact == 0 || fact == 1)
	{
		return 1;
	}
	else
	{
		return fact*factorial(fact-1);
	}
}

void print_factorial();
#endif
