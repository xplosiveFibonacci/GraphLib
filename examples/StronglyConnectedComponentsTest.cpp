#include <iostream>
#include "Graph.h"

using namespace std;

string StronglyConnectedComponentsTest() {
	// A list of identifiers for the vertices
	vector<string> vs = { "a", "b", "c", "d", "e", "f", "g", "h" };

	// Create the graph with the previously created list
	Graph g(vs);

	g.addEdge("a", "b");

	g.addEdge("b", "e");
	g.addEdge("b", "f");
	g.addEdge("b", "c");

	g.addEdge("c", "d");
	g.addEdge("c", "g");

	g.addEdge("d", "c");
	g.addEdge("d", "h");

	g.addEdge("e", "a");
	g.addEdge("e", "f");

	g.addEdge("f", "g");

	g.addEdge("g", "f");
	g.addEdge("g", "h");

	g.addEdge("h", "h");

	string result = g.print() + "\n";

	vector<list<Vertex>> forest = g.stronglyConnectedComponents();

	vector<list<Vertex>>::iterator it;
	list<Vertex>::iterator set_it;

	int i = 1;
	for (it = forest.begin(); it != forest.end(); it++) {
		result += "\n SCC(" + to_string(i) + ") -> ";
		for (set_it = it->begin(); set_it != it->end(); set_it++) {
			result += set_it->id + " ";
		}
		result += "\n";
		i++;
	}

	return result;
}

int main() {

	cout << " -------- STRONGLY CONNECTED COMPONENTS -------- " << endl;
	cout << StronglyConnectedComponentsTest();
	
	system("pause");

	return 0;
}