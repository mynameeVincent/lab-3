#include"Header.h"

int main()
{
	bla_bla_bla();

	//shap j;
	shape tt;

	//j.plus_();
	//for (int f = 0; f < 30; f++)
	//	j.muve_(1);

	//j.plus_();
	//j.plus_();
	//for (int f = 0; f < 30; f++)
	//	j.muve_(3);

	//char imor=0;
	//while(imor!='-')
	//	imor=_getch();



	point u1(400, 400);
	point u2(600, 745);
	point u3(800, 400);

	triangle ii(u1, u2, u3);
	line io(200, 200, 150, 150);
	rec tm(300,300,200,200);
	tt.draw(tm);
	Sleep(1000);
	tt.muveTO(tm, 1000, 400);
	tt.draw(tm);
	Sleep(1000);
	for (int f = 0; f < 300; )
	{
		cout << "mi";
		tt.rotate(tm, 10);
		tt.draw(tm);

		tt.rotate(io, 10);
		tt.draw(io);

		tt.rotate(ii, 10);
		tt.draw(ii);

		Sleep(0);
	}
	return 0;
}