#include"Header.h"

void draw(basic& a)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	int r, b, g;
	a.pin.getpen(r, b, g);
	Pen pen(Color(255, r, b, g));

	a._draw(pen, graphics);

	mio(gdiplusToken);
}

void hide(basic& a)
{
	a._hide();
}

void muveTO(basic& a, int x, int y)
{
	a._muve(x, y);
}

void muve(basic& a, int f, bool sl)
{
	hide(a);
	a._muv(f,sl);
	draw(a);
}


bool maybe(basic& gg)
{
	return gg.mat_i_become_big();
}

void change_color(basic& gg)
{
	gg.pin.chengecol();
}

void SetCur(int x, int y)
{
	COORD position = { x,y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(text));
}

