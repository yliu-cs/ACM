#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    int *a,*b;
    a = new int[n];
    b = new int[n];
    for (int i = 0;i < n;++i)
    {
        cin >> a[i];
    }
    long long flag = 0;
    for (int i = 0;i < n;++i)
    {
        cin >> b[i];
        flag += b[i];
        b[i] -= a[i];
    }
    sort(b,b+n);
    for (int i = 0;i < k;++i)
    {
        flag -= b[i];
    }
    cout << flag;
    return 0;
}
