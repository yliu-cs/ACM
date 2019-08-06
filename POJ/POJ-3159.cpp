#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxed = 150010;
const int maxn = 30010;
const double eps = 1e-5;

int n, m, edg;
int first[maxn], Next[maxed], u[maxed], v[maxed], w[maxed], dis[maxn];
bool vis[maxn];
priority_queue<P, vector<P>, greater<P> > que;

void Add_number(int pu, int pv, int pw) {
    u[edg] = pu;
    v[edg] = pv;
    w[edg] = pw;
    Next[edg] = first[pu];
    first[pu] = edg;
    edg++;
}

void Get_information() {
    edg = 0;
    mem(first, -1);
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Add_number(a, b, c);
    }
}

void Dijkstra() {
    mem(vis, 0);
    mem(dis, INF);
    dis[1] = 0;
    que.push(make_pair(0, 1));
    while (!que.empty()) {
        P u = que.top();
        que.pop();
        int x = u.second;
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        for (int e = first[x]; e != -1; e = Next[e]) {
            if (dis[v[e]] > dis[x] + w[e]) {
                dis[v[e]] = dis[x] + w[e];
                que.push(make_pair(dis[v[e]], v[e]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Get_information();
    Dijkstra();
    printf("%d", dis[n]);
    return 0;
}
