#include <iostream>
#include "Graph.h"

using namespace std;

string topologicalSortTest() {

	// A list of identifiers for the vertices
	vector<string> vs = { "undershorts", "pants", "socks", "belt", "shirt",
		"tie", "jacket", "shoes", "watch" };

	// Create the graph with the previously created list
	Graph g(vs);

	// What is a graph if only has vertices? Lets make some connections
	g.addEdge("undershorts", "pants");
	g.addEdge("undershorts", "shoes");

	g.addEdge("pants", "belt");
	g.addEdge("pants", "shoes");

	g.addEdge("belt", "jacket");

	g.addEdge("shirt", "belt");
	g.addEdge("shirt", "tie");

	g.addEdge("tie", "jacket");

	g.addEdge("socks", "shoes");

	string result = g.print() + "\n";

	/*
	Why dont to use some functions? Lets see if the graph has
	cycles. If not, its a great chance to make a topological sort!
	*/
	
	if (!g.isCiclyc()) {
		list<Vertex> vlist = g.topologicalSort();
		for (list<Vertex>::iterator it = vlist.begin(); it != vlist.end(); it++)
			result += it->id + " -- ";
	}
	else
		result = "Has cycles. Couldnt do a topological sort\n";

	return result;
}

int maain() {

	cout << " ---------- TOPOLOGICAL SORT ---------- " << endl;
	cout << topologicalSortTest();

	system("pause");

	return 0;
}
