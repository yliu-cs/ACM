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
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int n;
ull s, l;
ull h[maxn];
ull a[maxn];
ull d[maxn];
ull ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> s >> l) {
        ull a_max = 0;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > a_max) {
                a_max = a[i];
            }
        }
        ull _left = 0;
        ull _right = s > l ? s : l;
        _right /= a_max;
        _right += 1000;
        while (_left < _right) {
            ll mid = (_left + _right) / 2;
            ll sum = 0;
            for (int i = 0; i < n; ++i) {
                d[i] = h[i] + a[i] * mid;
                if (d[i] >= l) {
                    sum += d[i];
                }
            }
            if (sum < s) {
                _left = mid + 1;
            }
            else {
                _right = mid;
            }
            ans = _right;
        }
        cout << ans << endl;
    }
    return 0;
}

