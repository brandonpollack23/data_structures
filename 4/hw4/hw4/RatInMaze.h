//Brandon Pollack
//2375-4365
//1087
#ifndef RATINMAZE
#define RATINMAZE
#include <string>
#include "stack.h"
#include "queue.h"
#include <string>

#define east 0
#define west 1
#define south 2
#define north 3

using namespace std;

struct XYRat
{
	myQueue* x;
	myQueue* y;

	XYRat()
	{
		x = new myQueue();
		y = new myQueue();
	}
	
	void push(int fromX, int fromY)
	{
		x->push(fromX);
		y->push(fromY);
	}
};

class RatInMaze
{
private:
	char maze [15][17]; //this is the initial mazy copied with 1's all around
	char mazeAnswer[15][17]; //this is the maze after the most recent solution
	int xLim,yLim;
	myStack* ratPath;
	XYRat* spawnedRats;
	int traveled;
	int pathSteps;

	bool checkNorth(int& fromX, int& fromY, int& toX,int& toY);
	bool checkSouth(int& fromX, int& fromY, int& toX,int& toY);
	bool checkEast(int& fromX, int& fromY, int& toX,int& toY);
	bool checkWest(int& fromX, int& fromY, int& toX,int& toY);

	bool checkNorthSmart(int& fromX, int& fromY, int& toX,int& toY);
	bool checkSouthSmart(int& fromX, int& fromY, int& toX,int& toY);
	bool checkEastSmart(int& fromX, int& fromY, int& toX,int& toY);
	bool checkWestSmart(int& fromX, int& fromY, int& toX,int& toY);

	void findPathSteps();

	void determineOrder(int& fromX,int& fromY,int& toX,int& toY);
	int order[4];
public:
	RatInMaze(); //default constructor, no walls maze
	RatInMaze(char initMaze[][15]); //constructor for a maze
	bool searchStack(int fromX, int fromY, int toX, int toY); //depth first search
	bool searchQueue(int fromX, int fromY, int toX, int toY); //breadth first search
	bool searchStackSmart(int fromX, int fromY, int toX, int toY); //check directions
	void load(char initMaze[][15], int lengthX, int lengthY);
	void print(bool wasSuccessful);
	string answerToString(); //returns string of answer, for simplifies printing
};
#endif