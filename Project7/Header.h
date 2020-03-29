#pragma once

#include<Windows.h>
#include<conio.h>
#include<gdiplus.h>
#include<iostream>
#include<vector>
#include<math.h>

using namespace Gdiplus;
using namespace std;

class pen																//color
{
	int r, b, g;														//red blue green
public:												
	void getpen(int& r, int& b, int& g);								//get color									
	void setpen(int r = 255, int b = 255, int g = 255);					//set color				
	pen(int r = 255, int b = 255, int g = 255);							//const color
	int ceng_sup();
	void chengecol();
};

class basic;



class basic																//basic shape class
{
	double turn = 0;														//turn angle
	double mach = 1;
	int Nn;																//point quantity
	
	vector<Point> io;
	int last;

public:
	pen pin;															//color
	Point* p;															//point arr
	Point ce;															//centre point
	

	void PLUS(int now);

	void TALE();

	void DROW();
	
	void HIDE();

	int getNn();														//get quantity
																		
	void setNn(int N);													//set quatity
																		
	virtual void _draw(Pen& a, Graphics& graphics);						//draw shape
																		 
	virtual void _hide();												//hide shape
																		
	virtual void _muve(int x, int y);									//muveTO shape
																		
	virtual void _muv(int x, bool sl);											//muve shape
																		
	virtual bool may_i_muve(int ko);									//rotate shape

	virtual bool may_i_rotate();

	virtual bool mat_i_become_big();

	void changes_sup(int x, float am);

	void rotate_sup();

	void counter_sup();

	virtual void _turn(int x,float am);
																		//get angle
	double getT();
																		//set angle
	void setT(double a);
	
	double Getmach();

	void SetMach(double mach);


	//test
	//basic(basic& tt);

	//basic();

	basic& copy();

};


class point : public basic												//point class
{
public:
																		//get X
	int getX();
																		//get Y
	int getY();
																		//set X
	void setX(int x);
																		//set Y
	void setY(int y);
																		//const point 
	point(int x = 0, int y = 0);
																		//copy const point
	point(const point& a);
																		//==
	void operator = (const point& a);
																		//draw
	void _draw(Pen& a, Graphics& graphics);
																		//muve
	void _hide();

	void _muve(int x, int y);
};
																		//rectangle
class rec:public basic
{
public:
																		//const
	rec(int x = 50, int y = 50, int h = 100, int w = 100);
	rec(point* i);	
};
																		//tritangle
class triangle : public basic
{
public:
																		//const
	triangle(point p1, point p2, point p3);
};
																		//line
class line : public basic
{
public:
																		//const
	line(point p1, point p2);
	line(int x1, int y1, int x2, int y2);
};
																		//agregat
class agr:public basic
{
protected:
	int M;																//shapes quatity
	basic** yo;															//shapes
	void setM(int M);													//setM 
public:
	int getM();
	agr(basic** oop, int n);
	void _draw(Pen& a, Graphics& graphics) override;
	void _hide() override;
	bool may_i_muve(int x) override;
	bool may_i_rotate();
	void _muve(int x, int y) override;
	void _muv(int x,bool sl) override;
	

	//test

//	void rotate_sup_sup();

	virtual bool mat_i_become_big();
	
	void changes_sup(float am);
	
	void rotate_sup(int x);
	void _turn(int x, float am) override;


	bool may_i_rot();
};




void bla_bla_bla();
void mio(ULONG_PTR& gdiplusToken);
point tur(point y, double x);



void draw(basic& a);
void hide(basic& a);
void muveTO(basic& a, int x, int y);
void muve(basic& a, int f,bool sl);
bool maybe(basic& gg);
basic& copy(basic& a);
void change_color(basic& gg);
void SetCur(int x, int y);
void SetColor(int text = 15);


class users
{
public:
	void drarec(rec& d, int yop = 255);
	void werlds();
	void mainwind(int yu);
	void colorset();
	void hope(int yu);
	void congr();
	void PLUS();
	void Pluas_agr();
	void newname();
	void WTF();

};


class shape
{
protected:
	basic* f[10];
	int N;
	VOID ADD(basic& gg);
public:
	shape();
	int getN();
	void setN(int N);

	void draw_(int n);
	void plus_();
	void rotate_(int n, bool rorl);

	void hide_(int u);
	void muve_(int n, char step, bool sl);
	void compil_sup();
	void compil();

	void WTF(string t);
	void RFF(string t);
};

