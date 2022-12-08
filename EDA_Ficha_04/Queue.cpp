#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"



void Queue::put(Element * elem) {
	Node* newNode = new Node(elem);
	newNode->setNext(NULL);

	if (firstNode == NULL) { // Fila vazia
		firstNode = newNode;
	}
	else {
		lastNode->setNext(newNode);
	}

	lastNode = newNode;
}


Element* Queue::get() {

	if (isEmpty())  //Fila vazia
		return NULL;

	Node* aux = firstNode;
	Element* elem = aux->getElement();

	firstNode = aux->getNext();
	delete aux;
	return elem;
}


bool Queue::isEmpty()
{
	return firstNode == NULL;
}


Queue::~Queue(void)
{
	while (!isEmpty()) {
		delete get(); // elimina o elemento. O n� � eliminado pela fun��o get
	}
}


void Queue::printQueue() {
	Node* current = firstNode;
	printf("\n\n========= Queue =========\n");
	if (isEmpty()) printf(" Empty Queue");

	while (current != NULL) {
		current->getElement()->print();
		current = current->getNext();
	}
	printf("\n-------------------\n\n");
}
