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

const int maxn = 8;
int n,k,ans,sum;
char maze[maxn][maxn];
bool flag[maxn];

void dfs(int x) {
    if (sum == k) {
        ans++;
        return;
    }
    if (x >= n) {
        return;
    }
    for (int i = 0;i < n;++i) {
        if (maze[x][i] == '#' && flag[i] == 0) {
            flag[i] = 1;
            sum++;
            dfs(x + 1);
            sum--;
            flag[i] = 0;
        }
    }
    dfs(x + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> k) {
        if (n == -1 && k == -1) {
            break;
        }
        sum = 0;
        ans = 0;
        mem(flag, 0);
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                cin >> maze[i][j];
            }
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
