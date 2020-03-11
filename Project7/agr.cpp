#include"Header.h"
void agr :: setM(int M)
{
	this->M = M;
}
void agr::getM(int M)
{
	this->M = M;
}
agr::agr(basic** oop, int n)
{
	for (int f = 0; f < n; f++)
	{
		this->ce.X += oop[f]->ce.X;
		this->ce.Y += oop[f]->ce.Y;
	}

	yo = new basic * [n];
	this->M = n;
	ce.X /= M;
	ce.Y /= M;
	yo = oop;
}
void agr::_draw(Pen& a, Graphics& graphics)
{
	shape I;
	for (int f = 0; f < M; f++)
	{
		I.draw(*yo[f], 0, 0, 255);
	}
}
void agr::_hide()
{
	for (int f = 0; f < M; f++)
	{
		yo[f]->_hide();
	}
}
void agr::_muve(int x, int y)
{
	for (int f = 0; f < M; f++)
	{
		yo[f]->_muve(x, y);
	}
}
void agr::_muv(int x)
{
	for (int f = 0; f < M; f++)
	{
		yo[f]->_muv(x);
	}
}