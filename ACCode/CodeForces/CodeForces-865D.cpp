#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        que.push(x);
        if (que.top() < x) {
            ans += x - que.top();
            que.pop();
            que.push(x);
        }
    }
    printf("%lld\n", ans);
    return 0;
}

