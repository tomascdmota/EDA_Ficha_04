#include"Line.h"
#include<stdio.h>
#include <iostream>
#include <vector>

Line::Line() {
}

Line::Line(Point p1, Point p2)
{
	p1 = Point(pi);
	p2 = Point(pf);
}


void Line::Draw(HWND wndId, long color, std::vector<Point> pointList, int i)
{
		if (wndId != NULL)
		{


			HPEN hOPen;
			// penstyle, width, color
			HPEN hNPen = CreatePen(PS_SOLID, 2, color);
			HDC DrawHDC = GetDC(wndId);
			hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
			// starting point of line
			MoveToEx(DrawHDC, pointList[i].GetX(), pointList[i].GetY(), NULL);
			// ending point of line
			LineTo(DrawHDC, pointList[i+1].GetX(), pointList[i+1].GetY());
			DeleteObject(SelectObject(DrawHDC, hOPen));
			ReleaseDC(wndId, DrawHDC);
	}
}

double Line::GetLength()
{
	double Dist = 0;
	Dist = sqrt(pow(this->pi.GetX() - pf.GetX(), 2) + pow(this->pi.GetY() - pf.GetY(), 2));
	return Dist;
}
