/*
@file Graph.h
@brief defines the graph class and the common functionality for (almost) all algorithms over graphs
@date 15/01/2017
@author David Alba

---------------------------------- LICENSE ---------------------------------------
Graph.h is part of GraphLib

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
An adjacency-list representation of a graph. A graph is considered to be a set of
vertices plus the ability to manipulate the adjacency-list of each vertex (as well as
to add new vertices).
*/

#pragma once

#include <vector>
#include <map>
#include <string>
#include <list>

#include "Utils.h";
#include "DepthFirstSearch.h"

using namespace std;

class Graph
{
	friend class DepthFirstSearch;
public:
	// ++++++++++++++++++++++++++++++++++++++++++++
	//			CONSTRUCTORS/DESTRUCTORS
	// ++++++++++++++++++++++++++++++++++++++++++++

	/*
		Default constructor
	*/
	Graph();

	~Graph();

	/*
		Constructs a new graph with a list of vertex identifiers
	*/
	Graph(vector<string> ids);

	// ++++++++++++++++++++++++++++++++++++++++++++
	//			  BASIC FUNCTIONALITY
	// ++++++++++++++++++++++++++++++++++++++++++++

	/*
		Adds a new vertex with an identifier
	*/
	void addVertex(string id);

	/*
		Adds a directed edge that goes from the vertex named A to the one named B
	*/
	void addEdge(string A, string B);

	/*
		Adds a directed edge that goes from the ath vertex created to the bth vertex created
	*/
	void addEdge(int a, int b);

	// ++++++++++++++++++++++++++++++++++++++++++++
	//				READ ONLY FUNCTIONS
	// ++++++++++++++++++++++++++++++++++++++++++++

	/*
		Returns true if exist and edge from the vertex named A to the one named B
	*/
	bool existEdge(string A, string B) const;

	/*
		Returns true if exist an edge from the ath vertex created to the bth vertex created
	*/
	bool existEdge(int a, int b) const;

	/*
		True if the graph has cycles(1 or more). Technically: a graph has cycles if given a vertex A of
		the graph, exist a path with length > 0 that goes from A to A, for some A
	*/
	bool isCiclyc() const;

	/*
		Returns the number of vertices (i.e. the size of the graph)
	*/
	int size () const;

	/*
		A string representation of the graph.
	*/
	string print() const;
	
	// ++++++++++++++++++++++++++++++++++++++++++++
	//				  ALGORITHMS
	// ++++++++++++++++++++++++++++++++++++++++++++

	/*
		Returns a topological sort of the graph. A topological sort of a dag G = (V,E) is a linear ordering of 
		all its vertices such that if G contains an edge (u,v) then u appears before v in the ordering
	*/
	list<Vertex> topologicalSort();

	/*
		Returns the transpose of the graph. By definition, the transponse of a graph
		G = (V,E) is the graph Gt = (V,Et) where Et = {(u,v) | (v,u) belongs E}
	*/
	Graph transpose();

	/*
		Returns the strongly connected components of a graph. A strongly connected component of a 
		directed graph G = (V,E) is a maximal set of vertices C (with C subset of V) such that for every 
		pair of vertices u and v in C, we have both the path u -> v and v -> u 
	*/
	vector<list<Vertex>> stronglyConnectedComponents();

private:
	vector<Vertex> vertices;
	map<string, int> index_table;	// map each Vertex with the index that it occupies in the vector
};

