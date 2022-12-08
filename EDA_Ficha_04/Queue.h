#pragma once
#include "Element.h"
#include "Node.h"

class Queue {

private:

    Node* firstNode;	// apontador para o primeiro n� da fila
    Node* lastNode;	// apontador para o �ltimo n� da fila

public:
    Queue() { firstNode = NULL; }

    ~Queue();

    void put(Element* elem);

    Element* get();

    bool isEmpty();

    void printQueue();
};