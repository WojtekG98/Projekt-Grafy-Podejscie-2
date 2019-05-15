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
	unsigned IloscWierzcholkow=500;
	unsigned GestoscGrafu = 75;
	AdjacencyMatrix macierz(IloscWierzcholkow,GestoscGrafu);
	AdjacencyList lista(IloscWierzcholkow,GestoscGrafu);
	fstream zapis;

	zapis.open("zapis.txt", ios::out);
	std::cout << "Kruskal:\n\n";
	auto start = chrono::steady_clock::now();
	//std::cout <<  Kruskal<AdjacencyMatrix, EdgeMList, VertexMList, EdgeM, VertexM>(macierz, IloscWierzcholkow).IK << std::endl;
	std::cout <<  Kruskal<AdjacencyList, EdgeList, VertexList, Edge, Vertex>(lista, IloscWierzcholkow).IK << std::endl;
	auto end = chrono::steady_clock::now();

	std::cout << std::endl << "Gites\n";
	zapis << "Czas w milisekundach : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	//std::cin.ignore();	
}