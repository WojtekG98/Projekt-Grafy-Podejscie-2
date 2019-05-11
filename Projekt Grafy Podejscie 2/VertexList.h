#pragma once
#ifndef VERTEXLIST
#define VERTEXLIST
#include"EdgeList.h"
typedef int Elem;										// list base element type


class VertexList;

struct Vertex {
	Elem x;
	Vertex* position;//zmienic na VertexList::Iterator* position;!!!!
	VertexList* IncidenceCollection;
	unsigned index;
};

class VertexList {										//node-based list
private:
	struct Node {										// a node of the list
		Vertex elem;										// element value
		Node* prev;										// previous in list
		Node* next;										// next in list
	};
public:
	class Iterator {									// an iterator for the list
	public:
		Vertex& operator*();								// reference to the element
		bool operator==(const Iterator& p) const;		// compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();							// move to next position
		Iterator& operator--();							// move to previous position
		friend class VertexList;							// give NodeList access
	private:
		Node* v;										// pointer to the node
		Iterator(Node* u);								// create from node
	};
public:
	VertexList();											// default constructor
	int size() const;									// list size
	bool empty() const;									// is the list empty?
	Iterator begin() const;								// beginning position
	Iterator end() const;								// (just beyond) last position
	void insertFront(const Vertex& e);					// insert at front
	void insertBack(const Vertex& e);						// insert at rear
	void insert(const Iterator& p, const Vertex& e);		// insert e before p
	void eraseFront();									// remove first
	void eraseBack();									// remove last
	void erase(const Iterator& p);						// remove p
private:												// data members
	int n;												// number of items
	Node* header;										// head-of-list sentinel
	Node* trailer;										// tail-of-list sentinel
};

VertexList::Iterator::Iterator(Node* u)
{
	v = u;
}

Vertex& VertexList::Iterator::operator*()
{
	return v->elem;
}

bool VertexList::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

bool VertexList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

VertexList::Iterator& VertexList::Iterator::operator++()
{
	v = v->next; return *this;
}

VertexList::Iterator& VertexList::Iterator::operator--()
{
	v = v->prev; return *this;
}

VertexList::VertexList()									//constructor
{
	n = 0;												// initially empty
	header = new Node;									// create sentinels
	trailer = new Node;
	header->next = trailer;								// have them point to each other
	trailer->prev = header;
}

int VertexList::size() const								// list size
{
	return n;
}

bool VertexList::empty() const							// is the list empty?
{
	return (n == 0);
}

VertexList::Iterator VertexList::begin() const				// begin position is first item
{
	return Iterator(header->next);
}

VertexList::Iterator VertexList::end() const				// end position is just beyond last
{
	return Iterator(trailer);
}

void VertexList::insert(const VertexList::Iterator& p, const Vertex& e) // insert e before p
{
	Node* w = p.v;										// insert e before p
	Node* u = w->prev;									// p’s predecessor
	Node* v = new Node;									// new node to insert
	v->elem = e;
	v->next = w; w->prev = v;							// link in v before w
	v->prev = u; u->next = v;							// link in v after u
	n++;												// one more element
}

void VertexList::insertFront(const Vertex& e)				// insert at front
{
	insert(begin(), e);
}

void VertexList::insertBack(const Vertex& e)				// insert at rear
{
	insert(end(), e);
}

void VertexList::erase(const Iterator& p)					// remove p
{
	Node* v = p.v;										// node to remove
	Node* w = v->next;									// successor
	Node* u = v->prev;									// predecessor
	u->next = w; w->prev = u;							// unlink p
	delete v;											// delete this node
	n--;												// one fewer element
}

void VertexList::eraseFront()								// remove first
{
	erase(begin());
}

void VertexList::eraseBack()								// remove last
{
	erase(--end());
}
#endif 
