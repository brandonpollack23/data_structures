//Brandon Pollack
//2375 4365
#ifndef GRAPHSOLVER
#define GRAPHSOLVER
#include "Graph.h"
#include <string>

MapNode* findMinChild(std::vector<MapNodePointer>& children);
void reverseString(std::string rev);

class GraphSolver
{
private:
	ThisGraph* graph;
public:
	GraphSolver(ThisGraph* graph);

	std::string solveTo(MapNode* finalNode); //returns a string with fastest directions to finalNode
};
#endif