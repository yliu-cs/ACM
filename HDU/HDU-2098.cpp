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
#include <set>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 10010;

bool IsPrime[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	// 素数打表
    mem(IsPrime, 1);
    for (int i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                IsPrime[j] = 0;
            }
        }
    }
    int n;
    while (cin >> n, n) {
        int sum = 0;
        for (int i = 2; i < n / 2; ++i) {
            if (IsPrime[i] && IsPrime[n - i]) {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
