#include"Header.h"

rec::rec(point* i)
{
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
	setNn(8);
	p = new Point[8];
	this->p[0].X = x;
	this->p[0].Y = y;
	this->p[1].X = x + w;
	this->p[1].Y = y;
	this->p[2].X = x + w;
	this->p[2].Y = y + h;
	this->p[3].X = x;
	this->p[3].Y = y + h;
	this->ce.X = (this->p[0].X + p[1].X) / 2;
	this->ce.Y = (this->p[0].Y + p[3].Y) / 2;

	p[4] = p[0];
	p[5] = p[1];
	p[6] = p[2];
	p[7] = p[3];

	this->setT(0);
}



void rec::_turn(int o)
{
	while (1)
	{
		if (o < 360)
		{
			break;
		}
		else
		{
			o -= 360;
		}
	}

	point d[4];
	double hi = this->getT() + o;
	if (hi >= 360)
	{
		o = hi - 360;
		this->setT(0);
		p[0] = p[4];
		p[1] = p[5];
		p[2] = p[6];
		p[3] = p[7];
	}

	for (int f = 0; f < 4; f++)
	{
		d[f].setX(this->p[f].X - this->ce.X);
		d[f].setY(this->p[f].Y - this->ce.Y);
		d[f] = tur(d[f], o);
		p[f].X = d[f].getX() + this->ce.X;
		p[f].Y = d[f].getY() + this->ce.Y;
	}
	this->setT(o + this->getT());
}