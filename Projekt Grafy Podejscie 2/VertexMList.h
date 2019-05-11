#pragma once
#ifndef VERTEXMLIST
#define VERTEXMLIST
#include"EdgeMList.h"
typedef int Elem;										// list base element type


class VertexMList;

struct VertexM {
	Elem x;
	VertexM* position;//zmienic na VertexList::Iterator* position;!!!!
	unsigned index;
};

class VertexMList {										//node-based list
private:
	struct Node {										// a node of the list
		VertexM elem;										// element value
		Node* prev;										// previous in list
		Node* next;										// next in list
	};
public:
	class Iterator {									// an iterator for the list
	public:
		VertexM& operator*();								// reference to the element
		bool operator==(const Iterator& p) const;		// compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();							// move to next position
		Iterator& operator--();							// move to previous position
		friend class VertexMList;							// give NodeList access
	private:
		Node* v;										// pointer to the node
		Iterator(Node* u);								// create from node
	};
public:
	VertexMList();											// default constructor
	int size() const;									// list size
	bool empty() const;									// is the list empty?
	Iterator begin() const;								// beginning position
	Iterator end() const;								// (just beyond) last position
	void insertFront(const VertexM& e);					// insert at front
	void insertBack(const VertexM& e);						// insert at rear
	void insert(const Iterator& p, const VertexM& e);		// insert e before p
	void eraseFront();									// remove first
	void eraseBack();									// remove last
	void erase(const Iterator& p);						// remove p
private:												// data members
	int n;												// number of items
	Node* header;										// head-of-list sentinel
	Node* trailer;										// tail-of-list sentinel
};

VertexMList::Iterator::Iterator(Node* u)
{
	v = u;
}

VertexM& VertexMList::Iterator::operator*()
{
	return v->elem;
}

bool VertexMList::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

bool VertexMList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

VertexMList::Iterator& VertexMList::Iterator::operator++()
{
	v = v->next; return *this;
}

VertexMList::Iterator& VertexMList::Iterator::operator--()
{
	v = v->prev; return *this;
}

VertexMList::VertexMList()									//constructor
{
	n = 0;												// initially empty
	header = new Node;									// create sentinels
	trailer = new Node;
	header->next = trailer;								// have them point to each other
	trailer->prev = header;
}

int VertexMList::size() const								// list size
{
	return n;
}

bool VertexMList::empty() const							// is the list empty?
{
	return (n == 0);
}

VertexMList::Iterator VertexMList::begin() const				// begin position is first item
{
	return Iterator(header->next);
}

VertexMList::Iterator VertexMList::end() const				// end position is just beyond last
{
	return Iterator(trailer);
}

void VertexMList::insert(const VertexMList::Iterator& p, const VertexM& e) // insert e before p
{
	Node* w = p.v;										// insert e before p
	Node* u = w->prev;									// p’s predecessor
	Node* v = new Node;									// new node to insert
	v->elem = e;
	v->next = w; w->prev = v;							// link in v before w
	v->prev = u; u->next = v;							// link in v after u
	n++;												// one more element
}

void VertexMList::insertFront(const VertexM& e)				// insert at front
{
	insert(begin(), e);
}

void VertexMList::insertBack(const VertexM& e)				// insert at rear
{
	insert(end(), e);
}

void VertexMList::erase(const Iterator& p)					// remove p
{
	Node* v = p.v;										// node to remove
	Node* w = v->next;									// successor
	Node* u = v->prev;									// predecessor
	u->next = w; w->prev = u;							// unlink p
	delete v;											// delete this node
	n--;												// one fewer element
}

void VertexMList::eraseFront()								// remove first
{
	erase(begin());
}

void VertexMList::eraseBack()								// remove last
{
	erase(--end());
}
#endif 
