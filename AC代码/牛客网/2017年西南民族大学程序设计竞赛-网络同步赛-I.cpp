#include <iostream>
using namespace std;
int main()
{
    int n,f[21];
    f[1] = 2;
    f[2] = 3;
    for (int i = 3;i <= 20;++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cin >> n;
    cout << f[n];
    return 0;
}
