#include"Header.h"

void shape::compil()
{
	users look;
	look.mainwind(N);
	char sel = 0;
	bool sl = 0;
	int No = 0;
	while (1)
	{
		sel = _getch();
		switch (sel)
		{
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
		{

			if (getN() > int(sel) - 48)
			{
				
				No = sel - 48;
				users look;
				look.hope(No);
			}
			
			break;
		}
		case 'w': case 'W': case 'a': case 'A': case 'd': case 'D': case 's': case 'S':
		{
			if (getN() == 0)
				break;
			muve_(No, sel, sl);
			break;
		}
		case 'q': case 'Q': case 'E': case'e':				//??????????
		{
			if (getN() == 0)
				break;
			hide(*f[No]);
			bool k = 0;
			if (sel == 'q' || sel == 'Q')
				k = 1;
			rotate_(No, k);
			break;
		}
		case 27:
		{
			exit(0);
			break;
		}
		case 59:
		{
			cout << "f1";
			break;
		}
		case 'c': case 'C':									//color chenge
		{
			if (getN() == 0)
				break;
			look.colorset();
			change_color(*f[No]);
			users look;
			look.congr();
			look.mainwind(No);

			break;
		}
		case '+': case '=':
		{
			users look;
			look.PLUS();


			plus_();

			No = getN() - 1;
			look.mainwind(No);
			look.hope(No);
			Sleep(0.1);

			break;
		}
		case '-': case '_':
		{
			if (getN() <= 0)
				break;
			hide_(No);
			No = 0;
			users look;
			look.hope(No);
			break;
		}
		case 'Z': case 'z':
		{
			if (getN() == 0)
				break;
			if (sl)
			{
				sl = 0;
				f[No]->HIDE();
			}
			else
				sl = 1;
			break;
		}
		case '/':
		{
			if (getN() == 0)
				break;
			hide(*f[No]);
			f[No]->_turn(0, 0.975);
			draw(*f[No]);
			break;
		}
		case '*':
		{
			if (getN() == 0)
				break;
			hide(*f[No]);
			f[No]->_turn(0, 1.025);
			draw(*f[No]);
			break;
		}
		case 8:
		{
			look.WTF();
			string yo;
			cin >> yo;
			yo += ".dat";
			WTF(yo);
			look.mainwind(No);
			look.hope(No);
			break;
		}
		case 9:
		{
			look.WTF();
			string yo;
			cin >> yo;
			yo += ".dat";
			RFF(yo);
			look.mainwind(No);
			look.hope(No);
			break;
		}
		}
		compil_sup();
	}
}