#include"Header.h"

triangle::triangle(point p1, point p2, point p3)
{
	setNn(3);
	p = new Point[6];
	this->p[0].X = p1.getX();
	this->p[0].Y = p1.getY();
	this->p[1].X = p2.getX();
	this->p[1].Y = p2.getY();
	this->p[2].X = p3.getX();
	this->p[2].Y = p3.getY();
	ce.X = (p[0].X + p[1].X + p[2].X) / 3;
	ce.Y = (p[0].Y + p[1].Y + p[2].Y) / 3;

	p[3] = p[0];
	p[4] = p[1];
	p[5] = p[2];

	this->setT(0);
}
