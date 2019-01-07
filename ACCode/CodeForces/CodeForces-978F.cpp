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
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}

struct ac {
    int v, s;
    int qua;
};

int ans[maxn];
ac s[maxn];

bool cmp(ac a, ac b) {
    return a.s > b.s;
}

int main() {
    //fre();
    int n, k;
    scanf("%d%d", &n, &k);
    int minn = INF;
    for (int i = 1; i <= n; ++i) {
        s[i].v = i;
        s[i].qua = 0;
        scanf("%d", &s[i].s);
        if (s[i].s < minn) {
            minn = s[i].s;
        }
    }
    while (k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int temp;
        if (s[u].s == s[v].s) {
            continue;
        }
        else if (s[u].s > s[v].s) {
            temp = s[u].v;
        }
        else {
            temp = s[v].v;
        }
        s[temp].qua++;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        if (s[i].s == minn) {
            ans[s[i].v] = 0;
            continue;
        }
        int _l = 1, _r = n;
        while (_l < _r) {
            int mid = (_l + _r) >> 1;
            if (s[mid].s >= s[i].s) {
                _l = mid + 1;
            }
            else {
                _r = mid;
            }
        }
        ans[s[i].v] = n - _l + 1 - s[i].qua;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
