#pragma once
#ifndef ADJACENCYMATRIX
#define ADJACENCYMATRIX
#include"EdgeMList.h"
#include"VertexMList.h"

class AdjacencyMatrix {
public:
	unsigned n; //ilosc wierzcholkow
	unsigned m; //ilosc krawedzi
	unsigned IW = 0;
	unsigned IK = 0;
	VertexMList V;
	EdgeMList E;
	EdgeM ***MacierzSasiedztwa;
public:
	AdjacencyMatrix(unsigned IloscWierzcholkow);
	AdjacencyMatrix(unsigned IloscWierzcholkow, unsigned GestoscGrafu);
	void insertVertex(Elem o);
	void insertEdge(VertexM &v, VertexM &w, Elem o);
	void removeVertex(VertexM v);
	void removeEdge(EdgeM e);
	void replace(VertexM v, Elem w);
	void replace(EdgeM e, Elem w);
	VertexMList vertices();
	EdgeMList edges();
	VertexM** endVertices(EdgeM &e);
	VertexM opposite(VertexM &v, EdgeM &e);
	bool areAdjacent(VertexM v, VertexM w);
};

AdjacencyMatrix::AdjacencyMatrix(unsigned IloscWierzcholkow)
{
	n = IloscWierzcholkow;
	MacierzSasiedztwa = new EdgeM**[IloscWierzcholkow];
	for (unsigned int i = 0; i < IloscWierzcholkow; i++)
		MacierzSasiedztwa[i] = new EdgeM*[IloscWierzcholkow];
	for (unsigned int i = 0; i < IloscWierzcholkow; i++)
		for (unsigned int j = 0; j < IloscWierzcholkow; j++)
			MacierzSasiedztwa[i][j] = NULL;
}

AdjacencyMatrix::AdjacencyMatrix(unsigned IloscWierzcholkow, unsigned GestoscGrafu)
{
	n = IloscWierzcholkow;
	MacierzSasiedztwa = new EdgeM**[IloscWierzcholkow];
	for (unsigned int i = 0; i < IloscWierzcholkow; i++)
		MacierzSasiedztwa[i] = new EdgeM*[IloscWierzcholkow];
	for (unsigned int i = 0; i < IloscWierzcholkow; i++)
		for (unsigned int j = 0; j < IloscWierzcholkow; j++)
			MacierzSasiedztwa[i][j] = NULL;

	int *visited;
	visited = new int[n];
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		visited[i] = 0;

	for (unsigned i = 0; i < IloscWierzcholkow; )
	{
		int num = rand() % IloscWierzcholkow;
		if (visited[num] == 0)
		{
			visited[num] = 1;
			insertVertex(num);
			i++;
		}
	}
	//for (unsigned i = 0; i < IloscWierzcholkow; i++)
		//insertVertex(i);

	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		visited[i] = 0;
	VertexMList::Iterator begin = vertices().begin(), begin2 = ++vertices().begin();
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		for (unsigned j = 0; j < IloscWierzcholkow - (i + 1); )
		{
			int num = rand() % IloscWierzcholkow;
			if (visited[num] == 0)
			{
				insertEdge(*begin, *begin2, num);
				if (j != IloscWierzcholkow - 1)
					++begin2;
				j++;
			}
		}
		++begin;
		begin2 = begin;
		if (i != IloscWierzcholkow - 1)
			++begin2;
	}
	m = IK;
}



VertexMList AdjacencyMatrix::vertices()
{ return V; }

EdgeMList AdjacencyMatrix::edges()
{ return E; }

void AdjacencyMatrix::insertVertex(Elem o)
{
	if (IW < n)
	{
		VertexM v;
		v.index = IW;
		v.x = o;
		V.insertBack(v);
		(--V.end()).operator*().position = &(*(--V.end()));
		v.position = &(*(--V.end()));
		IW++;
	}
}


void AdjacencyMatrix::insertEdge(VertexM &v, VertexM &w, Elem o)
{
	EdgeM e;
	if (MacierzSasiedztwa[v.index][w.index] == NULL && &v!=&w)
	{
		e.x = o;
		e.vertex[0] = &v;
		e.vertex[1] = &w;
		E.insertBack(e);
		(--E.end()).operator*().position = &(*(--E.end()));
		e.position = &(*(--E.end()));
		MacierzSasiedztwa[v.index][w.index] = e.position;
		MacierzSasiedztwa[w.index][v.index] = e.position;
		IK++;
	}
}

void AdjacencyMatrix::replace(VertexM v, Elem w)
{
	v.x = w;
}

void AdjacencyMatrix::replace(EdgeM e, Elem w)
{
	e.x = w;
}

#endif