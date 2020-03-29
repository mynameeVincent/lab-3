#include"Header.h"
#include<vector>

shape::shape()
{
	N = 0;
}

int shape :: getN()
{
	return N;
}
void shape::draw_(int n)
{
	if (n <= N && n > 0)
		draw(*f[n - 1]);
}
void shape::plus_()
{
	char numb = 0;

	bool sad = 0;
	while (1)
	{
		numb = _getch();
		switch (numb)
		{
		case '0':
		{
			point* io = new point(600, 400);
			ADD(*io);
			sad = 1;
			break;
		}
		case '3':
		{
			rec* io = new rec(550, 350, 100, 100);
			ADD(*io);
			sad = 1;
			break;
		}
		case '2':
		{
			triangle* io;
			{
				point a(700, 300);
				point b(500, 400);
				point c(700, 500);
				io = new triangle(a, b, c);
			}
			ADD(*io);
			sad = 1;
			break;
		}

		case '1':
		{
			line* io = new line(550, 350, 650, 450);
			ADD(*io);
			sad = 1;
			break;
		}

		case '9':							/////////////////////////////////////////////////chenge me
		{
			users look;
			look.Pluas_agr();
			char op = 0;
			vector<bool> numb(10);
			op = _getch();
			int how = 0;
			while (op != 13 && op != 10 && op != ' ')
			{
				SetCur(0, 15);
				if (numb[op - '0'])
				{
					numb[op - '0'] = 0;
					how--;
				}
				else
				{
					numb[op - '0'] = 1;
					how++;
				}
				for (int f = 0; f < 10; f++)
				{
					cout << numb[f] << "  ";
				}
				while (1)
				{
					op = _getch();
					if (op <= '9' && op >= '0' || op == 13 || op == 10 || op==27 ||op == ' ')
					{
						break;
					}
				}
			}
			basic **V=new basic*[how];
			int fff = 0;
			for (int ff = 0; ff < getN(); ff++)
			{
				if (numb[ff] == 1)
				{
					V[fff] = &copy(*f[ff]);
					fff++;
				}
			}
			if (fff == 0)
			{
				look.newname();
				break;
			}

			agr* d = new agr(V, fff);
			ADD(*d);
			sad = 1;
			cout << "hi";

			break;
		}
		case 27:
		{
			exit(0);
		}

		default:
		{
			break;
		}
		}
		if (sad == 1)
			break;
	}

	draw_(N);
	users look;
	look.congr();
}

void shape::hide_(int u)
{
	f[u]->_hide();
	delete f[u];
	for (int ff = u; ff < getN() - 1; ff++)
		f[ff] = f[ff + 1];
	setN(getN()-1);
}

void shape::compil_sup()
{
	for (int f = 0; f < getN() + 1; f++)
	{
		draw_(f);
	}
}

void shape::muve_(int n, char mi, bool sl)
{
	
	switch (mi)
	{
	case 'w':
	{
		if ((*f[n]).may_i_muve(2))
			muve(*f[n], 1, sl);
		break;
	}
	case 's':
	{
		if ((*f[n]).may_i_muve(4))
			muve(*f[n], 0, sl);
		break;
	}
	case 'd':
	{
		if ((*f[n]).may_i_muve(3))
			muve(*f[n], 2, sl);
		break;
	}
	case 'a':
	{
		if ((*f[n]).may_i_muve(1))
			muve(*f[n], 3, sl);
		break;
	}
	default:
		break;
	}
}

void shape::rotate_(int n, bool rorl)
{
	if (rorl == 0)
	{
		f[n]->_turn(5, 1);
	}
	else
	{
		f[n]->_turn(-5, 1);

	}
	draw(*f[n]);
}

void shape::setN(int N)
{
	this->N = N;
}

void shape::ADD(basic& gg)
{
	f[N] = &gg;
	N++;
}