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
const int maxn = 1e2+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int n;
ull a[maxn];
ull ans[maxn];
bool flag;
bool vis[maxn];

void dfs(ull x, int step) {
    ans[step] = x;
    if (step == n) {
        flag = 1;
        return;
    }
    if (x % 3 == 0) {
        ull temp = x / 3;
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && a[i] == temp) {
                vis[i] = 1;
                dfs(a[i], step + 1);
                if (flag) {
                    return;
                }
                vis[i] = 0;
                break;
            }
        }
    }
    ull temp = x * 2;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && a[i] == temp) {
            vis[i] = 1;
            dfs(a[i], step + 1);
            if (flag) {
                return;
            }
            vis[i] = 0;
        }
    }
}

int main() {
    //fre();
    flag = 0;
    cin >> n;
    mem(vis, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        dfs(a[i], 1);
        if (flag) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
