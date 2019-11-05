#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	char x1,x2;
	int y1,y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	int a1,a2;
	a1 = x1 - 96;
	a2 = x2 - 96;
	int h1 = a1 - a2;
	if (h1 < 0)
	{
		h1 = -h1;
	}
	int h2 = y1 - y2;
	if (h2 < 0)
	{
		h2 = -h2;
	}
	cout << max(h1,h2) << endl;
	while (a1 != a2||y1 != y2)
	{
		if (y2 > y1)
		{
			if (a2 > a1)
			{
				cout << "RU" << endl;
				a1++;
				y1++;
			}else if (a2 < a1)
			{
				cout << "LU" << endl;
				y1++;
				a1--;
			}else
			{
				cout << "U" << endl;
				y1++;
			}
		}else if (y2 < y1)
		{
			if (a2 > a1)
			{
				cout << "RD" << endl;
				a1++;
				y1--;
			}else if (a2 < a1)
			{
				cout << "LD" << endl;
				a1--;
				y1--;
			}else
			{
				cout << "D" << endl;
				y1--;
			}
		}else
		{
			if (a2 < a1)
			{
				cout << "L" << endl;
				a1--;
			}else
			{
				cout << "R" << endl;
				a1++;
			}
		}
	}
	return 0;
}
