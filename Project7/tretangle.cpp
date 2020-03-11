#include"Header.h"




triangle::triangle(point p1, point p2, point p3)
{
	this->p[0].X = p1.getX();
	this->p[0].Y = p1.getY();
	this->p[1].X = p2.getX();
	this->p[1].Y = p2.getY();
	this->p[2].X = p3.getX();
	this->p[2].Y = p3.getY();

	p[3] = p[0];
	p[4] = p[1];
	p[5] = p[2];

	this->setT(0);
}
void triangle::_muve(int x, int y)
{
	int x1, y1;
	this->_hide();
	x1 = x - p[0].X;
	y1 = y - p[0].Y;
	p[0].X = x;
	p[0].Y = y;
	p[1].X += x1;
	p[1].Y += y1;
	p[2].X += x1;
	p[2].Y += y1;

	p[3] = p[0];
	p[4] = p[1];
	p[5] = p[2];
}


void triangle::_muv(int x)
{
	switch (x)
	{
	case 0:
	{
		p[0].Y += 5;
		p[1].Y += 5;
		p[2].Y += 5;
		break;
	}
	case 1:
	{
		p[0].Y -= 5;
		p[1].Y -= 5;
		p[2].Y -= 5;
		break;
	}
	case 2:
	{
		p[0].X += 5;
		p[1].X += 5;
		p[2].X += 5;
		break;
	}
	case 3:
	{
		p[0].X -= 5;
		p[1].X -= 5;
		p[2].X -= 5;
		break;
	}
	default:
	{
		cout << "fatal error you can't muve triangle";
		break;
	}
	}
	p[3] = p[0];
	p[4] = p[1];
	p[5] = p[2];
}
void triangle::_hide()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 12, 12, 12));
	graphics.DrawPolygon(&pen, p, 3);
}
void triangle::_draw(Pen& a, Graphics& graphics)
{
	graphics.DrawPolygon(&a, p, 3);
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