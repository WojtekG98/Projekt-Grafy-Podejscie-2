#pragma once
#ifndef LISTPRIORITYQUEUE
#define LISTPRIORITYQUEUE
#include"EdgeList.h"
#include"VertexList.h"
//typedef int C;
//typedef VertexMList lista;
//typedef VertexM E;

template <typename lista, typename E, typename C >
class ListPriorityQueue {
public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
private:
	lista L;
	C isLess;
};

template <typename lista, typename E, typename C > 
int ListPriorityQueue< lista, E, C >::size() const{ return L.size(); }template <typename lista, typename E, typename C >bool ListPriorityQueue< lista, E, C >::empty() const{ return L.empty();}
template <typename lista, typename E, typename C >
void ListPriorityQueue< lista, E, C >::insert(const E& e) {
	typename lista::Iterator p = L.begin();
	//std::cout << p.operator*().index << std::endl;
	
	while (p != L.end() && e.x > p.operator*().x){
		//std::cout << "while\n";
		//if (e.x > p.operator*().x)
		//{
			//std::cout << "if\n";
	 		++p;
		//}		
	}
	
	L.insert(p, e);
	//std::cout << p.operator*().index << std::endl;
	//std::cout << L.begin().operator*().index << std::endl;
}

template <typename lista, typename E, typename C >
const E& ListPriorityQueue< lista, E, C >::min() const
{
	return L.begin().operator*();
}

template <typename lista, typename E, typename C >
void ListPriorityQueue< lista, E, C >::removeMin()
{
	L.eraseFront();
}

#endif