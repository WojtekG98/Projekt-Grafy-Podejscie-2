#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"EdgeMList.h"
#include"VertexList.h"
#include"VertexMList.h"
#include"AdjacencyList.h"
#include"AdjacencyMatrix.h"

int main()
{
	unsigned IloscWierzcholkow=50;
	unsigned IloscKrawedzi = 50;

	AdjacencyMatrix graf(IloscWierzcholkow);
	AdjacencyList graf2(IloscWierzcholkow,IloscKrawedzi);
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
				std::cout.width(2);
				std::cout <<1;
			}
			else
			{
				std::cout.width(2);
				std::cout << 0;
			}
		std::cout << std::endl;
	}
	graf.insertVertex(10);
	std::cout << std::endl << "Ilosc wierzcholkow= " << graf.vertices().size() << ", n= " << graf.n << std::endl;
	std::cout << "Ilosc krawedzi= " << graf.edges().size() << ", m= " << graf.m << std::endl;
	std::cout << std::endl << "Gites\n";
	std::cin.ignore();
	
}