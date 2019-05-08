#pragma once
#ifndef ADJACENCYLIST
#define ADJACENCYLIST
#include"EdgeList.h"
#include"VertexList.h"


class AdjacencyList {
private:
	unsigned n; //ilosc wierzcholkow
	unsigned m; //ilosc krawedzi
	VertexList V;
	EdgeList E;
public:
	Vertex[2] endVertices(Edge e);
	Vertex opposite(Vertex v, Edge e);
	bool areAdjacent(Vertex v, Vertex w);
	void replace(Vertex v, Elem w);
	void replace(Edge v, Elem w);
	void insertVertex(Elem o);
	void insertEdge(Vertex v, Vertex w, Elem o);
	void removeVertex(Vertex v);
	void removeEdge(Edge e);
};

#endif