#include <iostream>
using namespace std;
// 根据题意模拟
int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }
        int res = N * 5;
        int a = 0;
        while (N--)
        {
            int n;
            cin >> n;
            if (n > a)
            {
                int b =    n - a;
                res += b * 6;
                a = n;
            }else if (a > n)
            {
                int b = a - n;
                res += b * 4;
                a = n;
            }
        }
        cout << res << endl;
    }
    return 0;
}
