#pragma once
#ifndef LISTTEMPLATE
#define LISTTEMPLATE
template<class Elem>
struct Node {										// a node of the list
	Elem elem;										// element value
	Node* prev;										// previous in list
	Node* next;										// next in list
};