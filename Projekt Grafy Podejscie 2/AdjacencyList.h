#pragma once
#ifndef ADJACENCYLIST
#define ADJACENCYLIST
#include"EdgeList.h"
#include"VertexList.h"


class AdjacencyList {
public:
	unsigned n; //ilosc wierzcholkow
	unsigned m; //ilosc krawedzi
	VertexList V;
	EdgeList E;
public:
	Vertex** endVertices(Edge &e);
	Vertex opposite(Vertex &v, Edge &e);
	bool areAdjacent(Vertex v, Vertex w);
	void replace(Vertex v, Elem w);
	void replace(Edge e, Elem w);
	void insertVertex(Elem o);
	void insertEdge(Vertex &v, Vertex &w, Elem o);
	void removeVertex(Vertex v);
	void removeEdge(Edge e);
	VertexList vertices();
	EdgeList edges();
};

Vertex** AdjacencyList::endVertices(Edge &e)
{ return e.vertex; }

Vertex AdjacencyList::opposite(Vertex &v,Edge &e)
{
	if (e.vertex[1] == v.position)
		return *e.vertex[2];
	else
		if (e.vertex[2] == v.position)
			return *e.vertex[1];
}

void AdjacencyList::insertVertex(Elem o)
{
	Vertex v;
	v.x = o;
	v.IncidenceCollection = new VertexList;
	V.insertBack(v);
	v.position = &(*(--V.end()));
	n++;
}

void AdjacencyList::insertEdge(Vertex &v, Vertex &w, Elem o)
{
	Edge e;
	e.x = o;
	e.vertex[0] = &v;
	e.vertex[1] = &w;
	e.IncidenceCollection[0] = v.IncidenceCollection;
	e.IncidenceCollection[1] = w.IncidenceCollection;
	E.insertBack(e);
	e.position = &(*(--E.end()));
	m++;
}

void AdjacencyList::replace(Vertex v, Elem w)
{ v.x = w; }

void AdjacencyList::replace(Edge e, Elem w)
{ e.x = w; }

VertexList AdjacencyList::vertices() 
{ return V; }

EdgeList AdjacencyList::edges()
{ return E; }
#endif