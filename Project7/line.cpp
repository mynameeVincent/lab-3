#include"Header.h"

line::line(point p1, point p2)
{
	pin.setpen();
	setNn(2);
	p = new Point[4];
	this->p[0].X = p1.getX();
	this->p[0].Y = p1.getY();
	this->p[1].X = p2.getX();
	this->p[2].Y = p2.getY();
	p[2] = p[0];
	p[3] = p[1];
}

line::line(int x1, int y1, int x2, int y2)
{
	pin.setpen();
	setNn(2);
	p = new Point[4];
	this->p[0].X = x1;;
	this->p[0].Y = y1;
	this->p[1].X = x2;
	this->p[1].Y = y2;
	this->ce.X = (x1 + x2) / 2;
	this->ce.Y = (y1 + y2) / 2;
	this->setT(0);
	p[2] = p[0];
	p[3] = p[1];

}
