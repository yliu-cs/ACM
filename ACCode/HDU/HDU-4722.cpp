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
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

/*
 * 可以发现每10个数中必定有一个数各位数之和是10的倍数
 * 所以可以用n/10求得结果
 * 然后再计算n-n%10~n之内是否存在一个各位数之和是10的倍数的数
 * 如果存在则结果加一
 */

int t;

int Cal_digit_sum(ll x) {
    int digit_sum_ans = 0;
    while (x) {
        digit_sum_ans += x % 10;
        x /= 10;
    }
    return digit_sum_ans;
}

ll Cal_ans(ll x) {
    ll ans = 0;
    ans += x / 10;
    for (ll i = (x - x % 10); i <= x; ++i) {
        if (Cal_digit_sum(i) % 10 == 0) {
            ans++;
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        ll st, en;
        cin >> st >> en;
        cout << "Case #" << Case << ": " << Cal_ans(en) - Cal_ans(st - 1) << endl;
    }
    return 0;
}
