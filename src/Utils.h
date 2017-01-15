/*
@file Utils.h
@brief defines the data structures nedeed by a graph (and/or algorithms over graphs)
@date 15/01/2017
@author David Alba

---------------------------------- LICENSE ---------------------------------------
Utils.h is part of GraphLib

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
The definition and implementation of some useful data structures for graphs, which are 
the representation of concepts that comes from graph theory
*/

#pragma once

#include <string>
#include <vector>

/*
	A vertex of a graph. A vertex is an identifier and its adjacency list (that is the list
	of vertices adjacent to it)
*/
struct Vertex;

/*
	An edge of a graph. An edge is seen as conecting one source vertex to another (instead of
	two any vertices). This way, an edge is composed by a vertex and a weight (for support weighted
	graphs) and each vertex store its own adjacency list (a list of edges).
*/
struct Edge;

/*
	Just a mark of time for search algorithms over graphs. The semantic of its fields are arbitrary,
	but was thinking to be the time in which a vertex was discovered and the time in which was done (
	a vertex is considered done if all their childs has been visited)
*/
struct TimeStamp;

struct Vertex {
	std::string id;
	std::vector<Edge> adjacencyList;
};

struct Edge {
	Vertex v;
	int weight;
};

struct TimeStamp {
	int discovered_time;
	int finished_time;
};
