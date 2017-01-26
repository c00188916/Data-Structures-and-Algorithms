
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "Graph.h"

using namespace std;
using std::pair;


typedef GraphArc<std::pair<std::string, int>, int> Arc;
typedef GraphNode<std::pair<std::string, int>, int> Node;

typedef GraphNode<std::pair<std::string, int>, int> UCSNode;

void visit(Node * node) {

	cout << "Visiting: " << node->data().first << endl;
}

void visitUCS(UCSNode * node)
{

	cout << "Visiting: " << node->data().first << endl;
	cout << "Path cost: " << node->data().second << endl;

}

int main(int argc, char *argv[]) {


	///////////////////////////////////////////////////////////////////////////////

	//Graph<std::string, int> graph(13);

	//std::string nodeName;
	//int i = 0;
	//ifstream nodeFile;
	//nodeFile.open("myNodes.txt");

	//while (nodeFile >> nodeName)
	//{
	//	graph.addNode(nodeName, i++);
	//}

	//nodeFile.close();
	//nodeFile.open("myArcs.txt");

	//int from, to, weight;
	//while (nodeFile >> from >> to >> weight)
	//{
	//	graph.addArc(from, to, weight);
	//}
	//nodeFile.close();

	//// Now traverse the graph with a breadth-first search.	
	//graph.breadthFirst(graph.nodeIndex(0), graph.nodeIndex(12), visit);

	////////////////////////////////////////////////////////////////////////////


	/*Graph<std::pair<std::string, int>, int>graph2(25);
	std::pair<std::string, int> nodeData;
	std::string nodeName2;
	int x = 0;
	ifstream arcsFile;
	arcsFile.open("nodes.txt");

	while (arcsFile >> nodeData.first)
	{
		graph2.addNode(nodeData, x++);
	}

	arcsFile.close();
	arcsFile.open("arcs.txt");

	int q2From, q2To, qWeight;

	while (arcsFile >> q2From >> q2To >> qWeight)
	{
		graph2.addArc(q2From, q2To, qWeight);
	}

	arcsFile.close();

	std::vector<Node *> path;
	graph2.ucs(graph2.nodeIndex(0), graph2.nodeIndex(23), visit, path);*/

	/////////////////////////////////////////////////////////////////////////////
	////////					Lab 4							/////////////////
	/////////////////////////////////////////////////////////////////////////////

	Graph<pair<string, int>, int > dorGraph(6);
	std::string nodeName3;
	int j = 0;
	ifstream ucsFile;
	ucsFile.open("ucsnodes.txt");


	while (ucsFile >> nodeName3)
	{
		dorGraph.addNode(std::pair< string, int>(nodeName3,0), j++);
	}

	ucsFile.close();
	ucsFile.open("map.txt");

	int ucsFrom = 0, ucsTo = 0, ucsWeight = 0;
	std::string ucsFromCity;
	std::string ucsToCity;

	while (ucsFile >> ucsFromCity >> ucsToCity >> ucsWeight)	
	{
		ucsFrom = ucsFromCity.at(0) - 'A';
		ucsTo = ucsToCity.at(0) - 'A';
		dorGraph.addArc(ucsFrom, ucsTo, ucsWeight);
	}

	ucsFile.close();
	std::vector<Node *>& path();
	dorGraph.ucs(dorGraph.nodeIndex(0), dorGraph.nodeIndex(4), visitUCS);
	Node * destination = dorGraph.nodeIndex(5);

	std::string output;
	while (destination != nullptr)
	{
		output = std::to_string(destination->data().second) + output;
		output = destination->data().first + " " + output;
		output = "\n" + output;

		/*std::cout << destination->data().first << std::endl;
		std::cout << destination->data().second << std::endl;*/
		destination = destination->previous();
	}
	std::cout << output;
	std::cout << std::endl;
	system("PAUSE");

}
