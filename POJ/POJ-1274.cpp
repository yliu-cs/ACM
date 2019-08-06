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
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 500;
const double eps = 1e-5;

int n, m;
int sum;
int stall[maxn];
bool connect[maxn][maxn];
bool vis[maxn];

void init() {
    sum = 0;
    mem(connect, 0);
    mem(vis, 0);
    mem(stall, 0);
    return;
}

bool hall_find(int x) {
    for (int i = 1; i <= m; ++i) {
        if (connect[x][i] && !vis[i]) {
            vis[i] = 1;
            if (stall[i] == 0 || hall_find(stall[i])) {
                stall[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

void Work() {
    for (int i = 1; i <= n; ++i) {
        mem(vis, 0);
        if (hall_find(i)) {
            sum++;
        }
    }
    cout << sum << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m) {
        init();
        for (int i = 1; i <= n; ++i) {
            int num_of_like;
            cin >> num_of_like;
            while (num_of_like--) {
                int like_stall;
                cin >> like_stall;
                connect[i][like_stall] = 1;
            }
        }
        Work();
    }
    return 0;
}
