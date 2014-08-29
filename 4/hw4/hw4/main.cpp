#include <iostream>
#include "RatInMaze.h"
#include <string>
using namespace std;

void print_header (string h, int fromX,int fromY,int toX,int toY)  {
    cout << h << "from " << "(" << fromX << "," << fromY << ") to ("
         << toX << "," << toY << "):" << endl;
}

int main (){

        RatInMaze* rim = new RatInMaze();
	char maze[13][15]={
		'0','0','0','1','0','0','0','0','0','0','1','0','0','0','0',
		'0','0','0','1','0','0','1','0','0','0','0','0','0','0','0',
		'0','0','0','0','0','0','0','1','1','1','1','1','1','1','1',
		'0','0','0','1','1','1','0','0','1','0','0','1','0','0','0',
		'0','0','0','0','0','1','1','0','0','1','0','0','1','0','0',
		'1','1','0','0','0','1','1','0','0','1','0','0','0','0','0',
		'0','1','1','0','0','1','1','0','0','1','0','0','0','0','0',
		'0','0','1','0','0','1','1','0','0','1','0','0','0','0','0',
		'0','1','1','0','0','1','0','0','0','0','0','0','0','0','0',
		'0','0','1','0','0','0','1','1','1','1','1','1','1','1','1',
		'0','0','1','0','1','0','0','0','0','0','0','0','0','0','0',
		'0','0','1','0','1','0','0','0','1','0','0','0','0','0','0',
		'0','0','0','0','1','0','0','1','0','0','0','0','0','0','0' };

	rim->load(maze,13,15);
	print_header("Queue search ", -1,1,10,10);
	rim->print(rim->searchQueue(-1,1,10,10));

	rim->load(maze,13,15);
	print_header("Stack search ", 0,0,41,1);
	rim->print(rim->searchStack(0,0,41,1));

	int fromY = 0;
	int fromX = 7;
	int toY =  14;
	int toX =  6;

	rim->load(maze,13,15);
	print_header("Rat (stack) searching ",fromX,fromY,toX,toY);
	rim->print(rim->searchStack(fromX,fromY,toX,toY));

	rim->load(maze,13,15);
	print_header("Multiple rats searching ",fromX,fromY,toX,toY);
	rim->print(rim->searchQueue(fromX,fromY,toX,toY)); //SOMETHINGS UP

	rim->load(maze,13,15);
	print_header("Smart rat searching ",fromX,fromY,toX,toY);
	rim->print(rim->searchStackSmart(fromX,fromY,toX,toY));
	//system("Pause");
}



