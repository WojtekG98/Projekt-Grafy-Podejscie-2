#include<iostream>
#include<chrono>
#include<conio.h>
#include<fstream>
#include"list.h"
#include"EdgeList.h"
#include"EdgeMList.h"
#include"VertexList.h"
#include"VertexMList.h"
#include"AdjacencyList.h"
#include"AdjacencyMatrix.h"
#include"ListPriorityQueue.h"
#include"Algorytmy.h"

using namespace std;

int main()
{
	unsigned IloscWierzcholkow=1000;
	unsigned GestoscGrafu = 100;
	ListPriorityQueue<VertexMList, VertexM, int>  kolejkaV;
	ListPriorityQueue<EdgeMList, EdgeM, int>  kolejkaE;
	AdjacencyMatrix graf(IloscWierzcholkow,GestoscGrafu);
	AdjacencyList graf2(IloscWierzcholkow,GestoscGrafu);
	VertexMList ListaTestowa1, ListaTestowa2;
	VertexList::Iterator beginV = graf2.vertices().begin();
	VertexMList::Iterator beginM = graf.vertices().begin();
	fstream zapis;
	zapis.open("zapis.txt", ios::out);
	/*
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
				//std::cout << graf.MacierzSasiedztwa[i][j]->vertex[0]->position << " -> " << graf.MacierzSasiedztwa[i][j]->vertex[1]->position << " ";
				std::cout << graf.MacierzSasiedztwa[i][j] << " ";
			}
			else
			{
				std::cout << " 0 ";
			}
		std::cout << std::endl;
	}
	*/
	//std::cout << std::endl << "Ilosc wierzcholkow= " << graf.vertices().size() << ", n= " << graf.n << std::endl;
	//std::cout << "Ilosc krawedzi= " << graf.edges().size() << ", m= " << graf.m << std::endl;


	//std::cout << "MacierzSasiedztwa:" << std::endl;
	auto start = chrono::steady_clock::now();
	//std::cout << std::endl << Kruskal<AdjacencyMatrix, EdgeMList, VertexMList, EdgeM, VertexM>(graf, IloscWierzcholkow).IK << std::endl;
	std::cout << std::endl << Kruskal<AdjacencyList, EdgeList, VertexList, Edge, Vertex>(graf2, IloscWierzcholkow).IK << std::endl;
	auto end = chrono::steady_clock::now();

	//std::cout << "ListaSasiedztwa:" << std::endl;
	
	
	std::cout << std::endl << "Gites\n";
	zapis << "Czas w milisekundach : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	//std::cin.ignore();
	
}