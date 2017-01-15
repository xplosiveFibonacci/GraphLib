#include "Graph.h"

Graph::Graph()
{
	vertices = vector<Vertex>();
}

Graph::Graph(vector<string> ids)
{
	Graph();
	for (int i = 0; i < ids.size(); i++) {
		addVertex(ids[i]);
	}
}

Graph::~Graph()
{
	// Nothing to destroy (?)
}

void Graph::addVertex(string id)
{
	Vertex v = { id, vector<Edge>() };
	vertices.push_back(v);
	index_table.insert(pair<string, int>(id, vertices.size() - 1));
}

void Graph::addEdge(string A, string B)
{
	int Aindex = index_table.at(A);
	int Bindex = index_table.at(B);

	addEdge(Aindex, Bindex);
}

void Graph::addEdge(int a, int b)
{
	Edge e = { vertices[b], 0 };
	vertices[a].adjacencyList.push_back(e);
}

bool Graph::existEdge(string A, string B) const
{
	int Aindex = index_table.at(A);
	int Bindex = index_table.at(B);

	return existEdge(Aindex, Bindex);
}

bool Graph::existEdge(int a, int b) const
{
	vector<Edge>::const_iterator it;
	for (it = vertices[a].adjacencyList.cbegin(); it != vertices[a].adjacencyList.cend(); it++)
		if (it->v.id == vertices[b].id)
			return true;
	return false;
}

bool Graph::isCiclyc() const
{
	DepthFirstSearch dfs(this);
	dfs.search();
	return dfs.hasCycle;
}

int Graph::size() const
{
	return vertices.size();
}


string Graph::print() const
{
	string ret;

	for (int i = 0; i < vertices.size(); i++) {
		ret += vertices[i].id + " -> ";
		for (int j = 0; j < vertices[i].adjacencyList.size(); j++)
			ret += vertices[i].adjacencyList[j].v.id + " ";
		ret += "\n";
	}

	return ret;
}


list<Vertex> Graph::topologicalSort()
{
	DepthFirstSearch dfs(this);
	dfs.search();
	return dfs.getVerticesOrderedByFTime();
}



Graph Graph::transpose()
{
	vector<string> ids;

	vector<Vertex>::iterator it;
	for (it = this->vertices.begin(); it != vertices.end(); it++)
		ids.push_back(it->id);

	Graph t(ids);	// Couldnt make a copy because the edges would remain

	vector<Edge>::iterator e_it;
	for (it = this->vertices.begin(); it != vertices.end(); it++) {
		Vertex v = *it;
		for (e_it = v.adjacencyList.begin(); e_it != v.adjacencyList.end(); e_it++) {
			t.addEdge(e_it->v.id, v.id);
		}
	}

	return t;
}

vector<list<Vertex>> Graph::stronglyConnectedComponents()
{
	// 1. call DFS(G) to compute ﬁnishing finished times for each vertex u 
	DepthFirstSearch dfs(this);
	dfs.search();

	list<Vertex> orderedList = dfs.getVerticesOrderedByFTime();

	// 2. Compute Gt (transponse G)
	Graph t = this->transpose();

	/* 3. call DFS(Gt), but in the main loop of DFS, consider the vertices in order of decreasing
	finished time 4. Return the strongly connected components found */
	DepthFirstSearch dfs_t(&t);
	return dfs_t.specialSearch(orderedList);
}





