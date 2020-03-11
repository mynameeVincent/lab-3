#include"Header.h"

point tur(point y, double x)
{
	if (x > 180)
	{
		x -= 360;
	}

	x = x / 57.29577;
	point mi;
	double si = sin(x);
	double co = cos(x);
	mi.setX((y.getX() * co) - (y.getY() * si));
	mi.setY((y.getX() * si) + (y.getY() * co));
	return mi;
}


void bla_bla_bla()
{

	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);


	Sleep(30);
}





void mio(ULONG_PTR &gdiplusToken)
{
	if (!gdiplusToken)
		GdiplusShutdown(gdiplusToken);
}


