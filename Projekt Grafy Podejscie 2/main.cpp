#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"VertexList.h"
#include"AdjacencyList.h"
//#include"AdjacencyList.h"
int main()
{
	unsigned IloscWierzcholkow=50;
	unsigned IloscKrawedzi = 10;
	AdjacencyList graf;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		graf.insertVertex(i);
	for (unsigned i = 0; i < IloscKrawedzi; i++)
		graf.insertEdge(*(++graf.vertices().begin()), *(--graf.vertices().end()), i);
	std::cout << "Ilosc wierzcholkow= " << graf.vertices().size() << std::endl;
	std::cout << "Ilosc krawedzi= " << graf.edges().size() << std::endl;
	std::cout << std::endl << "Gites\n";
	std::cin.ignore();
	
}