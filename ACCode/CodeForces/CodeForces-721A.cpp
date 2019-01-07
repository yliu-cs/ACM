#include <iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	char *a;
	a = new char[k];
	int *b;
	b = new int[k];
	cin >> a;
	int x = 0;
	for (int i = 0;i < k;++i)
	{
		b[i] = 0;
		if (a[i] == 'B')
		{
			if (i == 0)
			{
				b[i]++;
				continue;
			}
			int y = 0;
			for (int j = x;j < i;++j)
			{
				if (b[j] != 0)
				{
					b[j]++;
					y++;
					break;
				}
			}
			if (y == 0&&i != 0)
			{
				b[i]++;
			}
		}else
		{
			x = i;
		}
	}
	int num = 0;
	for (int i = 0;i < k;++i)
	{
		if (b[i] != 0)
		{
			num++;
		}
	}
	cout << num << endl;
	for (int i = 0;i < k;++i)
	{
		if (b[i] != 0)
		{
			cout << b[i] << " ";
		}
	}
	return 0;
}
