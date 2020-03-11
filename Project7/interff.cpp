#include"Header.h"

shap::shap()
{
	N = 0;
}

int shap :: getN()
{
	return N;
}
void shap::draw(int n)
{
	if (n <= N && n > 0)
		U.draw(*f[n - 1]);
}
void shap::plus_()
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

		case '9':
		{
			basic **V=new basic*[2];
			V[0] = f[0];
			V[1] = f[1];

			agr *d=new agr(V,2);
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
			cout << "select 0-9";
			break;
		}
		}
		if (sad == 1)
			break;
	}
	draw(N);
}

void shap::hide_(int u)
{
	f[u - 1]->_hide();
	delete[] f[u - 1];
	for (int ff = u - 1; ff < N - 1; ff++)
		f[ff] = f[ff + 1];
}


void shap::muve_(int n)
{
	char mi;
	mi = _getch();
	switch (mi)
	{
	case 'w':
	{
		U.muve(*f[n - 1], 1);
		break;
	}
	case 's':
	{
		U.muve(*f[n - 1], 0);
		break;
	}
	case 'd':
	{
		U.muve(*f[n - 1], 2);
		break;
	}
	case 'a':
	{
		U.muve(*f[n - 1], 3);
		break;
	}
	default:
		break;
	}
}

void shap::rotate_(int n, bool rorl)
{
	if (rorl == 1)
	{
		U.rotate(*f[n], 5);
		U.draw(*f[n]);
	}
}
