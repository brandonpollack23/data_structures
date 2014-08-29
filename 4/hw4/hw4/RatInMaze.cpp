//Brandon Pollack
//2375-4365
//1087
#include "RatInMaze.h"
#include <iostream>
#include <sstream>
#include <string>

//Y is EW
//X is SN

//TODO surround array with 1's and change boundary conditions for failure accordingly

RatInMaze::RatInMaze()
{
	ratPath = new myStack();
	spawnedRats =  new XYRat();

	/*for(int y = 0; y < 17; y++)
	{
		maze[0][y] = '1';
		mazeAnswer[0][y] = '1';
		maze[14][y] = '1';
		mazeAnswer[14][y] = '1';
	}
	for(int x = 0; x < 15; x++)
	{
		maze[x][0] = '1';
		mazeAnswer[x][0] = '1';
		maze[x][16] = '1';
		mazeAnswer[x][16] = '1';
	} //surround with borders

	for(int x = 0; x < 13; x++)
	{
		for(int y = 0; y < 15; y++)
		{
			maze[x][y] = 0;
			mazeAnswer[x][y] = 0;
		}
	}*/
}

RatInMaze::RatInMaze(char initMaze[][15])
{
	ratPath = new myStack();
	spawnedRats = new XYRat();
	traveled = 0;
	pathSteps = 0;

	for(int y = 0; y < 17; y++)
	{
		maze[0][y] = '1';
		mazeAnswer[0][y] = '1';
		maze[14][y] = '1';
		mazeAnswer[14][y] = '1';
	}
	for(int x = 0; x < 15; x++)
	{
		maze[x][0] = '1';
		mazeAnswer[x][0] = '1';
		maze[x][16] = '1';
		mazeAnswer[x][16] = '1';
	} //surround with borders

	for(int x = 1; x <= 13; x++)
	{
		for(int y = 1; y <= 15; y++)
		{
			maze[x][y] = initMaze[x][y];
			mazeAnswer[x][y] = initMaze[x][y];
		}
	}
}

bool RatInMaze::searchStack(int fromX, int fromY, int toX, int toY)
{
	mazeAnswer[fromX+1][fromY+1] = '2';
	if(maze[fromX+1][fromY+1] == '1') //somehow ended up or started in a wall
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Starting point is in a wall!" << endl << "Search canceled" << endl;
		return false;
	}
	if(fromX == toX && fromY == toY) //end condition
	{
		//mazeAnswer[fromX+1][fromY+1] = '2';
		return true;
	}
	if(fromX < 0 ||fromY < 0 || fromX > xLim-1 || fromY > yLim-1) //failure out of bounds
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Starting point is not inside the maze!" << endl << "Search canceled" << endl;
		return false;
	}
	else if(toX < 0 || toY < 0 || toX > xLim-1 || toY > yLim-1) //failure out of bounds
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Ending point is not inside the maze!" << endl << "search canceled" << endl;
		return false;
	}
	fromX++;
	fromY++;
	toX++;
	toY++; //inc all to put them in their right spot (border array)

	//EWSN

	//check east first
	if(mazeAnswer[fromX][fromY+1] == '0')
	{
		return checkEast(fromX,fromY,toX,toY);
	}

	//check south second

	else if(mazeAnswer[fromX+1][fromY] == '0')
	{
		return checkSouth(fromX,fromY,toX,toY);
	}

	//check west third

	else if(mazeAnswer[fromX][fromY-1] == '0') 
	{
		return checkWest(fromX,fromY,toX,toY);
	}

	//check north last

	else if(mazeAnswer[fromX-1][fromY] == '0')
	{
		return checkNorth(fromX,fromY,toX,toY);
	}

	//if no avenues are goable, then go pop
	else
	{
		mazeAnswer[fromX][fromY] = '3';
		//pathSteps--;
		int lastStep = 4;
		if(!(ratPath->empty()))
		{
			lastStep = ratPath->pop();
		}
		//need ifs for every stack direction to figure out which direction to go
		if(lastStep == east)
		{
			//dec y
			return searchStack(--fromX,--fromY-1,--toX,--toY);
		}
		else if(lastStep == west)
		{
			return searchStack(--fromX,fromY,--toX,--toY);
		}
		else if(lastStep == south)
		{
			return searchStack(--fromX-1,--fromY,--toX,--toY);
		}
		else if(lastStep == north)
		{
			return searchStack(fromX,--fromY,--toX,--toY);
		}
		else
		{
			pathSteps = 0;
			traveled = 0;
			return false; //there is no path if we have no steps to go back to
		}
	}
}

bool RatInMaze::searchQueue(int fromX, int fromY, int toX, int toY)
{
	traveled = 0;
	pathSteps = 0;
	if(fromX < 0 ||fromY < 0 || fromX > 12 || fromY > 14) //failure out of bounds
	{
		cout << "Starting point is not inside the maze!" << endl << "Search canceled" << endl;
		return false;
	}
	else if(toX < 0 || toY < 0 || toX > 12 || toY > 14) //failure out of bounds
	{
		cout << "Ending point is not inside the maze!" << endl << "search canceled" << endl;
		return false;
	}
	fromX++;
	fromY++;
	toX++;
	toY++; //inc all to put them in their right spot (border array)

	char generationChar = '3';

	spawnedRats->push(fromX, fromY); //push coordinates I've been
	mazeAnswer[fromX][fromY] = '2';
	while(!spawnedRats->x->empty() && ((fromX != toX) || (fromY != toY)))
	{
		fromX = spawnedRats->x->pop();
		fromY = spawnedRats->y->pop();
		//push every direction that can be pushed (if statements) into queue and notDone
		//reason for bug is that we push more onto the stack after we solve the problem, find a way to check if the problem is solved, and if so do not push

		if(mazeAnswer[fromX][fromY] == generationChar)
		{
			generationChar++;
		}

		
		//push east
		if(mazeAnswer[fromX][fromY+1] == '0') 
		{
			if(mazeAnswer[toX][toY] =='0')
			{
				mazeAnswer[fromX][fromY+1] = generationChar;
				spawnedRats->push(fromX,fromY+1);
			}
			traveled++;
		}

		//push south
		if(mazeAnswer[fromX+1][fromY] == '0') 
		{
			if(mazeAnswer[toX][toY] =='0')
			{
				mazeAnswer[fromX+1][fromY] = generationChar;
				spawnedRats->push(fromX+1,fromY);
			}
			traveled++;
		}

		//push west
		if(mazeAnswer[fromX][fromY-1] == '0') 
		{
			if(mazeAnswer[toX][toY] =='0')
			{
				mazeAnswer[fromX][fromY-1] = generationChar;
				spawnedRats->push(fromX,fromY-1);
			}
			traveled++;
		}

		//push north
		if(mazeAnswer[fromX-1][fromY] == '0') 
		{
			if(mazeAnswer[toX][toY] =='0')
			{
				mazeAnswer[fromX-1][fromY] = generationChar;
				spawnedRats->push(fromX-1,fromY);
			}
			traveled++;
		}
	}

	//fromX = spawnedRats->x->back();
	//fromY = spawnedRats->y->back();

	mazeAnswer[toX][toY] = '2';

	while(generationChar != '2')
	{
		pathSteps++;
		generationChar--;
		//follow path back 
		if(mazeAnswer[fromX][fromY-1] == generationChar)
		{
			mazeAnswer[fromX][--fromY] = '2';
		}
		else if(mazeAnswer[fromX][fromY+1] == generationChar)
		{
			mazeAnswer[fromX][++fromY] = '2';
		}
		else if(mazeAnswer[fromX-1][fromY] == generationChar)
		{
			mazeAnswer[--fromX][fromY] = '2';
		}
		else if(mazeAnswer[fromX+1][fromY] == generationChar)
		{
			mazeAnswer[++fromX][fromY] = '2';
		}
	}

	if(mazeAnswer[toX][toY] == '2')
	{
		traveled--;
		return true;
	}
	else
	{
		return false;
	}
}

bool RatInMaze::searchStackSmart(int fromX, int fromY, int toX, int toY)
{
	mazeAnswer[fromX+1][fromY+1] = '2';
	if(maze[fromX+1][fromY+1] == '1') //somehow ended up or started in a wall
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Starting point is in a wall!" << endl << "Search canceled" << endl;
		return false;
	}
	if(fromX == toX && fromY == toY) //end condition
	{
		mazeAnswer[fromX][fromY] = '2';
		return true;
	}
	if(fromX < 0 ||fromY < 0 || fromX > xLim-1 || fromY > yLim-1) //failure out of bounds
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Starting point is not inside the maze!" << endl << "Search canceled" << endl;
		return false;
	}
	else if(toX < 0 || toY < 0 || toX > xLim-1 || toY > yLim-1) //failure out of bounds
	{
		pathSteps = 0;
		traveled = 0;
		cout << "Ending point is not inside the maze!" << endl << "search canceled" << endl;
		return false;
	}
	fromX++;
	fromY++;
	toX++;
	toY++; //inc all to put them in their right spot (border array)

	determineOrder(fromX,fromY,toX,toY);

	for(int i = 0; i < 4; i++)
	{
		if(order[i] == east && mazeAnswer[fromX][fromY+1] == '0')
		{
			return checkEastSmart(fromX,fromY,toX,toY);
		}
		else if(order[i] == west && mazeAnswer[fromX][fromY-1] == '0')
		{
			return checkWestSmart(fromX,fromY,toX,toY);
		}
		else if(order[i] == south && mazeAnswer[fromX+1][fromY] =='0')
		{
			return checkSouthSmart(fromX,fromY,toX,toY);
		}
		else if(order[i] == north && mazeAnswer[fromX-1][fromY] =='0')
		{
			return checkNorthSmart(fromX,fromY,toX,toY);
		}
	}

	mazeAnswer[fromX][fromY] = '3';
	//pathSteps--;
	int lastStep = 4;
	if(!(ratPath->empty()))
	{
		lastStep = ratPath->pop();
	}
	//need ifs for every stack direction to figure out which direction to go
	if(lastStep == east)
	{
		//dec y
		return searchStackSmart(--fromX,--fromY-1,--toX,--toY);
	}
	else if(lastStep == west)
	{
		return searchStackSmart(--fromX,fromY,--toX,--toY);
	}
	else if(lastStep == south)
	{
		return searchStackSmart(--fromX-1,--fromY,--toX,--toY);
	}
	else if(lastStep == north)
	{
		return searchStackSmart(fromX,--fromY,--toX,--toY);
	}
	else
	{
		pathSteps = 0;
		traveled = 0;
		return false; //there is no path if we have no steps to go back to
	}
}

void RatInMaze::load(char initMaze[][15], int borderX,int borderY)
{
	xLim = borderX+2;
	yLim = borderY+2;
	for(int x = 0; x < xLim; x++)
	{
		maze[x][0] = '1';
		mazeAnswer[x][0] = '1';
		maze[x][yLim-1] = '1';
		mazeAnswer[x][yLim-1] = '1';
	}
	for(int y = 0; y < yLim; y++)
	{
		maze[0][y] = '1';
		mazeAnswer[0][y] = '1';
		maze[xLim-1][y] = '1';
		mazeAnswer[xLim-1][y] = '1';
	}

	for(int i = 1; i <= xLim-2; i++)
	{
		for(int j = 1; j <= yLim-2; j++)
		{
			maze[i][j] = initMaze[i-1][j-1];
			mazeAnswer[i][j] = initMaze[i-1][j-1];
		}
	} //init the maze
}

void RatInMaze::print(bool wasSuccessful)
{
	if(wasSuccessful)
	{
		cout << answerToString();
	}
	traveled = 0;
	pathSteps = 0;
}

string RatInMaze::answerToString()
{
	pathSteps = 0;
	stringstream answer;
	for(int i = 1; i < xLim-1; i++)
	{
		for(int j = 1; j < yLim-1; j++)
		{
			if(mazeAnswer[i][j] == '1' || mazeAnswer[i][j] == '2')
			{
				answer << mazeAnswer[i][j];
			}
			else
			{
				answer << '0';
			}
		}
		answer << endl;
	}

	findPathSteps();

	answer << "I've traveled through " << traveled << " square(s). The path contains " << pathSteps << " square(s)" << endl;
	return answer.str();
}

bool RatInMaze::checkNorth(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(north);
	//mazeAnswer[fromX-1][fromY] = '2';
	return searchStack(--fromX-1,--fromY,--toX,--toY);
}

bool RatInMaze::checkSouth(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(south);
	//mazeAnswer[fromX+1][fromY] = '2';
	return searchStack(fromX,--fromY,--toX,--toY);
}

bool RatInMaze::checkEast(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(east);
	//mazeAnswer[fromX][fromY+1] = '2';
	return searchStack(--fromX,fromY,--toX,--toY);
}

bool RatInMaze::checkWest(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(west);
	//mazeAnswer[fromX][fromY-1] = '2';
	return searchStack(--fromX,--fromY-1,--toX,--toY);
}

bool RatInMaze::checkNorthSmart(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(north);
	//mazeAnswer[fromX-1][fromY] = '2';
	return searchStackSmart(--fromX-1,--fromY,--toX,--toY);
}

bool RatInMaze::checkSouthSmart(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(south);
	//mazeAnswer[fromX+1][fromY] = '2';
	return searchStackSmart(fromX,--fromY,--toX,--toY);
}

bool RatInMaze::checkEastSmart(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(east);
	//mazeAnswer[fromX][fromY+1] = '2';
	return searchStackSmart(--fromX,fromY,--toX,--toY);
}

bool RatInMaze::checkWestSmart(int& fromX, int& fromY, int& toX,int& toY)
{
	traveled++;
	//pathSteps++;
	ratPath->push(west);
	//mazeAnswer[fromX][fromY-1] = '2';
	return searchStackSmart(--fromX,--fromY-1,--toX,--toY);
}

void RatInMaze::determineOrder(int& fromX, int& fromY, int& toX,int& toY)
{
	if(fromX <= toX)
	{
		order[0] = south;
		order[2] = north;
	}
	else
	{
		order[0] = north;
		order[2] = south;
	}

	if(fromY <= toY)
	{
		order[1] = east;
		order[3] = west;
	}
	else
	{
		order[1] = west;
		order[3] = east;
	}
}

void RatInMaze::findPathSteps()
{
	for(int x = 0; x < xLim-1; x++)
	{
		for(int y = 0; y < yLim-1; y++)
		{
			if(mazeAnswer[x][y] == '2')
			{
				pathSteps++;
			}
		}
	}
}