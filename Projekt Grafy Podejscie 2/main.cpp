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
	unsigned GestoscGrafu = 50;
	std::cout << "Tworzenie Macierzy:\n\n";
	AdjacencyMatrix macierz(IloscWierzcholkow,GestoscGrafu);
	std::cout << "Tworzenie Listy:\n\n";
	AdjacencyList lista(IloscWierzcholkow,GestoscGrafu);
	fstream zapis;

	zapis.open("zapis.txt", ios::out);
	std::cout << "Kruskal:\n\n"; 
	//zapis << "macierz:\n";
	zapis << "lista:\n";
	auto start = chrono::steady_clock::now();
	//std::cout <<  Kruskal<AdjacencyMatrix, EdgeMList, VertexMList, EdgeM, VertexM>(macierz, IloscWierzcholkow).IK << std::endl;
	std::cout <<  Kruskal<AdjacencyList, EdgeList, VertexList, Edge, Vertex>(lista, IloscWierzcholkow).IK << std::endl;
	auto end = chrono::steady_clock::now();

	std::cout << std::endl << "Gites\n";
	zapis << "IloscWierzcholkow=";
	zapis << IloscWierzcholkow << std::endl;
	zapis << "Czas w milisekundach : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	//std::cin.ignore();	
}