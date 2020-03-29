#include"Header.h"

rec::rec(point* i)
{
	pin.setpen(200, 0, 0);

	pin.setpen();
	setNn(4);
	p = new Point[8];
	this->p[0].X = i[0].getX();
	this->p[0].Y = i[0].getY();

	this->p[1].X = i[1].getX();
	this->p[1].Y = i[1].getY();

	this->p[2].X = i[2].getX();
	this->p[2].Y = i[2].getY();

	this->p[3].X = i[3].getX();
	this->p[3].Y = i[3].getY();

	p[4] = p[0];
	p[5] = p[1];
	p[6] = p[2];
	p[7] = p[3];

	ce.X = (p[0].X + p[3].X) / 2;
	ce.Y = (p[0].Y + p[3].Y) / 2;

	this->setT(0);
}

rec::rec(int x, int y, int h, int w)
{
	pin.setpen();

	setNn(4);
	p = new Point[8];
	this->p[0].X = x;
	this->p[0].Y = y;
	this->p[1].X = x + w;
	this->p[1].Y = y;
	this->p[2].X = x + w;
	this->p[2].Y = y + h;
	this->p[3].X = x;
	this->p[3].Y = y + h;
	this->ce.X = (this->p[0].X + this->p[1].X + this->p[2].X + this->p[3].X) / 4;
	this->ce.Y = (this->p[0].Y + this->p[1].Y + this->p[2].Y + this->p[3].Y) / 4;

	p[4] = p[0];
	p[5] = p[1];
	p[6] = p[2];
	p[7] = p[3];

	this->setT(0);
}
