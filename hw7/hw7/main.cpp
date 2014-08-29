//Brandon Pollack
//2375-4365
#include <iostream>
#include "GraphSolver.h"

using namespace std;

int main()
{
	ThisGraph graph;
	GraphSolver solver = GraphSolver(&graph);

	vector<MapNode*> nodes = graph.getAllNodes();

	cout << "All paths are displayed in reverse order" << endl;

	cout << solver.solveTo(nodes[0]) << endl;

	cout << solver.solveTo(nodes[1]) << endl;
	cout << solver.solveTo(nodes[2]) << endl;
	cout << solver.solveTo(nodes[3]) << endl;
	cout << solver.solveTo(nodes[4]) << endl;
	cout << solver.solveTo(nodes[5]) << endl;
}