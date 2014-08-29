//Brandon Pollack
//2375-4365
#include "BinPacking.h"

using namespace std;

int main()
{
	int input;
	char menu;
	BinPacker* binpacker;

	for(;;)
	{
		cout << "Please choose the algorithm for test: 1. Firstfit; 2. Bestfit; 3. Quit?" << endl;
		cin >> menu;

		if(menu > '3' || menu < '1')
		{
			cout << "Option unavailable\n";
			continue;
		}

		if(menu == '3')
		{
			cout << "quiting...";
			break;
		}
		
		cout << "Enter number of objects and bin capacity for ";
		
		if(menu ==  '1') //first fit selected
		{
			cout << "First Fit\n";
		}
		else
		{
			cout << "Best Fit\n";
		}

		cin >> input;
		int numberOfObjects = input;

		cin >> input;
		int binCap = input;

		if(menu == '1')
		{
			binpacker = new BinPackerFirst(binCap);
		}
		else
		{
			binpacker = new BinPackerBest(binCap);
		}

		for(int i = 0; i < numberOfObjects; ++i)
		{
			cout << "Enter space requirment of object " << i+1 << endl;
			cin >> input;
			binpacker->packValue(input);
		}

		binpacker->printBins();
		cout << endl;
	}

}