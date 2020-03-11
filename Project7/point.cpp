#include"Header.h"

int point::getX()
{
	return this->x;
}
int point::getY()
{
	return this->y;
}
void point::setX(int x)
{
	this->x = x;
}
void point::setY(int y)
{
	this->y = y;
}

point::point(int x, int y)
{
	ce.X = x;
	ce.Y = y;
	this->x = x;
	this->y = y;
}
point::point(const point& a)
{
	this->x = a.x;
	this->y = a.y;
}

void point :: operator = (const point& a)
{
	this->x = a.x;
	this->y = a.y;
}

void point::_muve(int x, int y)
{
	this->_hide();
	this->x = x;
	this->y = y;
}
void point :: _muv(int x) 
{
	switch (x)
	{
		case 0:
		{
			this->y += 5;
			break;
		}
		case 1:
		{
			this->y -= 5;
			break;
		}
		case 2:
		{
			this->x += 5;
			break;
		}
		case 3:
		{
			this->x -= 5;
			break;
		}
		default:
		{
			cout << "fatal error you can't muve point";
			break;
		}
	}
}

void point::_draw(Pen& a, Graphics& graphics)
{

	graphics.DrawLine(&a, this->x, this->y, this->x + 1, this->y + 1);
	graphics.DrawLine(&a, this->x + 1, this->y, this->x, this->y + 1);
}
void point::_hide()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 12, 12, 12));
	graphics.DrawLine(&pen, this->getX(), this->getY(), this->getX() + 1, this->getY() + 1);
	graphics.DrawLine(&pen, this->getX(), this->getY() + 1, this->getX() + 1, this->getY());
}

