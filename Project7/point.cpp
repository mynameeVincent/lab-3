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
	p = new Point[4];
	setNn(4);
	ce.X = x;
	ce.Y = y;
	this->p[0].X = x;
	this->p[0].Y = y;
	this->p[1].X = x + 1;
	this->p[1].Y = y;
	this->p[2].X = x + 1;
	this->p[2].Y = y + 1;
	this->p[3].X = x;
	this->p[3].Y = y + 1;
}
point::point(const point& a)
{
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


void point :: operator = (const point& a)
{
	for (int f = 0; f < getNn(); f++)
		this->p[0] = a.p[0];
}