#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, p; cin >> n >> m >> p;
    vector<int> s(p);
    for (auto &it : s) cin >> it;
    vector<queue<pair<int, int>>> que(p);
    vector<int> ans(p, 0);
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (isdigit(maze[i][j])) {
                que[maze[i][j] - '0' - 1].push(make_pair(i, j));
                ans[maze[i][j] - '0' - 1]++;
            }
        }
    }
    auto check = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.';
    };
    auto bfs = [&](int key) {
        int speed = s[key];
        while (speed--) {
            if (que[key].empty()) break;
            int size = que[key].size();
            for (int k = 0; k < size; ++k) {
                if (que[key].empty()) continue;
                pair<int, int> cur = que[key].front(); que[key].pop();
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        if (abs(i) == abs(j)) continue;
                        int nx(cur.first + i), ny(cur.second + j);
                        if (check(nx, ny)) {
                            maze[nx][ny] = key + '0';
                            ans[key]++;
                            que[key].push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    };
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < p; ++i) {
            if (que[i].empty()) continue;
            flag = true;
            bfs(i);
        }
    }
    for (auto &it : ans) cout << it << " ";
    cout << endl;
    return 0;
}

