#pragma once
#include "Element.h"

class Node
{
private:
	Node* next;
	Element* elem;

public:
	Node(void) { next = NULL; }
	Node(Element* e) { elem = e; }
	~Node(void) {}

	void setNext(Node* n) { next = n; }
	Node* getNext() { return next; }
	Element* getElement() { return elem; }
};
