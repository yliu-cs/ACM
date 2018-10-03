#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
#define maxn 3000010

int Sum[maxn];
bool IsPrime[maxn];
int Prime[maxn];

// 欧拉打表
void Judge() {
    int cnt = 0;
    mem(IsPrime, 0);
    for (int i = 2;i < maxn;++i) {
        if (IsPrime[i] == 0) {
            Prime[cnt++] = i;
            Sum[i] = i - 1;
        }
        for (int j = 0;j < cnt && i * Prime[j] < maxn;++j) {
            IsPrime[i * Prime[j]] = 1;
            if (i % Prime[j] == 0) {
                Sum[i * Prime[j]] = Sum[i] * Prime[j];
            }
            else {
                Sum[i * Prime[j]] = Sum[i] * (Prime[j] - 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    Judge();
    int a,b;
    while (cin >> a >> b) {
        ll Res = 0;
        for (int i = a;i <= b;++i) {
            Res += Sum[i];
        }
        cout << Res << endl;
    }
    return 0;
}
