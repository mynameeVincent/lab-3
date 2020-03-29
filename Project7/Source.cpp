#include"Header.h"

void basic::_hide()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 12, 12, 12));
	graphics.DrawPolygon(&pen, this->p, this->getNn());
}

void basic::_draw(Pen& a, Graphics& graphics)
{
	graphics.DrawPolygon(&a, p, getNn());
}

void basic::_muve(int x, int y)
{
	int x1, y1;
	this->_hide();

	x1 = x - ce.X;
	y1 = y - ce.Y;

	ce.X = x;
	ce.Y = y;
	for (int f = 0; f < getNn(); f++)
	{
		p[f].X += x1;
		p[f].Y += y1;
		p[f + getNn()] = p[f];
	}
}

void basic::_muv(int x, bool sl)
{
	if(sl)
		PLUS(x);
	switch (x)
	{
	case 0:
	{
		for (int f = 0; f <= getNn() * 2; f++)
			this->p[f].Y += 5;
		ce.Y += 5;
		break;
	}
	case 1:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].Y -= 5;
		ce.Y -= 5;
		break;
	}
	case 2:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].X += 5;
		ce.X += 5;
		break;
	}
	case 3:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].X -= 5;
		ce.X -= 5;
		break;
	}
	default:
	{
		cout << "fatal error you can't muve point";
		break;
	}
	}
	if(sl)
		TALE();
}

void basic::setNn(int N)
{
	this->Nn = N;
}

bool basic::may_i_muve(int ko)
{
	for (int f = 0; f < getNn(); f++)
	{
		switch (ko)
		{
		case 1:
		{
			if (p[f].X < 86)
				return 0;
			break;
		}
		case 2:
		{
			if (p[f].Y < 30)
				return 0;
			break;
		}
		case 3:
		{
			if (p[f].X > 1570)
				return 0;
			break;
		}
		case 4:
		{
			if (p[f].Y > 880)
				return 0;
			break;
		}
		}
	}
	return 1;
}

bool basic :: may_i_rotate()
{
	for (int f = 0; f < getNn(); f++)
	{
		if (p[f].X <= 90 || p[f].Y <= 30 || p[f].X >= 1570 || p[f].Y >= 880)
			return 0;
	}
	return 1;
}

void basic::setT(double a)
{
	turn = a;
}

double basic::getT()
{
	return turn;
}

int basic::getNn()
{
	return Nn;
}

void basic::PLUS(int now)
{
	if (last != now)
	{
		io.push_back(this->ce);
		last = now;
	}
	DROW();
}

void basic::TALE()
{
	int r, b, g;
	this->pin.getpen(r, b, g);
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, r, b, g));
	graphics.DrawLine(&pen, io[io.size() - 1].X, io[io.size() - 1].Y, ce.X, ce.Y);
}

void basic::DROW()
{
	int r, b, g;
	this->pin.getpen(r, b, g);
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, r, b, g));
	for (int f = 1; f < io.size(); f++)
	{
		graphics.DrawLine(&pen, io[f - 1].X, io[f - 1].Y, io[f].X, io[f].Y);
	}
}

void basic::HIDE()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 12, 12, 12));
	for (int f = 1; f < io.size(); f++)
	{
		graphics.DrawLine(&pen, io[f - 1].X, io[f - 1].Y, io[f].X, io[f].Y);
	}
	graphics.DrawLine(&pen, io[io.size() - 1].X, io[io.size() - 1].Y, ce.X, ce.Y);
	io.clear();
}

double basic::Getmach()
{
	return this->mach;
}



bool basic::mat_i_become_big()
{
	bool ui = 1;
	Point* iom = new Point{ *p };

	for (int f = 0; f < this->Nn; f++)
	{
		double x = this->p[f].X, y = this->p[f].Y;
		x = x - ce.X;
		y = y - ce.Y;
		x *= Getmach();
		y *= Getmach();
		p[f].X = ce.X + x;
		p[f].Y = ce.Y + y;
		if (p[f].X <= 80 || p[f].X >= 1580 || p[f].Y <= 20 || p[f].Y >= 895)
		{
			ui = 0;
			break;
		}
	}
	for (int f = 0; f < getNn(); f++)
	{
		p[f] = iom[f];
	}
	return ui;
}


void basic::counter_sup()
{
	while (1)
	{
		if (getT() >= 360)
		{
			setT(getT() - 360);
		}
		else
		{
			break;
		}
	}
}





void basic::changes_sup(int ox, float am)
{
	bool ui = 1;

	for (int f = 0; f < this->Nn; f++)
	{
		double x = this->p[f].X, y = this->p[f].Y;
		x = x - ce.X;
		y = y - ce.Y;
		x *= Getmach();
		y *= Getmach();
		p[f].X = ce.X + x;
		p[f].Y = ce.Y + y;
		if ((p[f].X <= 80 || p[f].X >= 1580 || p[f].Y <= 20 || p[f].Y >= 895 || ce.X + x < 0 || ce.Y + y < 0) && am >= 1)
		{
			{
				if (am != 1)
				{
					this->_turn(0, 0.9);																	//neeed in me
				}
				if (ox != 0)
					this->_turn(-ox, 1);
			}
		}
	}

}


void basic::_turn(int o, float am)
{

	setT(getT() + o);
	this->SetMach(Getmach() * am);
	this->counter_sup();
	this->rotate_sup();
	this->changes_sup(o, am);
}

void basic::rotate_sup()
{
	point *D=new point;
	for (int f = 0; f < getNn(); f++)
	{
		(*D).setX(this->p[f + getNn()].X - this->ce.X);
		(*D).setY(this->p[f + getNn()].Y - this->ce.Y);
		*D = tur(*D, getT());
		p[f].X = (*D).getX() + this->ce.X;
		p[f].Y = (*D).getY() + this->ce.Y;
	}
	delete D;
}


basic& basic::copy()
{
	basic* mi = new basic;
	(*mi).ce = this->ce;
	(*mi).Nn = this->Nn;
	(*mi).turn = this->turn;
	(*mi).mach = this->mach;
	this->last = 0;
	this->pin.setpen();
	(*mi).p = new Point[getNn() * 2];
	for (int f = 0; f < getNn(); f++)
	{
		(*mi).p[f] = this->p[f];
		(*mi).p[f + getNn()] = this->p[f + getNn()];
	}
	return *mi;
}

basic& copy(basic& a)
{
	return a.copy();
}

void basic::SetMach(double mach)
{
	this->mach = mach;
}