#include <iostream>
int main()
{
    using namespace std;
    int n;
    while (cin >> n)
    {
        int *a,*b;
        a = new int[n + 1];
        b = new int[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            b[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            for (int j = 1; j <= i; ++j)
            {
                if (a[i] == a[j])
                {
                    b[j]++;
                    break;
                }
            }
        }
        int x = 0,y;
        for (int i = 1; i <= n; ++i)
        {
            if (b[i] > x)
            {
                x = b[i];
                y = i;
            }
        }
        int z = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i != y)
            {
                z += b[i];
            }
        }
        if (b[y] > z)
        {
            cout << a[y] << endl;
        }else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
