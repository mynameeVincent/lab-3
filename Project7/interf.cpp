#include"Header.h"


void shape :: draw(basic& a, int r, int b, int g)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);

	Graphics graphics(hdc);

	Pen pen(Color(255, r, b, g));

	a._draw(pen, graphics);

	mio(gdiplusToken);
}

void shape::hide(basic& a)
{
	a._hide();
}

void shape::muveTO(basic& a, int x, int y)
{
	a._muve(x, y);
}

void shape :: muve(basic& a, int f)
{
	hide(a);
	a._muv(f);
	draw(a);
}

void shape::rotate(basic2& shap, int o)
{
	shap._turn(o);
}