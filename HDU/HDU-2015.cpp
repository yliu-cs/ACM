#include<iostream>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 2; i <= n * 2;)
        {
            double avg = 0;
            for (int j = 1; j <= m; j++)
            {
                avg += i;
                if (i == n*2)
                {
                    cout << avg / j << endl;
                    break;
                }
                else if (j == m)
                {
                    cout << avg / j << " ";
                    break;
                }
                i = i + 2;
            }
            i = i + 2;
        }
    }
}
