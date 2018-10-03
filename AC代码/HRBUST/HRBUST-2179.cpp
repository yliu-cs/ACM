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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int num[11], n, k;
bool vis[11] = {0};

void dfs(int step,int q) {
    if (step == k) {
        cout << num[0];
        for (int i = 1; i < k; ++i) {
            cout << " " << num[i];
        }
        cout << endl;
        return;
    }
    for (int i = q; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            num[step] = i;
            dfs(step + 1, i + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mem(num, 0);
        cin >> n >> k;
        dfs(0, 1);
    }
    return 0;
}
