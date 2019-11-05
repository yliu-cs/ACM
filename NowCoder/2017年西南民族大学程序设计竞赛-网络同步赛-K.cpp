#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int flag[5001];
    memset(flag,0,sizeof(flag));
    int n,m;
    cin >> n >> m;
    while (n--)
    {
        int a,b;
        cin >> a >> b;
        for (int i = a;i <= b;++i)
        {
            flag[i]++;
        }
    }
    sort(flag,flag+5001,greater<int>());
    if (flag[0]%m)
    {
        cout<<flag[0]/m+1;
    }else
    {
        cout<<flag[0]/m;
    }
    return 0;
}
