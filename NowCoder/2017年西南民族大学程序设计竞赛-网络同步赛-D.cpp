#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *sweet;
    sweet = new int[n + 1];
    for (int i = 1;i <= n;++i)
    {
        cin >> sweet[i];
    }
    int m;
    cin >> m;
    int *num;
    num = new int[m];
    for (int i = 0;i < m;++i)
    {
        num[i] = 0;
        int L,R;
        cin >> L >> R;
        for (int j = L;j <= R;++j)
        {
            num[i] += sweet[j];
        }
    }
    sort(num,num+m,greater<int>());
    long long result = 0;
    for (int i = 0;i < m;++i)
    {
        if (num[i] > 0)
        {
            result += num[i];
        }
    }
    cout << result;
    return 0;
}
