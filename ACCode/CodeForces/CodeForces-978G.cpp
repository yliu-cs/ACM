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
const int maxn = 1e2+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}

struct ac {
    int num;
    int s;
    int d;
    int c;
};

bool cmp(ac a, ac b) {
    return a.d < b.d;
}

int main() {
    //fre();
    int n, m;
    scanf("%d%d", &n, &m);
    ac ex[maxn];
    for (int i = 1; i <= m; ++i) {
        ex[i].num = i;
        scanf("%d%d%d", &ex[i].s, &ex[i].d, &ex[i].c);
    }
    sort(ex + 1, ex + m + 1, cmp);
    int ans[maxn];
    mem(ans, -1);
    bool flag = 1;
    for (int i = 1; i <= m; ++i) {
        int cnt = 0;
        int j;
        for (j = ex[i].s; j < ex[i].s + ex[i].c + cnt; ++j) {
            if (j >= ex[i].d) {
                flag = 0;
                break;
            }
            if (ans[j] == -1) {
                ans[j] = ex[i].num;
            }
            else {
                cnt++;
            }
        }
        if (!flag) {
            break;
        }
        if (ans[ex[i].d] == -1) {
            ans[ex[i].d] = m + 1;
        }
        else {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            ans[i] = 0;
        }
        printf("%d ", ans[i]);
    }
    return 0;
}
