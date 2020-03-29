#include"Header.h"
void pen :: getpen(int& r, int& b, int& g)
{
	r = this->r;
	b = this->b;
	g = this->g;
}

void pen :: setpen(int r, int b, int g)
{
	this->b = b;
	this->r = r;
	this->g = g;
}

pen :: pen(int r, int b, int g)
{
	this->b = b;
	this->r = r;
	this->g = g;
}

int pen::ceng_sup()
{
	int r = 0;
	char t = 0;
	cout << "\n\n\t";
	for (int f = 0; f < 3 && t != 13 && t != 10; f++)
	{
		t = _getch();
		if (t == 27)
		{
			r = -1;
			break;
		}
		if (t < '0' || t > '9')
		{
			f--;
		}
		else
		{
			r = r * 10 + (t - 48);
			cout << t;
		}
	}
	cout << "\t";
	if (r > 255)
		r = 255;
	return r;
}

void pen :: chengecol()
{
	int r = 0, b = 0, g = 0;
	r = this->ceng_sup();
	if (r == -1)
		return;
	b = this->ceng_sup();
	if (b == -1)
		return;
	g = this->ceng_sup();
	if (g == -1)
		return;
	this->setpen(r, b, g);
}