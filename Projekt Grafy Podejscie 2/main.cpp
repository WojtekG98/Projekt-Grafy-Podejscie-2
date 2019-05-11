#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"EdgeMList.h"
#include"VertexList.h"
#include"VertexMList.h"
#include"AdjacencyList.h"
#include"AdjacencyMatrix.h"
#include"ListPriorityQueue.h"
#include"Algorytmy.h"

int main()
{
	unsigned IloscWierzcholkow=5;
	unsigned IloscKrawedzi = 5;

	ListPriorityQueue<VertexMList, VertexM, int>  kolejkaV;
	ListPriorityQueue<EdgeMList, EdgeM, int>  kolejkaE;
	AdjacencyMatrix graf(IloscWierzcholkow);
	AdjacencyList graf2(IloscWierzcholkow,IloscKrawedzi);
	VertexMList ListaTestowa1, ListaTestowa2;
	VertexList::Iterator beginV = graf2.vertices().begin();
	VertexMList::Iterator beginM = graf.vertices().begin();
	std::cout << "Lista sasiedztwa: " << std::endl;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		std::cout << "Wierzcholek i: " << i << " : "  << beginV.operator*().x << "  " << beginV.operator*().position << "  " << beginV.operator*().IncidenceCollection <<std::endl;
			++beginV;
	}

	std::cout << "Ilosc sasiadow:"  << std::endl;

	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		std::cout << "Wierzcholek " << i << ":" << graf2.AdList[i].size() << ", ";
		if (i % 10 == 9)
			std::cout << std::endl;
	}

	std::cout << std::endl << "Ilosc wierzcholkow= " << graf2.vertices().size() << ", n= " << graf2.n << std::endl;
	std::cout << "Ilosc krawedzi= " << graf2.edges().size() << ", m= " << graf2.m << std::endl;
	
	//graf.insertEdge(graf.vertices().begin().operator*(), (++graf.vertices().begin()).operator*(), 10);

	std::cout << "Macierz Sasiedztwa: " << std::endl;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		std::cout << "Wierzcholek i: " << i << " : " << beginM.operator*().index << "  " << beginM.operator*().x << "  " << beginM.operator*().position << std::endl;
		++beginM;
	}

	std::cout << "Ilosc sasiadow:" << std::endl;

	
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		for (unsigned j = 0; j < IloscWierzcholkow; j++)
			if (graf.MacierzSasiedztwa[i][j] != NULL)
			{
				std::cout.width(3);
				std::cout << graf.MacierzSasiedztwa[i][j]->x;
			}
			else
			{
				std::cout.width(3);
				std::cout << 0;
			}
		std::cout << std::endl;
	}

	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		for (unsigned j = 0; j < IloscWierzcholkow; j++)
			if (graf.MacierzSasiedztwa[i][j] != NULL)
			{
				//std::cout.width(2);
				//std::cout << graf.MacierzSasiedztwa[i][j]->vertex[0]->position << " -> " << graf.MacierzSasiedztwa[i][j]->vertex[1]->position << " ";
				std::cout << graf.MacierzSasiedztwa[i][j] << " ";
			}
			else
			{
				//std::cout.width(2);
				std::cout << " 0 ";
			}
		std::cout << std::endl;
	}
	graf.insertVertex(10);
	std::cout << std::endl << "Ilosc wierzcholkow= " << graf.vertices().size() << ", n= " << graf.n << std::endl;
	std::cout << "Ilosc krawedzi= " << graf.edges().size() << ", m= " << graf.m << std::endl;
	VertexMList::Iterator begin = graf.vertices().begin();
	kolejkaV.insert(*begin);
	kolejkaV.insert(*(++begin));
	kolejkaV.insert(*(++begin));
	kolejkaV.insert(*(++begin));
	kolejkaV.insert(*(++begin));
	std::cout << "kolejka min=" << kolejkaV.min().index << ",x=  "<<kolejkaV.min().x << std::endl;
	kolejkaV.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaV.min().index << ",x=  " << kolejkaV.min().x << std::endl;
	kolejkaV.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaV.min().index << ",x=  " << kolejkaV.min().x << std::endl;
	kolejkaV.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaV.min().index << ",x=  " << kolejkaV.min().x << std::endl;
	kolejkaV.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaV.min().index << ",x=  " << kolejkaV.min().x << std::endl;

	EdgeMList::Iterator begina = graf.edges().begin();
	kolejkaE.insert(*begina);
	kolejkaE.insert(*(++begina));
	kolejkaE.insert(*(++begina));
	kolejkaE.insert(*(++begina));
	kolejkaE.insert(*(++begina));
	std::cout << "kolejka min=" << kolejkaE.min().position << ",x=  " << kolejkaE.min().x << std::endl;
	kolejkaE.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaE.min().position << ",x=  " << kolejkaE.min().x << std::endl;
	kolejkaE.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaE.min().position << ",x=  " << kolejkaE.min().x << std::endl;
	kolejkaE.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaE.min().position << ",x=  " << kolejkaE.min().x << std::endl;
	kolejkaE.removeMin();
	std::cout << "kolejka min po removeMin=" << kolejkaE.min().position << ",x=  " << kolejkaE.min().x << std::endl;
	
	//std::cout << std::endl << Kruskal<AdjacencyMatrix, EdgeMList, VertexMList, EdgeM, VertexM>(graf, IloscWierzcholkow, IloscKrawedzi).n << std::endl;
	std::cout << std::endl << Kruskal<AdjacencyMatrix, EdgeMList, VertexMList, EdgeM, VertexM>(graf, IloscWierzcholkow, IloscKrawedzi).m << std::endl;

	/* TEST LISTY
	ListaTestowa1.insertBack(*graf.vertices().begin());
	ListaTestowa2.insertBack(*(++(++graf.vertices().begin())));

	Merge(ListaTestowa1, ListaTestowa2);

	VertexMList::Iterator ListaTestowa1Iterator = ListaTestowa1.begin();
	VertexMList::Iterator ListaTestowa2Iterator = ListaTestowa2.begin();
	for (unsigned i = 0; i < ListaTestowa1.size(); i++)
	{
		std::cout << "Lista Testowa1: " << i << ": " << ListaTestowa1Iterator.operator*().index << ", x=" << ListaTestowa1Iterator.operator*().x << std::endl;
		++ListaTestowa1Iterator;
	}
	
	std::cout << "Lista Testowa2: " << ListaTestowa2Iterator.operator*().index << ", x=" << ListaTestowa2Iterator.operator*().x << std::endl;
	*/
	std::cout << std::endl << "Gites\n";
	std::cin.ignore();
	
}