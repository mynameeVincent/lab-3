#include"Header.h"

line::line(point p1, point p2)
{
	this->p[0].X = p1.getX();
	this->p[0].Y = p1.getY();
	this->p[1].X = p2.getX();
	this->p[2].Y = p2.getY();
	p[2] = p[0];
	p[3] = p[1];
}
line::line(int x1, int y1, int x2, int y2)
{
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
void line::_muve(int x, int y)
{
	this->_hide();
	int s, ss;
	s = x - ce.X;
	ss = y - ce.Y;
	this->p[0].X = s + this->p[0].X;
	this->p[0].Y = ss + this->p[0].Y;
	this->p[1].X = s + this->p[1].X;
	this->p[1].Y = ss + this->p[1].Y;
	ce.X = x;
	ce.Y = y;
	p[2] = p[0];
	p[3] = p[1];
}
void line ::_muv(int x)
{
	switch (x)
	{
	case 0:
	{
		ce.Y += 5;
		this->p[0].Y += 5;
		this->p[1].Y += 5;
		this->p[2].Y += 5;
		this->p[3].Y += 5;
		break;
	}
	case 1:
	{
		ce.Y -= 5;
		this->p[0].Y -= 5;
		this->p[1].Y -= 5;
		this->p[2].Y -= 5;
		this->p[3].Y -= 5;
		break;
	}
	case 2:
	{
		ce.X += 5;
		this->p[0].X += 5;
		this->p[1].X += 5;
		this->p[2].X += 5;
		this->p[3].X += 5;
		break;
	}
	case 3:
	{
		ce.X -= 5;
		this->p[0].X += 5;
		this->p[1].X += 5;
		this->p[2].X += 5;
		this->p[3].X += 5;
		break;
	}
	default:
	{
		cout << "fatal error you can't muve line";
		break;
	}
	}
	p[2] = p[0];
	p[3] = p[1];
}

void line::_hide()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 12, 12, 12));
	graphics.DrawLine(&pen, p[0].X, p[0].Y, p[1].X, p[1].Y);
}
void line::_draw(Pen& a, Graphics& graphics)
{
	graphics.DrawLine(&a, this->p[0].X, this->p[0].Y, this->p[1].X, this->p[1].Y);
}


void line :: _turn(int o)
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
	point d[2];
	double hi = this->getT() + o;
	if (hi >= 360)
	{
		o = hi - 360;
		this->setT(0);
		p[0] = p[2];
		p[1] = p[3];
	}
	for (int f = 0; f < 2; f++)
	{
		d[f].setX(this->p[f].X - this->ce.X);
		d[f].setY(this->p[f].Y - this->ce.Y);
		d[f] = tur(d[f], o);
		p[f].X = d[f].getX() + this->ce.X;
		p[f].Y = d[f].getY() + this->ce.Y;
	}
	this->setT(o + this->getT());
}