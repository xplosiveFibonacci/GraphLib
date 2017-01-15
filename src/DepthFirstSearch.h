/*
@file DepthFirstSearch.h
@brief defines a depth first search over a graph.
@date 15/01/2017
@author David Alba

---------------------------------- LICENSE ---------------------------------------
DepthFirstSearch.h is part of GraphLib

GraphLib is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GraphLib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

-------------------------------- DESCRIPTION ------------------------------------
A class for search on a graph in depth. The execution of some of the functions of this class
causes the collection of data, that the class provide to other classes that can be interested on
*/

#pragma once

#include "Graph.h"

using namespace std;

class DepthFirstSearch
{
	friend class Graph;
public:
	/*
		Creates a Depth First Search for a graph
	*/
	DepthFirstSearch(const Graph *g);

	~DepthFirstSearch();

	/*
		Executes the DFS search over the graph associated. As side-effect, it stores some
		interesting data. If want to recover this data, call the appropiate functions of this class
	*/
	void search();

	/*
		Returns the time in which each vertex was done. A vertex is considered "done" if
		all their adjacent vertex (their childs in a tree search) have been visited
	*/
	vector<int> getFinishedTimes() const;

	/*
		Returns the time in which each vertex was discovered. A vertex is considered
		discovered when is visited for the first time
	*/
	vector<int> getDiscoveredTimes() const;

	/*
		True if the DFS has discovered some cycle (i.e. the associated graph have cicles)
	*/
	bool isCiclyc() const;

	/*
		Returns the vertices of the graph ordered by finished times
	*/
	list<Vertex> getVerticesOrderedByFTime() const;

private:
	/*
	WHITE => undiscovered vertex
	GRAY  => discovered graph (still has undiscovered childs)
	BLACK => discovered graph (all its childs has been disconvered)
	*/
	enum color { WHITE, BLACK, GRAY };

	// ---------- ASSOCIATED GRAPH
	const Graph* g;
	int graph_size;

	// ---------- COLLECTED DATA
	vector<color> marks;
	vector<TimeStamp> time_stamps;
	list<Vertex> time_ordered_vlist;	// The vertices ordered by finished times
	bool hasCycle;

	// ---------- AUXILIAR ATTRIBUTTES
	int time;

	/*
	Just visits a vertex. v is the index of the vertex in graph's inner representation
	*/
   void visit(int v);

	/*
	A special dfs for the strongly connected componnents arguments
	*/
	vector<list<Vertex>> specialSearch(list<Vertex> orderedList);

	/*
	A special visit for the special dfs
	*/
	void specialVisit(int v, list<Vertex>& s);
};
