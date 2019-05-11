#pragma once
#ifndef EDGEMLIST
#define EDGEMLIST
#include"VertexMList.h"
typedef int Elem;										// list base element type


struct EdgeM {
	Elem x;
	VertexM* vertex[2];
	EdgeM* position;//zmienic na EdgeList::Iterator* position;!!!!
};

class EdgeMList {										//node-based list
private:
	struct Node {										// a node of the list
		EdgeM elem;										// element value
		Node* prev;										// previous in list
		Node* next;										// next in list
	};
public:
	class Iterator {									// an iterator for the list
	public:
		EdgeM& operator*();								// reference to the element
		bool operator==(const Iterator& p) const;		// compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();							// move to next position
		Iterator& operator--();							// move to previous position
		friend class EdgeMList;							// give EdgeList access
	private:
		Node* v;										// pointer to the node
		Iterator(Node* u);								// create from node
	};
public:
	EdgeMList();											// default constructor
	int size() const;									// list size
	bool empty() const;									// is the list empty?
	Iterator begin() const;								// beginning position
	Iterator end() const;								// (just beyond) last position
	void insertFront(const EdgeM& e);					// insert at front
	void insertBack(const EdgeM& e);						// insert at rear
	void insert(const Iterator& p, const EdgeM& e);		// insert e before p
	void eraseFront();									// remove first
	void eraseBack();									// remove last
	void erase(const Iterator& p);						// remove p
private:												// data members
	int n;												// number of items
	Node* header;										// head-of-list sentinel
	Node* trailer;										// tail-of-list sentinel
};

EdgeMList::Iterator::Iterator(Node* u)
{
	v = u;
}

EdgeM& EdgeMList::Iterator::operator*()
{
	return v->elem;
}

bool EdgeMList::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

bool EdgeMList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

EdgeMList::Iterator& EdgeMList::Iterator::operator++()
{
	v = v->next; return *this;
}

EdgeMList::Iterator& EdgeMList::Iterator::operator--()
{
	v = v->prev; return *this;
}

EdgeMList::EdgeMList()									//constructor
{
	n = 0;												// initially empty
	header = new Node;									// create sentinels
	trailer = new Node;
	header->next = trailer;								// have them point to each other
	trailer->prev = header;
}

int EdgeMList::size() const								// list size
{
	return n;
}

bool EdgeMList::empty() const							// is the list empty?
{
	return (n == 0);
}

EdgeMList::Iterator EdgeMList::begin() const				// begin position is first item
{
	return Iterator(header->next);
}

EdgeMList::Iterator EdgeMList::end() const				// end position is just beyond last
{
	return Iterator(trailer);
}

void EdgeMList::insert(const EdgeMList::Iterator& p, const EdgeM& e) // insert e before p
{
	Node* w = p.v;										// insert e before p
	Node* u = w->prev;									// p’s predecessor
	Node* v = new Node;									// new node to insert
	v->elem = e;
	v->next = w; w->prev = v;							// link in v before w
	v->prev = u; u->next = v;							// link in v after u
	n++;												// one more element
}

void EdgeMList::insertFront(const EdgeM& e)				// insert at front
{
	insert(begin(), e);
}

void EdgeMList::insertBack(const EdgeM& e)				// insert at rear
{
	insert(end(), e);
}

void EdgeMList::erase(const Iterator& p)					// remove p
{
	Node* v = p.v;										// node to remove
	Node* w = v->next;									// successor
	Node* u = v->prev;									// predecessor
	u->next = w; w->prev = u;							// unlink p
	delete v;											// delete this node
	n--;												// one fewer element
}

void EdgeMList::eraseFront()								// remove first
{
	erase(begin());
}

void EdgeMList::eraseBack()								// remove last
{
	erase(--end());
}
#endif 
