#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char dir[100010];
	cin >> dir;
	int len = strlen(dir);
	if (len % 2 != 0)
	{
		cout << -1;
	}else
	{
		int a[4] = {0,0,0,0};
		for (int i = 0;i < len;++i)
		{
			if (dir[i] == 'L')
			{
				a[0]++;
			}else if (dir[i] == 'R')
			{
				a[1]++;
			}else if (dir[i] == 'U')
			{
				a[2]++;
			}else if (dir[i] == 'D')
			{
				a[3]++;
			}
		}
		int res = 0;
		int b1 = a[0] > a[1] ? a[0] : a[1];
		int b2 = a[0] < a[1] ? a[0] : a[1];
		int b = b1 - b2;
		int c1 = a[2] > a[3] ? a[2] : a[3];
		int c2 = a[2] < a[3] ? a[2] : a[3];
		int c = c1 - c2;
		res = (b + c) / 2;
		cout << res;
	}
	return 0;
}
