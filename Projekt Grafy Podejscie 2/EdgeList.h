#pragma once
#ifndef EDGELIST
#define EDGELIST
typedef int Elem;										// list base element type

struct Edge {
	Elem x;
};

class EdgeList {										//node-based list
private:
	struct Node {										// a node of the list
		Edge elem;										// element value
		Node* prev;										// previous in list
		Node* next;										// next in list
	};
public:
	class Iterator {									// an iterator for the list
	public:
		Edge& operator*();								// reference to the element
		bool operator==(const Iterator& p) const;		// compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();							// move to next position
		Iterator& operator--();							// move to previous position
		friend class EdgeList;							// give NodeList access
	private:
		Node* v;										// pointer to the node
		Iterator(Node* u);								// create from node
	};
public:
	EdgeList();											// default constructor
	int size() const;									// list size
	bool empty() const;									// is the list empty?
	Iterator begin() const;								// beginning position
	Iterator end() const;								// (just beyond) last position
	void insertFront(const Edge& e);					// insert at front
	void insertBack(const Edge& e);						// insert at rear
	void insert(const Iterator& p, const Edge& e);		// insert e before p
	void eraseFront();									// remove first
	void eraseBack();									// remove last
	void erase(const Iterator& p);						// remove p
private:												// data members
	int n;												// number of items
	Node* header;										// head-of-list sentinel
	Node* trailer;										// tail-of-list sentinel
};

EdgeList::Iterator::Iterator(Node* u)
{
	v = u;
}

Edge& EdgeList::Iterator::operator*()
{
	return v->elem;
}

bool EdgeList::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

bool EdgeList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

EdgeList::Iterator& EdgeList::Iterator::operator++()
{
	v = v->next; return *this;
}

EdgeList::Iterator& EdgeList::Iterator::operator--()
{
	v = v->prev; return *this;
}

EdgeList::EdgeList()									//constructor
{
	n = 0;												// initially empty
	header = new Node;									// create sentinels
	trailer = new Node;
	header->next = trailer;								// have them point to each other
	trailer->prev = header;
}

int EdgeList::size() const								// list size
{
	return n;
}

bool EdgeList::empty() const							// is the list empty?
{
	return (n == 0);
}

EdgeList::Iterator EdgeList::begin() const				// begin position is first item
{
	return Iterator(header->next);
}

EdgeList::Iterator EdgeList::end() const				// end position is just beyond last
{
	return Iterator(trailer);
}

void EdgeList::insert(const EdgeList::Iterator& p, const Edge& e) // insert e before p
{
	Node* w = p.v;										// insert e before p
	Node* u = w->prev;									// p’s predecessor
	Node* v = new Node;									// new node to insert
	v->elem = e;
	v->next = w; w->prev = v;							// link in v before w
	v->prev = u; u->next = v;							// link in v after u
	n++;												// one more element
}

void EdgeList::insertFront(const Edge& e)				// insert at front
{
	insert(begin(), e);
}

void EdgeList::insertBack(const Edge& e)				// insert at rear
{
	insert(end(), e);
}

void EdgeList::erase(const Iterator& p)					// remove p
{
	Node* v = p.v;										// node to remove
	Node* w = v->next;									// successor
	Node* u = v->prev;									// predecessor
	u->next = w; w->prev = u;							// unlink p
	delete v;											// delete this node
	n--;												// one fewer element
}

void EdgeList::eraseFront()								// remove first
{
	erase(begin());
}

void EdgeList::eraseBack()								// remove last
{
	erase(--end());
}
#endif 
