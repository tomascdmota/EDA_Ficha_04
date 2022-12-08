#include "Point.h"
#include <math.h>
#include <stdio.h>

Point::Point(){
	x = 0;
	y = 0;
}


Point::Point(int x0, int y0) {
	int x_coord, y_coord;
	x_coord = x0;
	y_coord = y0;

	SetX(x_coord);
	SetY(y_coord);
	GetX();
	GetY();
}

double Point::GetDistance(Point p2)
{
	double Dist = 0;
	Dist = sqrt(pow(this->x - p2.x, 2) + pow(this->y - p2.y, 2));
	printf("%d", Dist);
	return Dist;
}

