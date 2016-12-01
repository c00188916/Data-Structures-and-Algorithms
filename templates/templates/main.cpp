
#include <iostream>
#include <fstream>
#include <string>
#include <utility>  // for STL pair
using std::pair;

#include "Graph.h"

using namespace std;


typedef GraphArc<std::string, int> Arc;
typedef GraphNode<std::string, int> Node;

void visit( Node * node ) {
	cout << "Visiting: " << node->data() << endl;
}

int main(int argc, char *argv[]) {
	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)

	Graph< pair<string, int>, int > myGraph(6);

    Graph<std::string, int> graph( 25 );
	Graph<std::string, int> graphQ2(25);
	
	std::string nodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open ("nodes.txt");

	while ( myfile >> nodeLabel ) {
		graph.addNode(nodeLabel, i++);
	}

	myfile.close();
	myfile.open("Q2Arcs.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graph.addArc(from, to, weight);
	}
	myfile.close();
	myfile.open("mapArcs.txt");

	string fromString, toString;
	while (myfile >> fromString >> toString >> weight) {
		//graph.addArc(fromString, toString, weight);
	}

	myfile.close();

	// Now traverse the graph with a breadth-first search.	
	//graph.breadthFirst( graph.nodeIndex(0), visit );
	graph.adaptedBreadthFirst(graph.nodeIndex(0), visit, graph.nodeIndex(20));
	auto g = graph.nodeIndex(5);
	system("PAUSE");
	
}
