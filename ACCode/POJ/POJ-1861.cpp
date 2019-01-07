#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int maxn = 1000100;

struct connect {
    int u;
    int v;
    int dis;
}eg[maxn];

int n,E,pre[maxn],Max = 0,N = 0;

bool cmp(connect a,connect b) {
    return a.dis < b.dis;
}

void init(int n) {
    for (int i = 0;i <= n;++i) {
        pre[i] = i;
    }
}

int find(int x) {
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    int i = x,j;
    while (i != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x,int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        pre[xx] = yy;
    }
}

void kruskal() {
    sort(eg, eg + n * n, cmp);
    init(n);
    int res = 0;
    for (int i = 0;i <= n * n;++i) {
        connect e = eg[i];
        if (find(e.u) != find(e.v)) {
            join(e.u, e.v);
            res += e.dis;
            N++;
            if (e.dis > Max) {
                Max = e.dis;
            }
        }
    }
}

void kruskal2() {
    init(n);
    for (int i = 0;i <= n * n;++i) {
        connect e = eg[i];
        if (find(e.u) != find(e.v)) {
            join(e.u, e.v);
            cout << e.u << " " << e.v << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    cin >> E;
    int Num = 0;
    while (E--) {
        int a,b,c;
        cin >> a >> b >> c;
        connect add;
        add.u = a;
        add.v = b;
        add.dis = c;
        eg[Num++] = add;
    }
    kruskal();
    cout << Max << endl;
    cout << N << endl;
    kruskal2();
    return 0;
}
