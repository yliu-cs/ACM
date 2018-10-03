#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1000010;

bool IsGealy[maxn];
int d[7] = {0,10,100,1000,10000,100000,1000000};

// 打标预处理
void Gealy() {
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < 7; ++j) {
            int a = i, b = i;
            if (i > d[j]) {
                if (d[j] != 0) {
                    a /= d[j];
                    b /= d[j];
                }
                if (j < 5) {
                    a %= 100;
                }
                if (j < 6) {
                    b %= 10;
                }
            }
            if (a == 62 || b == 4) {
                IsGealy[i] = 0;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(IsGealy, 1);
    Gealy();
    int n, m;
    while (cin >> n >> m, n, m) {
        int sum = 0;
        for (int i = n; i <= m; ++i) {
            if (IsGealy[i]) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
