#include <iostream>
using namespace std;
int main()
{
	int r = 5;
	int n;
	cin >> n;
	char **seat;
	seat = new char*[n];
	for (int i = 0;i < n;++i)
	{
		seat[i] = new char[r];
	}
	for (int j = 0;j < n;++j)
	{
		for (int i = 0;i < r;++i)
		{
			cin >> seat[j][i];
		}
	}
	int x = 0;
	for (int j = 0;j < n;++j)
	{
		if (seat[j][0] == 'O'&&seat[j][1] == 'O')
		{
			seat[j][0] = '+';
			seat[j][1] = '+';
			x++;
			break;
		}
		if (seat[j][3] == 'O'&&seat[j][4] == 'O')
		{
			seat[j][3] = '+';
			seat[j][4] = '+';
			x++;
			break;
		}
	}
	if (x == 1)
	{
		cout << "YES" << endl;
		for (int j = 0;j < n;++j)
		{
			for (int i = 0;i < r;++i)
			{
				cout << seat[j][i];
			}
			cout << endl;
		}
	}else
	{
		cout << "NO";
	}
	return 0;
}
