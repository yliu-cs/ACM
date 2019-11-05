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
typedef pair<int,int> p;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int n;
ll a[maxn];
map<int, int> dp;
ll ans, book;
ll res[maxn];

int main() {
    //fre();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    ans = 0; book = 0;
    for (int i = 0; i < n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (ans < dp[a[i]]) {
            ans = dp[a[i]];
            book = a[i];
        }
    }
    int temp = ans - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == book) {
            res[temp--] = i + 1;
            book--;
        }
    }
    printf("%I64d\n", ans);
    for (int i = 0; i < ans; ++i) {
        printf("%I64d ", res[i]);
    }
    return 0;
}
