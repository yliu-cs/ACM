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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool flag = 1;
    int n;
    cin >> n;
    char **maze;
    maze = new char*[n + 1];
    for (int i = 0; i <= n; ++i) {
        maze[i] = new char[n + 1];
    }
    bool **vis;
    vis = new bool*[n + 1];
    for (int i = 0; i <= n; ++i) {
        vis[i] = new bool[n + 1];
    }
    char Dia, Oth;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            vis[i][j] = 1;
            cin >> maze[i][j];
        }
    }
    Dia = maze[1][1];
    Oth = maze[1][2];
    if (Dia == Oth) {
        flag = 0;
    }
    if (flag) {
        for (int i = 1, j = 1; i <= n && j <= n; ++i, ++j) {
            if (maze[i][j] != Dia) {
                flag = 0;
                break;
            }
            vis[i][j] = 0;
        }
    }
    if (flag) {
        for (int i = n, j = 1; i >= 1 && j <= n; --i, ++j) {
            if (maze[i][j] != Dia) {
                flag = 0;
                break;
            }
            vis[i][j] = 0;
        }
    }
    if (flag) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (vis[i][j] && maze[i][j] != Oth) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
