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

int n, m;
bool flag;
bool vis[maxn];
int ans;
vector<int> Adj[maxn];

void dfs(int x) {
    if (Adj[x].size() != 2 || vis[x]) {
        flag = 0;
        return;
    }
    vis[x] = 1;
    for (auto it = Adj[x].begin(); it != Adj[x].end(); ++it) {
        int v = *it;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    //fre();
    ans = 0;
    mem(vis, 0);
    scanf("%d%d", &n, &m);
    while (m--) {
        int input_u, input_v;
        scanf("%d%d", &input_u, &input_v);
        Adj[input_u].pb(input_v);
        Adj[input_v].pb(input_u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            flag = 1;
            dfs(i);
            if (flag) {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
