#include<iostream>
#include"list.h"
#include"EdgeList.h"
#include"VertexList.h"
#include"AdjacencyList.h"
//#include"AdjacencyList.h"
int main()
{
	unsigned IloscWierzcholkow=50;
	unsigned IloscKrawedzi = 50;
	AdjacencyList graf(IloscWierzcholkow,IloscKrawedzi);
	
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		graf.insertVertex(i);

	VertexList::Iterator end = --graf.vertices().end();
	VertexList::Iterator begin = graf.vertices().begin();
	VertexList::Iterator begin2 = graf.vertices().begin();
	for (unsigned j = 0; j < IloscWierzcholkow; j++)
	{
		for (unsigned i = 0; i < IloscKrawedzi; i++)
		{
			//graf.insertEdge(*begin, *end, i);
			std::cout << begin.operator*().x <<" " ;
			if (begin != begin2)
				graf.insertEdge(*begin, *begin2, i);
			++begin2;
			//--end;
		}
		begin2= graf.vertices().begin();
		++begin;
	}

	std::cout << "Sasiedzi " << graf.vertices().begin().operator*().x << ": " << std::endl;
	
	VertexList::Iterator it = (((((graf.vertices()).begin()).operator*()).IncidenceCollection)->begin());
	
	for (unsigned i = 0; i < (((((graf.vertices()).begin()).operator*()).IncidenceCollection)->size()); i++)
		{
			std::cout << " i: " << i << "=" << it.operator*().x << ", ";
			++it;
		}
		
	std::cout << "Ilosc sasiadow:" << (graf.vertices().begin().operator*().IncidenceCollection)->size() << std::endl;
	for (unsigned i = 0; i < IloscWierzcholkow; i++)
		std::cout << graf.AdList[i].size() << std::endl;

	std::cout << "Ilosc wierzcholkow= " << graf.vertices().size() << std::endl;
	std::cout << "Ilosc krawedzi= " << graf.edges().size() << std::endl;
	std::cout << std::endl << "Gites\n";
	std::cin.ignore();
	
}