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
	std::cout << "Merge: \n";
	for (unsigned i = 0; i < lista1.size(); i++)
	{
		std::cout << "index= " << Lista1Iterator.operator*().index << ", x=" << Lista1Iterator.operator*().x << std::endl;
		++Lista1Iterator;
	}
	std::cout << "WITH: \n";
	typename lista::Iterator Lista2Iterator = lista2.begin();
	for (unsigned i = 0; i < lista2.size(); i++)
	{
		std::cout << "index= " << Lista2Iterator.operator*().index << ", x=" << Lista2Iterator.operator*().x << std::endl;
		lista1.insertBack(Lista2Iterator.operator*());
		lista2.eraseFront();
		++Lista2Iterator;
	}
	Lista1Iterator = lista1.begin();
	std::cout << "Merge: \n";
	for (unsigned i = 0; i < lista1.size(); i++)
	{
		std::cout << "index= " << Lista1Iterator.operator*().index << ", x=" << Lista1Iterator.operator*().x << std::endl;
		++Lista1Iterator;
	}
}

template <typename lista,typename element>
bool IsContaining(lista &lista1, element &Element) //adds lista2 elements to lista1 and deletes them from lista2
{
	return true;
}

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
	for (unsigned i = 0; i < T.edges().size(); i++)
	{
		T.edges().eraseFront();
	}
	T.IK = 0;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		std::cout << "C[" << i << "].size()=" << C[i].size() << std::endl;
	std::cout << "--------------------------\n";
	//while (T.IK < (IloscWierzcholkow - 1))
	for (unsigned i = 1; i < IloscWierzcholkow; i++)
	{
		if (!Q.empty())
		{
			Wierzcholek u = *Q.min().vertex[0];
			Wierzcholek v = *Q.min().vertex[1];
			//if (IsContaining(C[u.index],v) || IsContaining(C[v.index], u))
			//{
			T.insertEdge(u, v, Q.min().x);
			std::cout << "BEDZIE MERGE\n";
			Merge(C[0], C[i]);
			//}
			Q.removeMin();
		}
		else
			T.IK++;
	}
	std::cout << "--------------------------\n";
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		if (C[i].size() > 0)
		//std::cout << "C[" << i << "].size()="<< C[i].size()<<std::endl;
		
		{
			std::cout << "C[" << i << "]:\n";
			typename ListaWierzcholkow::Iterator It = C[i].begin();
			while (It != C[i].end())
			{
				std::cout <<"index= "<<It.operator*().index<<", x="<< It.operator*().x << std::endl;
				++It;
			}
		}

	return T;
}
#endif