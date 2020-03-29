#include"Header.h"
#include<fstream>


void shape::WTF(string t)
{
	fstream fs;

	fs.open(t, fstream::out);
	if (!fs.is_open())
	{
		SetColor(4);
		cout << "\n  error";
		SetColor();
		return;
	}
	else
	{
		SetColor(2);
		cout << "  all right";
		SetColor();
	}
	fs << getN()<<" ";
	for (int ff = 0; ff < getN(); ff++)
	{
		int r, b, g;
		(*f[ff]).pin.getpen(r, b, g);
		fs << (*f[ff]).getNn() << " " << (*f[ff]).getT() << " " << (*f[ff]).Getmach() << " " << r << " " << b << " " << g << " " << (*f[ff]).ce.X << " " << (*f[ff]).ce.Y << "\n";
		for (int fff = 0; fff < (*f[ff]).getNn(); fff++)
		{
			fs << (*f[ff]).p[fff].X << " " << (*f[ff]).p[fff].Y << "\n";
		}
	}
	fs.close();
}

void shape::RFF(string t)
{
	fstream fs;

	fs.open(t, fstream::in);
	if (!fs.is_open())
	{
		SetColor(4);
		cout << "\n  error";
		SetColor();
		return;
	}
	else
	{
		SetColor(2);
		cout << "  all right";
		SetColor();
	}
	int N;
	fs >> N;
	for (int ff = 0; ff < N; ff++)
	{
		basic* pains = new basic;
		int r, b, g;
		
		fs >> r >> b >> g;
		(*pains).setNn(r);
		(*pains).p = new Point[(*pains).getNn()*2];
		(*pains).setT(b);
		(*pains).SetMach(g);
		fs >> r >> b >> g;
		(*pains).pin.setpen(r, b, g);
		fs >> r >> b;
		(*pains).ce.X = r;
		(*pains).ce.Y = b;
		for (int f = 0; f < (*pains).getNn(); f++)
		{
			fs >> r >> b;
			(*pains).p[f].X = r;
			(*pains).p[f].Y = b;
			(*pains).p[f + (*pains).getNn()] = (*pains).p[f];
		}
		ADD(*pains);
	}
	fs.close();
}






