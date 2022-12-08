#include"Circle.h"

Circle::Circle(Point c, int r) {
	center = c;
	radius = r;
}


void Circle::Draw(HWND wndId, long color)
{
	if (wndId != NULL)
	{
		HDC DrawHDC = GetDC(wndId);
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 10, color);
		HPEN hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush = CreateSolidBrush(color);;
		Ellipse(DrawHDC, center.GetX() - radius, center.GetY() + radius,
			center.GetX() + radius, center.GetY() - radius);
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(wndId, DrawHDC);
	}
}

void Circle::Draw(HWND wndId, long color, char* text, long text_color)
{
	if (wndId != NULL)
	{
		HDC DrawHDC = GetDC(wndId);
		// penstyle, width, color
		HPEN hNPen = CreatePen(PS_SOLID, 2, color);
		HPEN hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
		HBRUSH hOldBrush;
		HBRUSH hNewBrush;
		hNewBrush = CreateSolidBrush(color);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
		Ellipse(DrawHDC, center.GetX() - radius, center.GetY() + radius,
			center.GetX() + radius, center.GetY() - radius);
		SetBkMode(DrawHDC, TRANSPARENT);
		SetTextColor(DrawHDC, text_color);
		SetTextAlign(DrawHDC, TA_CENTER | TA_BASELINE);
		TextOut(DrawHDC, center.GetX(), center.GetY() + 3, text, strlen(text));
		DeleteObject(SelectObject(DrawHDC, hOPen));
		DeleteObject(SelectObject(DrawHDC, hOldBrush));
		ReleaseDC(wndId, DrawHDC);
	}
}





bool Circle::Contains(Point p) { //Um ponto está dentro de um circle quando a distancia ao
	if (center.GetDistance(p) < radius) return true; //Compara com a this
	else return false;
};