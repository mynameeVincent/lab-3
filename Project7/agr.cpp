#include"Header.h"

void agr :: setM(int M)
{
	this->M = M;
}
int agr::getM()
{
	return this->M;
}
agr::agr(basic** oop, int n)
{
	pin.setpen();
	int r, b, g;
	pin.getpen(r, b, g);
	for (int f = 0; f < n; f++)
	{
		this->ce.X += oop[f]->ce.X;
		this->ce.Y += oop[f]->ce.Y;
		oop[f]->pin.setpen(r, b, g);
	}

	yo = new basic * [n];
	this->M = n;
	ce.X /= M;
	ce.Y /= M;
	yo = oop;
}
void agr::_draw(Pen& a, Graphics& graphics)
{	
	int r = 255, b = 255, g = 255;
	this->pin.getpen(r, b, g);
	for (int f = 0; f < M; f++)
	{
		yo[f]->pin.setpen(r, b, g);
		draw(*yo[f]);
	}
}
void agr::_hide()
{
	for (int f = 0; f < M; f++)
	{
		yo[f]->_hide();
	}
}

bool agr::may_i_muve(int x)
{
	bool dd = 1;
	for (int f = 0; f < getM(); f++)
	{
		if (!yo[f]->may_i_muve(x))
			dd = 0;
	}
	return dd;
}
void agr::_muve(int x, int y)
{
	for (int f = 0; f < M; f++)
	{

		yo[f]->_muve(x, y);
	}
}
void agr::_muv(int x, bool sl)
{
	if (this->may_i_muve(x))
	{
		for (int f = 0; f < M; f++)
		{
			yo[f]->_muv(x, 0);
		}
		if(sl)
			PLUS(x);
		switch (x)
		{
		case 0:
		{
			ce.Y += 5;
			break;
		}
		case 1:
		{
			ce.Y -= 5;
			break;
		}
		case 2:
		{
			ce.X += 5;
			break;
		}
		case 3:
		{
			ce.X -= 5;
			break;
		}
		}
		if(sl)
			TALE();
	}
}
bool agr::may_i_rotate()
{
	bool dd = 1;
	for (int f = 0; f < getM(); f++)
	{
		if (!yo[f]->may_i_rotate())
			dd = 0;
	}
	return dd;
}

bool agr::may_i_rot()
{
	bool ice = 1;
	for (int f = 0; f < M; f++)
	{
		if (!(yo[f]->may_i_rotate()))
		{
			ice = 0;
		}
	}
	return ice;
}


void agr::_turn(int x, float am)
{
	if (may_i_rot())
	{
		rotate_sup(x);
	}

	changes_sup(am);
	draw(*this);
}

bool agr::mat_i_become_big()
{
	bool to = 1;
	for (int f = 0; f < M; f++)
	{
		bool hate = maybe(*yo[f]);
		if (hate == 0)
		{
			to = 0;
			break;
		}
	}
	return to;
}

void agr::changes_sup(float am)
{
	if (this->mat_i_become_big() || am < 1)
	{
		for (int f = 0; f < M; f++)
		{
			(*yo[f])._turn(0, am);
		}
	}
	else
	{
		for (int f = 0; f < M; f++)
		{
			(*yo[f])._turn(0, 1);
		}
	}
}

void agr::rotate_sup(int x)
{
	bool kk = 1;
	for (int f = 0; f < M && kk == 1; f++)
	{
		yo[f]->ce = this->ce;
		switch (x)
		{
		case 5:
		{
			(*yo[f])._turn(5, 1);
			break;
		}
		case -5:
		{
			(*yo[f])._turn(-5, 1);
			break;
		}
		case 0:
		{
			kk = 0;
			break;
		}
		}
	}
}