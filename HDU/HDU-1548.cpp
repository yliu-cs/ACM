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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int num[maxn],temp[maxn];
int sta,endn;
int d[2] = {1, -1};
int t,a,b;

// 宽度优先搜索
int bfs() {
    queue<int> que;
    mem(temp, INF);
    que.push(sta);
    temp[sta] = 0;
    while (que.size()) {
        int p = que.front();
        que.pop();
        if (p == endn) {
            break;
        }
        for (int i = 0;i < 2;++i) {
            int n = p + num[p] * d[i];
            if (n >= 1 && n <= t && temp[n] == INF) {
                que.push(n);
                temp[n] = temp[p] + 1;
            }
        }
    }
    return temp[endn];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> t,t) {
        cin >> sta >> endn;
        for (int i = 1;i <= t;++i) {
            cin >> num[i];
        }
        if (bfs() == INF) {
            cout << -1 << endl;
        }
        else {
            cout << bfs() << endl;
        }
    }
    return 0;
}
