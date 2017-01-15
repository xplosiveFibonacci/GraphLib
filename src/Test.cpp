/*
@file Test.h
@brief defines a depth first search over a graph.
@date 15/01/2017
@author David Alba

A test program of the GraphLib. It contains a test function that operates as follow: Given a 
graph, if it has cycles, the strongly connected components of the graph are calculated. Otherwise,
the topological sort

This program collects performance data that is encapsulated on a .dat file. For analisys, use the .plt file
that is also generated

NOTE: Both (.dat) & (.plt) files are supported by GNU-Plot
*/


#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <fstream>

#include "Graph.h"

using namespace std;

#define INIT_GRAPH_SIZE 5
#define INIT_EDGES_NUMBER 5

void addEdgeTest(Graph& g) {
	int a, b;
	int n = g.size();
	do {
		a = rand() % n;
		b = rand() % n;
	} while (g.existEdge(a, b));
	g.addEdge(a, b);
}

void store(ofstream& f, int size, clock_t time) {
	double msecs = ((double)(time) / CLOCKS_PER_SEC) * 1000;
	f << size;
	f << " ";
	f << msecs << endl;
}

void test(Graph& g, int size, ofstream& f1, ofstream& f2) {
	clock_t t;
	bool acyclyc;

	t = clock();
	acyclyc = !g.isCiclyc();
	t = clock() - t;
	store(f1, size, t);

	if (acyclyc) {
		// This method just recover the data extracted from isAcyclic. That's why
		// the time for analisys is calculated above
		g.topologicalSort();
	}

	else {
		t = clock();
		g.stronglyConnectedComponents();
		t = clock() - t;
		store(f2, size, t);
	}
}


int main() {

	Graph g;
	ofstream file_ts("Topological Sort.dat");
	ofstream file_scc("Strong Connected Components.dat");

	for (int i = 0; i < INIT_GRAPH_SIZE; i++)
		g.addVertex(to_string(i));

	for (int i = 0; i < INIT_EDGES_NUMBER; i++)
		addEdgeTest(g);

	int limit_size;

	cout << "|V| -> ";
	cin >> limit_size;

	int i = INIT_GRAPH_SIZE;

	// For principal
	for (i; i < limit_size; i += 10) {
		// Add vertex
		g.addVertex(to_string(i));

		// Add 0,1,2 edges
		int r = rand() % 2;
		for (int j = 0; j < r; j++)
			addEdgeTest(g);

		cout << i << endl;

		test(g, i, file_ts, file_scc);
	}

	file_ts.close();
	file_scc.close();


	// GNU-Plot files
	ofstream TS_PLT("Topological Sort analisys.plt");
	ofstream SCC_PLT("Strong Connected Components analisys.plt");

	TS_PLT << "set style line 1 lc rgb '#0BFA5' lt 1 lw 2 pt 7 ps 1.5" << endl;
	TS_PLT << "plot 'Topological Sort.dat' with linespoints ls 1";

	SCC_PLT << "set style line 1 lc rgb '#0b9e9' lt 1 lw 2 pt 7 ps 1.5" << endl;
	SCC_PLT << "plot 'Strong Connected Components.dat' with linespoints ls 1";

	TS_PLT.close();
	SCC_PLT.close();

	return 0;
}
