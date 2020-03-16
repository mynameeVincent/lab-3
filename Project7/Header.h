#pragma once
#include<Windows.h>
#include<conio.h>
#include<gdiplus.h>
#include<iostream>
#include<vector>
#include<math.h>

using namespace Gdiplus;
using namespace std;
class basic			
{
	double turn;
	int Nn;
public:
	Point* p;
	Point ce;
	int getNn()
	{
		return Nn;
	}
	void setNn(int N)
	{
		this->Nn = N;
	}
	virtual void _draw(Pen& a, Graphics& graphics);
	virtual void _hide();
	virtual void _muve(int x, int y);
	virtual void _muv(int x);
	virtual void _turn(int x);
	double getT()
	{
		return turn;
	}
	void setT(double a)
	{
		turn = a;
	}
};

class point : public basic
{
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	point(int x = 0, int y = 0);
	point(const point& a);
	void operator = (const point& a);

	void _muve(int x, int y);
	void _turn(int o){}
};

class rec:public basic
{
public:
	rec(int x = 50, int y = 50, int h = 100, int w = 100);
	rec(point* i);	
};

class triangle : public basic
{
public:
	triangle(point p1, point p2, point p3);
};

class line : public basic
{
public:
	line(point p1, point p2);
	line(int x1, int y1, int x2, int y2);
};

class shape
{
public:
	void draw(basic& a, int r = 255, int b = 255, int g = 255);
	void hide(basic& a);
	void muveTO(basic& a, int x, int y);
	void muve(basic& a, int f);
	void rotate(basic& shap, int o);
};

class shap
{
protected:
	basic* f[10];
	int N;
	shape U;
	VOID ADD(basic& gg)
	{
		f[N] = &gg;
		N++;
	}
public:
	shap();
	int getN();
	void draw(int n);
	void plus_();
	void rotate_(int n, bool rorl);
	void hide_(int u);
	void muve_(int n);
};

void bla_bla_bla();
void mio(ULONG_PTR& gdiplusToken);
point tur(point y, double x);


class agr:public basic
{
protected:
	int M;
	basic** yo;
	void setM(int M);
public:
	void getM(int M);
	agr(basic** oop, int n);
	void _draw(Pen& a, Graphics& graphics) override;

	void _hide() override;
	void _muve(int x, int y) override;
	void _muv(int x) override;
	void _turn(int x) override;
};