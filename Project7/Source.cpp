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

void basic::_muv(int x)
{
	switch (x)
	{
	case 0:
	{
		for (int f = 0; f <= getNn() * 2; f++)
			this->p[f].Y += 5;
		break;
	}
	case 1:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].Y -= 5;
		break;
	}
	case 2:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].X += 5;
		break;
	}
	case 3:
	{
		for (int f = 0; f < getNn() * 2; f++)
			this->p[f].X -= 5;
		break;
	}
	default:
	{
		cout << "fatal error you can't muve point";
		break;
	}
	}
}