//Brandon Pollack
//2375-4365
#include "Graph.h"

ThisGraph::ThisGraph()
{
	one = new MapNode(0,true);
	MapNode* two = new MapNode(1);
	MapNode* three = new MapNode(2);
	MapNode* four = new MapNode(3);
	MapNode* five = new MapNode(4);
	MapNode* six = new MapNode(5);

	one->addRoute(two,10);
	one->addRoute(five,100);
	one->addRoute(four,30);

	two->addRoute(three,50);

	three->addRoute(six,5);
	three->addRoute(five,10);

	four->addRoute(three,20);
	four->addRoute(six,15);

	five->addRoute(four,60);

	allNodes.push_back(one);
	allNodes.push_back(two);
	allNodes.push_back(three);
	allNodes.push_back(four);
	allNodes.push_back(five);
	allNodes.push_back(six);
}

std::vector<MapNode*> ThisGraph::getAllNodes()
{
	return allNodes;
}

MapNode* ThisGraph::getOrigin()
{
	return one;
}