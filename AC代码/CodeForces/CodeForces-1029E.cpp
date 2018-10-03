#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int ans;
vector<int> tree[maxn];

int dfs(int node, int father) {
    int x = 2;
    for (int i = 0; i < int(tree[node].size()); ++i) {
        int u = tree[node][i];
        if (u != father) {
            x = min(x, dfs(u, node));
        }
    }
    // 当当前节点与父节点都不为根节点并且x=0时ans++
    if (node != 1 && father != 1 && x == 0) {
        ans++;
    }
    // 当x=2时返回0，根节点与1其父节点连线，ans++
    return (x + 1) % 3;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ans = 0;
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}

