//Brandon Pollack
//2375 4365
#include "GraphSolver.h"
#include <sstream>

GraphSolver::GraphSolver(ThisGraph* graph)
{
	this->graph = graph;
}

std::string GraphSolver::solveTo(MapNode* finalNode)
{
	std::vector<MapNode*> nodes = graph->getAllNodes();
	MapNode* origin = graph->getOrigin();
	MapNode* current;
	MapNode** path = new MapNode*[nodes.size()];

	for(int i = 1; i < nodes.size(); i++)
	{
		nodes[i]->unVisit();
	}

	int totalDistance;

	std::vector<MapNodePointer> children;

	for(current = origin; current != finalNode;)
	{
		//add all children of current to children vector
		std::vector<MapNodePointer> currentChildren = current->getPaths();
		for(int i = 0; i < currentChildren.size(); ++i)
		{
			children.push_back(currentChildren[i]);
		}

		for(std::vector<MapNodePointer>::iterator it = children.begin(); it != children.end(); ++it)
		{
			if(!it->mapNode->isVisited() && it->mapNode->attemptToChangeDistance(it->distance + current->getCurrentDistance()))
			{
				path[it->mapNode->getNodeID()] = current; //keep track of where you went with the array path (set values with if statement of change distance)
			}
		} 

		current->setVisited();
		current = findMinChild(children); //continue with least distant of the children of current, also erase from children
	}

	totalDistance = current->getCurrentDistance();
	
	//construct string based on array and return that bad boy
	std::stringstream answer;

	answer << totalDistance << ": ";

	for(current = finalNode; current != origin; current = path[current->getNodeID()])
	{
		answer << current->getNodeID()+1 << "<--";
	}
	answer << origin->getNodeID()+1;

	return answer.str();
}

MapNode* findMinChild(std::vector<MapNodePointer>& children)
{
	MapNode* answer = children[0].mapNode;
	int eraseIndex = 0;
	for(int i = 1; i < children.size(); ++i)
	{
		if(!children[i].mapNode->isVisited() && children[i].mapNode->getCurrentDistance() < answer->getCurrentDistance())
		{
			answer = children[i].mapNode;
			eraseIndex = i;
		}
	}

	children.erase(children.begin() + eraseIndex);

	return answer;
}

