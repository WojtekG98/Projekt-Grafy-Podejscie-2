#pragma once
#ifndef ALGORYTMY
#define ALGORYTMY
#include <algorithm>
#include "ListPriorityQueue.h"
typedef int Elem;

template <typename Graph,typename ListaKrawedzi, typename ListaWierzcholkow, typename Krawedz, typename Wierzcholek>
Graph Kruskal(Graph Graf, unsigned IloscWierzcholkow, unsigned IloscKrawedzi)
{
	Graph T(IloscWierzcholkow);
	ListaWierzcholkow *C;
	ListPriorityQueue<ListaKrawedzi, Krawedz, Elem> Q;
	typename ListaKrawedzi::Iterator beginE = Graf.edges().begin();
	typename ListaWierzcholkow::Iterator beginV = Graf.vertices().begin();
	C = new ListaWierzcholkow[IloscWierzcholkow];
	while (beginE != Graf.edges().end())
	{
		Q.insert(*beginE);
		++beginE;
	}
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		C[i].insertBack(*beginV);
		++beginV;
	}
	while (T.IK < (IloscWierzcholkow - 1))
	{
		Wierzcholek u = *Q.min().vertex[0];
		Wierzcholek v = *Q.min().vertex[1];
		if (&u!=&v)
			T.insertEdge(u, v, Q.min().x);
		Q.removeMin();
	}
	return T;
}
#endif