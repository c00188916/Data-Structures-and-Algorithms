
#include <iostream>
#include <fstream>
#include <string>
#include <utility>  // for STL pair
using std::pair;

#include "Graph.h"

using namespace std;


typedef GraphArc<std::string, int> Arc;
typedef GraphNode<pair<std::string, int>, int> Node;

void visit( Node * node ) {
	cout << "Visiting: " << node->data().first << endl;
	cout << "`Path cost: " << node->data().second << endl;
}

int main(int argc, char *argv[]) {
	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)

	Graph< pair<string, int>, int > myGraph(6);

   // Graph<std::string, int> graph( 25 );
	//Graph<std::string, int> graphQ2(25);
	
	std::string nodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open ("cityNames.txt");

	std::pair<string, int> data;
	while ( myfile >> data.first ) {
		myGraph.addNode(data, i++);
	}

	myfile.close();
	myfile.open("map.txt");

	int from, to, weight;
	std::string fromS;
	std::string toS;
	while ( myfile >> fromS >> toS >> weight ) {
		from = fromS.at(0) - 'A';
		to = toS.at(0) - 'A';
		myGraph.addArc(from, to, weight);
	}
	myfile.close();
	

	// Now traverse the graph with a breadth-first search.	
	//graph.breadthFirst( graph.nodeIndex(0), visit );
	//graph.adaptedBreadthFirst(graph.nodeIndex(0), visit, graph.nodeIndex(20));
	//auto g = graph.nodeIndex(5);
	system("PAUSE");
	
}
