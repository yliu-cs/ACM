#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 22;
const double eps = 1e-5;
const double e = 2.718281828459;

int n;
int cnt = 0;
bool flag[maxn];
char rel[maxn][maxn];
int ans[maxn];
bool res_flag = 0;

void dfs(int st, int step) {
    if (step == n && (rel[st][1] == 'W' || rel[1][st] == 'L')) {
        ans[step] = st;
        res_flag = 1;
        return;
    }
    else {
        // 剪枝
        bool dfs_flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (!flag[i] && (rel[i][1] == 'W' || rel[1][i] == 'L')) {
                dfs_flag = 1;
                break;
            }
        }
        if (!dfs_flag) {
            return;
        }
        // 搜索
        for (int i = 1; i <= n; ++i) {
            if (!flag[i] && (rel[st][i] == 'W' || rel[i][st] == 'L')) {
                flag[i] = 1;
                ans[step] = st;
                dfs(i, step + 1);
                if (res_flag) {
                    return;
                }
                flag[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> rel[i][j];
        }
    }
    mem(flag, 0);
    flag[1] = 1;
    dfs(1, 1);
    if (!res_flag) {
        cout << "No Solution";
    }
    else {
        cout << ans[1];
        for (int i = 2; i <= n; ++i) {
            cout << " " << ans[i];
        }
    }
    return 0;
}
