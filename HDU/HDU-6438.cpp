#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int Case = 1, n; Case <= t; ++Case) {
        scanf("%d", &n);
        priority_queue<int, vector<int>, greater<int> > pq;
        long long ans = 0, cnt = 0;
        map<int, int> vis;
        for (int i = 0, x; i < n; ++i) {
            scanf("%d", &x);
            pq.push(x);
            if (pq.top() < x) {
                cnt++;
                ans += x - pq.top();
                if (vis[pq.top()] > 0) {
                    cnt--;
                    vis[pq.top()]--;
                }
                pq.pop();
                pq.push(x);
                vis[x]++;
            }
        }
        printf("%lld %lld\n", ans, cnt * 2);
    }
    return 0;
}

