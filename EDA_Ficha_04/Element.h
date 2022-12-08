#pragma once
#include <stdio.h>
#include <stdlib.h>

class Element
{
private:
	int data;
public:
	Element() { data = 0; };
	Element(int d) { data = d; }

	int get() { return data; }
	int set(int d) { data = d; }
	void read() {
		printf("\n\nElement value: ");
		scanf("%d", &data);
	}

	void print() { printf(" %d ", data); }
};