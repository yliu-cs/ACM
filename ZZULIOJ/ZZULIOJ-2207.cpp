#include <iostream>
using namespace std;
long long modxx(long long a,long long b,long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        a = a % mod;
        if (b & 1)
        {
            res = res * a % mod;
        } 
        b = b >> 1;
        a = a * a % mod;
    }
    return res; 
}
int main()
{
    long long mod = 10;
    long long m,n;
    while (cin >> m >> n)
    {
        cout << modxx(m,n,mod) << endl; 
    }
    return 0;
}
