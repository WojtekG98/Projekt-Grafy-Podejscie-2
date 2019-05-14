#pragma once
#ifndef ALGORYTMY
#define ALGORYTMY
#include <algorithm>
#include "ListPriorityQueue.h"
typedef int Elem;

template <typename lista>
void Merge(lista &lista1, lista &lista2) //adds lista2 elements to lista1 and deletes them from lista2
{
	typename lista::Iterator Lista1Iterator = lista1.begin();
	typename lista::Iterator Lista2Iterator = lista2.begin();
	if (!lista1.empty())
	{
		/*
		std::cout << "Merge: \n";
		for (unsigned i = 0; i < lista1.size(); i++)
		{
			std::cout << "index= " << Lista1Iterator.operator*().index << ", x=" << Lista1Iterator.operator*().x << std::endl;
			++Lista1Iterator;
		}
		std::cout << "WITH: \n";
		

		
		while (Lista2Iterator != lista2.end())
		{
			std::cout << "index= " << Lista2Iterator.operator*().index << ", x=" << Lista2Iterator.operator*().x << std::endl;
			++Lista2Iterator;
		}
		*/
		Lista2Iterator = lista2.begin();
		while (Lista2Iterator != lista2.end())
		{
			lista1.insertBack(Lista2Iterator.operator*());
			++Lista2Iterator;
		}

		while (lista2.begin() != lista2.end())
		{
			//std::cout << "USUNIETO: index= " << lista2.begin().operator*().index << ", x=" << lista2.begin().operator*().x << std::endl;
			lista2.eraseFront();
		}
		
		/*
		Lista1Iterator = lista1.begin();
		std::cout << "Merge: \n";
		for (unsigned i = 0; i < lista1.size(); i++)
		{
			std::cout << "index= " << Lista1Iterator.operator*().index << ", x=" << Lista1Iterator.operator*().x << std::endl;
			++Lista1Iterator;
		}
		*/
	}
}

template <typename Graph,typename ListaKrawedzi, typename ListaWierzcholkow, typename Krawedz, typename Wierzcholek>
Graph Kruskal(Graph &Graf, unsigned IloscWierzcholkow)
{
	Graph T(IloscWierzcholkow);
	ListaWierzcholkow **C;
	ListPriorityQueue<ListaKrawedzi, Krawedz, Elem> Q;
	typename ListaKrawedzi::Iterator beginE = Graf.edges().begin();
	typename ListaWierzcholkow::Iterator beginV = Graf.vertices().begin();
	C = new ListaWierzcholkow*[IloscWierzcholkow];
	while (beginE != Graf.edges().end())
	{
		Q.insert(*beginE);
		++beginE;
	}
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		C[i] = new ListaWierzcholkow;
		(*C[i]).insertBack(*beginV);
		++beginV;
	}

	while (T.IK < (IloscWierzcholkow - 1))
	{
		if (!Q.empty())
		{
			Wierzcholek u = *Q.min().vertex[0];
			Wierzcholek v = *Q.min().vertex[1];
			if (C[u.index]!=C[v.index])
			{
				T.insertEdge(*Q.min().vertex[0], *Q.min().vertex[1], Q.min().x);
				Merge(*C[u.index], *C[v.index]);
				ListaWierzcholkow *Pom = C[v.index];
				for (unsigned i = 0; i < IloscWierzcholkow; i++)
					if (C[i]== Pom)
						C[i] = C[u.index];
			}
			Q.removeMin();
		}
		else
			T.IK++;
	}	
	/*
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		
		{
			std::cout << "C[" << i << "]:\n";
			typename ListaWierzcholkow::Iterator It = (*C[i]).begin();
			while (It != (*C[i]).end())
			{
				std::cout <<"index= "<<It.operator*().index<<", x="<< It.operator*().x << std::endl;
				++It;
			}
		}
	*/
	/*
	typename ListaKrawedzi::Iterator KruskalIterator = T.edges().begin();
	while (KruskalIterator != T.edges().end())
	{
		std::cout << KruskalIterator.operator*().vertex[0]->index << "->" << KruskalIterator.operator*().vertex[1]->index << std::endl;
		++KruskalIterator;
	}
	*/
	return T;
	}
#endif