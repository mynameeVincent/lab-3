#include"Header.h"

void users::drarec(rec& d, int yop)
{
	int x = d.p[0].X;
	int y = d.p[0].Y;
	int w = d.p[2].X - x;
	int h = d.p[2].Y - y;
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	HWND hWnd = GetConsoleWindow();
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	int r, b, g;
	d.pin.getpen(r, b, g);
	SolidBrush pen(Color(yop, r, b, g));

	graphics.FillRectangle(&pen, x, y, w, h);

	mio(gdiplusToken);
}

void users::werlds()
{
	cout << "\n\n   F1\n  hellp\n";
	cout << "\n\n\n   W,S\n up/doun\n";
	cout << "\n\n\n   D,A\nright/left\n";
	cout << "\n\n\n   E,Q\n  rotate\n";
	cout << "\n\n\n    Z\n  track\n";
	cout << "\n\n\n    C\n  color\n";
	cout << "\n\n\n    +\nnew shape\n";
	cout << "\n\n\n    -\ndel shape\n";
	cout << "\n\n\n   /,*\nbig/smol\n";
	cout << "\n\n\n   <-\n  write\n";
	cout << "\n\n\n  shif\n  read\n";
	cout << "\n\n\n\n\n";
}

void users::hope(int yu)
{
	SetCur(0, 0);
	cout << "\t\t\t\t\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9";
	SetCur(yu * 8 + 48, 0);
	SetColor(2);
	cout << yu << "\t\t\t\t\t\t\t\t\t\t";
	SetColor();
	Sleep(10);
	rec* paintBox = new rec(315, 0, 20, 700);
	(*paintBox).pin.setpen(150, 150, 150);
	drarec(*paintBox, 50);
	delete paintBox;

	paintBox = new rec(80, 20, 875, 1500);
	(*paintBox).pin.setpen(100, 100, 100);
	draw(*paintBox);
	delete paintBox;
}

void users::mainwind(int yu)
{
	werlds();
	hope(yu);
	rec* paintBox = new rec(80, 20, 875, 1500);
	(*paintBox).pin.setpen(100, 100, 100);
	draw(*paintBox);
	delete paintBox;

	paintBox = new rec(0, 20, 875, 80);
	(*paintBox).pin.setpen(150, 150, 150);
	drarec(*paintBox, 50);
	delete paintBox;
}

void users::colorset()
{
	rec* paintBox;
	SetCur(0, 0);
	Sleep(10);
	paintBox = new rec(0, 0, 900, 1600);
	(*paintBox).pin.setpen(50, 50, 50);
	drarec(*paintBox, 50);
	delete paintBox;
	paintBox = new rec(0, 0, 400, 200);
	(*paintBox).pin.setpen(12, 12, 12);
	drarec(*paintBox, 255);
	delete paintBox;
	SetCur(0, 0);
	SetColor(4);
	cout << "\n\tred";
	SetColor(2);
	cout << "\n\n        green";
	SetColor(1);
	cout << "\n       \n\tblwe";
	SetColor();
	SetCur(0, 0);
}

void users::congr()
{
	system("cls");
	SetCur(0, 0);
}

void users::PLUS()
{
	rec* paintBox;
	SetCur(0, 0);
	Sleep(10);
	paintBox = new rec(0, 0, 900, 1600);
	(*paintBox).pin.setpen(50, 50, 50);
	drarec(*paintBox, 50);
	delete paintBox;
	paintBox = new rec(0, 0, 400, 300);
	(*paintBox).pin.setpen(12, 12, 12);
	drarec(*paintBox, 255);
	delete paintBox;
	SetCur(0, 0);
	cout << "\n  0 - point \n       \n  1 - line \n       \n  2 - tritangle\n      \n  3 - rectangle\n        \n  9 - agregat\n      \n      \n        \n          \n";
	point om(160, 23);
	draw(om);

	line lm(145, 43, 165, 57);
	draw(lm);

	point a(150, 90);
	point b(160, 95);
	point c(160, 85);
	triangle tm(a, b, c);
	draw(tm);

	rec rl(150, 115, 10, 10);
	draw(rl);
}

void users::Pluas_agr()
{
	cout << "0  1  2  3  4  5  6  7  8  9\n";
}
void users::newname() 
{
	SetCur(0, 14);
	cout << "                                   \n";
	cout << "                                   \n";
	SetCur(0, 14);
}

void users::WTF()
{
	rec* paintBox;
	SetCur(1, 1);
	Sleep(10);
	paintBox = new rec(0, 0, 900, 1600);
	(*paintBox).pin.setpen(50, 50, 50);
	drarec(*paintBox, 50);
	delete paintBox;
	paintBox = new rec(0, 0, 200, 200);
	(*paintBox).pin.setpen(12, 12, 12);
	drarec(*paintBox, 255);
	delete paintBox;
	cout << "name:";
}
