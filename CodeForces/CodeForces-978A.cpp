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
const int maxn = 2e3+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main() {
    //fre();
    int n;
    scanf("%d", &n);
    int a[55];
    bool vis[1005];
    mem(vis, 0);
    int cnt = 0;
    set<int> num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (!num.count(a[i])) {
            num.insert(a[i]);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    stack<int> sta;
    for (int i = n - 1; i >= 0; --i) {
        if (!vis[a[i]]) {
            sta.push(a[i]);
            vis[a[i]] = 1;
        }
    }
    printf("%d", sta.top());
    sta.pop();
    while (!sta.empty()) {
        printf(" %d", sta.top());
        sta.pop();
    }
    return 0;
}
