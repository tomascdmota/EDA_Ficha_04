#pragma once
#include <math.h>
class Point {
private:
	int x, y; // coordenadas do ponto
public:
	Point();// construtor por omiss�o
	Point(int x0, int y0); //construtor para atribui��o de novos valores
	void SetX(int new_x) { x = new_x; }; // nova coordenada X
	int GetX() { return x; }; // devolve a coordenada X
	void SetY(int new_y) { y = new_y; }; // nova coordenada Y
	int GetY() { return y; }; // devolve a coordenada Y
	double GetDistance(Point p2);
};