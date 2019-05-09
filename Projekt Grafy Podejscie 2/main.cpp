#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"VertexList.h"
#include"AdjacencyList.h"
//#include"AdjacencyList.h"
int main()
{
	unsigned IloscWierzcholkow=10;
	unsigned IloscKrawedzi = 10;
	AdjacencyList graf(IloscWierzcholkow,IloscKrawedzi);
	
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		graf.insertVertex(i);
	VertexList::Iterator beginV = graf.vertices().begin();
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
	{
		std::cout << "Adres wierzcholka i: " << i << "  " << beginV.operator*().position << "  " << beginV.operator*().IncidenceCollection <<std::endl;
			++beginV;
	}
	VertexList::Iterator end = --graf.vertices().end();
	VertexList::Iterator begin = graf.vertices().begin();
	VertexList::Iterator begin2 = graf.vertices().begin();
	VertexList::Iterator begin3 = graf.vertices().begin();
	//for (unsigned j = 0; j < IloscWierzcholkow; j++)
	//{
		for (unsigned i = 0; i < IloscKrawedzi; i++)
		{
			graf.insertEdge(*begin, *end, i);
			//std::cout << begin.operator*().x <<" " ;
			//if (begin != begin2)
				//graf.insertEdge(*begin, *begin2, i);
			++begin;
			--end;
		}
		std::cout << std::endl;
		//end = --graf.vertices().end();
		//++begin3;
		//begin2 = begin3;
	//}

	std::cout << "Sasiedzi " << (++graf.vertices().begin()).operator*().x << ": " << std::endl;
	
	VertexList::Iterator it = ((((++(graf.vertices()).begin()).operator*()).IncidenceCollection)->begin());
	
	for (unsigned i = 0; i < ((((++(graf.vertices()).begin()).operator*()).IncidenceCollection)->size()); i++)
		{
			std::cout << " i: " << i << "  " << (++(graf.vertices()).begin()).operator*().x << " -> " << it.operator*().x << ", ";
			++it;
		}
	std::cout << std::endl << "Lista krawedzi:" << std::endl;
	EdgeList::Iterator beginE = graf.edges().begin();
		for (unsigned i = 0; i < graf.edges().size(); i++)
		{
			std::cout << " i: " << i << "  " << beginE.operator*().x << "  ";
			std::cout << beginE.operator*().vertex[0]->x << "  " << beginE.operator*().vertex[0]->position << "  " << beginE.operator*().vertex[0]->IncidenceCollection;
			std::cout << "->";
			std::cout << beginE.operator*().vertex[1]->x << "  " << beginE.operator*().vertex[1]->position << "  " << beginE.operator*().vertex[1]->IncidenceCollection;
			std::cout << std::endl;
			++beginE;
		}

	std::cout << "Ilosc sasiadow:" << (graf.vertices().begin().operator*().IncidenceCollection)->size() << std::endl;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		std::cout << graf.AdList[i].size() << std::endl;

	std::cout << "Ilosc wierzcholkow= " << graf.vertices().size() << std::endl;
	std::cout << "Ilosc krawedzi= " << graf.edges().size() << std::endl;
	std::cout << std::endl << "Gites\n";
	std::cin.ignore();
	
}