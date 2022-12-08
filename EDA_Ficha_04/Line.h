#pragma once
#pragma once
#include <windows.h>
#include "Point.h"
#include <vector>
#include <stdio.h>
class Line {
private:
	Point pi, pf; // pi - Initial point, pf - Final point
public:
	Line(); // Default constructor
	Line(Point p1, Point p2);
	void Draw(HWND wndId, long color, std::vector<Point> pointList, int i); // Draw graphically a line between pi and pf
	double GetLength(); // Length of the line
};
