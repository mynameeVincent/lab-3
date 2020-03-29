#include"Header.h"

int point::getX()
{
	return this->p[0].X;
}
int point::getY()
{
	return this->p[0].Y;
}
void point::setX(int x)
{
	this->p[0].X = x;
}
void point::setY(int y)
{
	this->p[0].Y = y;
}

point::point(int x, int y)
{
	pin.setpen();
	p = new Point[2];
	setNn(1);
	ce.X = x;
	ce.Y = y;
	this->p[0].X = x;
	this->p[0].Y = y;
	this->p[1].X = x;
	this->p[1].Y = y;
}
point::point(const point& a)
{
	pin.setpen();
	p = new Point[1];
	setNn(1);
	this->p[0] = a.p[0];
}


void point::_muve(int x, int y)
{
	this->_hide();
	this->p[0].X = x;
	this->p[0].Y = y;
}

void point::_draw(Pen& a, Graphics& graphics)
{
	graphics.DrawRectangle(&a,p[0].X, p[0].Y, 1, 1);
}

void point::_hide()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen a(Color(255, 12, 12, 12));
	graphics.DrawRectangle(&a, p[0].X, p[0].Y, 1, 1);
}

void point :: operator = (const point& a)
{
	for (int f = 0; f < getNn(); f++)
		this->p[0] = a.p[0];
}