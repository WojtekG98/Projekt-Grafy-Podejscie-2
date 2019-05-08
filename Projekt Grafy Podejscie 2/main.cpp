#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"VertexList.h"
#include"AdjacencyList.h"
//#include"AdjacencyList.h"
int main()
{
	Edge krawedz;
	EdgeList ListaKrawedzi;
	krawedz.x = 10;
	ListaKrawedzi.insertBack(krawedz);
	std::cout << "Size: " << ListaKrawedzi.size() << std::endl;
	std::cout << "Gites\n";
	std::cin.ignore();
}