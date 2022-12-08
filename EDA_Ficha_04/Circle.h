#pragma once
#include <windows.h>
#include "Point.h"
class Circle {
private:
	Point center; // coordenadas do centro
	int radius; // raio do c�rculo
public:
	Circle(); // construtor por omiss�o
	Circle(Point c, int r);
	void Draw(HWND wndId, long color); // Desenha graficamente o circulo
	void Draw(HWND wndId, long color, char* text, long text_color);
	bool Contains(Point p); // verifica se o ponto est� dentro do circulo
};
