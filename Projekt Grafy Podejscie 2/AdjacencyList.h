#pragma once
#ifndef ADJACENCYLIST
#define ADJACENCYLIST
#include"EdgeList.h"
#include"VertexList.h"
#include <ctime> 
#include <cstdlib>

class AdjacencyList {
public:
	unsigned n; //ilosc wierzcholkow
	unsigned m; //ilosc krawedzi
	unsigned IW=0;
	unsigned IK=0;
	VertexList V;
	EdgeList E;
	VertexList *AdList;
public:
	AdjacencyList(unsigned IloscWierzcholkow);
	AdjacencyList(unsigned IloscWierzcholkow, unsigned IloscKrawedzi);
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

AdjacencyList::AdjacencyList(unsigned IloscWierzcholkow)
{
	n = IloscWierzcholkow;
	AdList = new VertexList[IloscWierzcholkow];
	//for (unsigned i=0; i < IloscWierzcholkow; i++)
		//std::cout << "konstruktor: " << &AdList[i] << std::endl;
}

AdjacencyList::AdjacencyList(unsigned IloscWierzcholkow, unsigned IloscKrawedzi)
{
	n = IloscWierzcholkow;
	AdList = new VertexList[IloscWierzcholkow];

	srand(time(0));
	int *visited; // to mark used random numbers. Let all of the values be 0 initially.
	visited = new int[n];
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		visited[i] = 0;

	for (unsigned i=0; i < IloscWierzcholkow; )
	{
		int num = rand() % IloscWierzcholkow;
		// check if num has already been generated
		if (visited[num] == 0)
		{
			// now mark it as used
			visited[num] = 1;
			insertVertex(num);
			i++;
		}
	}

	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		visited[i] = 0;
	VertexList::Iterator end = --vertices().end(), begin = vertices().begin();
	for (unsigned i = 0; i < IloscKrawedzi; i++)
	{
		int num = rand() % IloscKrawedzi;
		if (visited[num] == 0 )
		{
			insertEdge(*begin, *end, num);
			++begin;
			--end;
		}
	}
}

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
	v.IncidenceCollection = new VertexList;
	v.x = o;
	//std::cout <<"insertvertex: "<< &AdList[IW] << std::endl;
	v.IncidenceCollection = &AdList[IW];
	V.insertBack(v);
	(--V.end()).operator*().position= &(*(--V.end()));
	v.position = &(*(--V.end()));
	IW++;
}

void AdjacencyList::insertEdge(Vertex &v, Vertex &w, Elem o)
{
	Edge e;
	if (&w != &v)
	{
		e.x = o;
		e.vertex[0] = &v;
		e.vertex[1] = &w;
		v.IncidenceCollection->insertBack(w);
		w.IncidenceCollection->insertBack(v);
		e.IncidenceCollection[0] = v.IncidenceCollection;
		e.IncidenceCollection[1] = w.IncidenceCollection;
		E.insertBack(e);
		(--E.end()).operator*().position = &(*(--E.end()));
		e.position = &(*(--E.end()));
		m++;
		IK++;
	}
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