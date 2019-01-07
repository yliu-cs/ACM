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
const int maxn = 100001;
const int INF = 100000000;

int num[maxn],temp[maxn];
int sta,endn;
int d[3] = {1,-1,2};

int bfs() {
    queue<int> que;
    for (int i = 0;i < maxn;++i) {
        temp[i] = INF;
    }
    que.push(sta);
    temp[sta] = 0;
    while (que.size()) {
        int p = que.front();
        que.pop();
        if (p == endn) {
            break;
        }
        for (int i = 0;i < 3;++i) {
            int n;
            if (i < 2) {
                n = p + d[i];
            }
            else {
                n = p * d[i];
            }
            if (n >= 0 && n <= maxn && temp[n] == INF) {
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
    while (cin >> sta >> endn) {
        cout << bfs() << endl;
    }
    return 0;
}
