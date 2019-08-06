#include <iostream>
int main()
{
    using namespace std;
    int a,b;
    while(cin >> a >> b)
    {
        int c;
        c = a * 100;
        int d;
        for (int i = 0; i <= 99; ++i)
        {
            d = c + i;
            if (d % b == 0)
            {
                if (i >= 0&&i <= 9)
                {
                    cout << 0 << i << " ";
                }else
                {
                    cout << i << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
