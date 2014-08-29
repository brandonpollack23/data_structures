//Brandon Pollack
//2375-4365
#ifndef GRAPH
#define GRAPH

#include <vector>

class MapNode;

struct MapNodePointer //contains the distance and the pointer
{
	MapNode* mapNode;
	int distance;
};

class MapNode
{
private:
	bool visited;
	int currentDistanceTotal;

	std::vector<MapNodePointer> paths; //all the ways I can go 

	int nodeID;

	void changeDistance(int newDist)
	{
		currentDistanceTotal = newDist;
	}

public:
	MapNode(int ID, bool isOrigin = false)
	{
		nodeID = ID;
		if (!isOrigin)
		{
			currentDistanceTotal = INT_MAX; 
		}
		else
		{
			currentDistanceTotal = 0;
		}
		visited = false;
	}

	void setVisited()
	{
		visited = true;
	}

	void unVisit()
	{
		visited = false;
		currentDistanceTotal = INT_MAX;
	}

	bool const isVisited() const
	{
		return visited;
	}

	bool attemptToChangeDistance(int newDist)
	{
		if(currentDistanceTotal > newDist)
		{
			changeDistance(newDist);
			return true;
		}
		else return false;
	}

	void addRoute(MapNode* mapNode, int distance)
	{
		MapNodePointer addme;
		addme.mapNode = mapNode;
		addme.distance = distance;
		paths.push_back(addme);
	}

	std::vector<MapNodePointer> getPaths()
	{
		return paths;
	}

	const int getNodeID() const
	{
		return nodeID;
	}

	const int getCurrentDistance() const
	{
		return currentDistanceTotal;
	}
};

class ThisGraph
{
private:
	MapNode* one;
	std::vector<MapNode*> allNodes;
public:
	ThisGraph();

	std::vector<MapNode*> getAllNodes();

	MapNode* getOrigin();
};

#endif