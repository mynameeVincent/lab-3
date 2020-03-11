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
public:
	virtual void _draw(Pen& a, Graphics& graphics) = 0;
	virtual void _hide() = 0;
	virtual void _muve(int x, int y) = 0;
	virtual void _muv(int x) = 0;
};

class basic2
{
	double turn;
public:
	virtual void _turn(int x) = 0;
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
protected:
	int x;
	int y;
public:
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	point(int x = 0, int y = 0);
	point(const point& a);
	void operator = (const point& a);
	void _muve(int x, int y);
	void _muv(int x);
	void _draw(Pen& a, Graphics& graphics);
	virtual void _hide();
};

class rec : public point, public basic2
{
protected:
	Point p[8];
	Point ce;
public:
	rec(int x = 50, int y = 50, int h = 100, int w = 100);
	rec(point* i);	
	void _muve(int x, int y);
	void _muv(int x);
	void _hide();
	void _draw(Pen& a, Graphics& graphics);
	void _turn(int o);
};

class triangle : public point, public basic2
{
protected:
	Point p[6];
public:
	triangle(point p1, point p2, point p3);
	void _muve(int x, int y);
	void _muv(int x);
	void _hide();
	void _draw(Pen& a, Graphics& graphics);
	void _turn(int o);
};

class line : public point, public basic2
{
protected:
	Point p[4], ce;
public:
	line(point p1, point p2);
	line(int x1, int y1, int x2, int y2);
	void _muve(int x, int y);
	void _muv(int x);
	void _hide();
	void _draw(Pen& a, Graphics& graphics);
	void _turn(int o);
};

class shape
{
public:
	void draw(basic& a, int r = 255, int b = 255, int g = 255);
	void hide(basic& a);
	void muveTO(basic& a, int x, int y);
	void muve(basic& a, int f);
	void rotate(basic2& shap, int o);
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
	void hide_(int u);
	void muve_(int n);
};

void bla_bla_bla();
void mio(ULONG_PTR& gdiplusToken);
point tur(point y, double x);


class agr:public basic, public basic2
{
protected:
	int M;
	basic** yo;
	void setM(int M)
	{
		this->M = M;
	}
public:
	void getM(int M)
	{
		this->M = M;
	}
	agr(basic **oop,int n)
	{
		yo = new basic*[n];
		this->M = n;
		yo = oop;
	}
	void _draw(Pen& a, Graphics& graphics) override
	{
		shape I;
		for (int f = 0; f < M; f++)
		{
			I.draw(*yo[f], 0, 0, 255);
		}
	}

	void _hide() override
	{
		for (int f = 0; f < M; f++)
		{
			yo[f]->_hide();
		}
	}
	void _muve(int x, int y) override
	{
		for (int f = 0; f < M; f++)
		{
			yo[f]->_muve(x,y);
		}
	}
	void _muv(int x) override
	{
		for (int f = 0; f < M; f++)
		{
			yo[f]->_muv(x);
		}
	}
	void _turn(int x) override
	{

	}
};