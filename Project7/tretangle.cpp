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





void triangle::_turn(int o)
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

	point d[3];
	double hi = this->getT() + o;
	if (hi >= 360)
	{
		o = hi - 360;
		this->setT(0);
		p[1] = p[4];
		p[2] = p[5];
	}

	for (int f = 1; f < 3; f++)
	{
		d[f].setX(this->p[f].X - this->p[0].X);
		d[f].setY(this->p[f].Y - this->p[0].Y);
		d[f] = tur(d[f], o);
		p[f].X = d[f].getX() + this->p[0].X;
		p[f].Y = d[f].getY() + this->p[0].Y;
	}
	this->setT(o + this->getT());
}