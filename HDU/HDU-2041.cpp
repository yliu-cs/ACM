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
const int maxn = 41;

int res[maxn];

// 记忆化搜索递归求得斐波那契数列
int Fib(int x) {
    if (res[x] >= 0) {
        return res[x];
    }
    else {
        int ans = Fib(x - 1) + Fib(x - 2);
        res[x] = ans;
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(res, -1);
    res[0] = 0;
    res[1] = 1;
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        cout << Fib(M) << endl;
    }
    return 0;
}
