const int maxn = "Edit";

vector<vector<int>> g;

int dfs_clock;
int in[maxn], out[maxn];

// Dfs序
void DfsOrder(int cur, int pre) {
    dfs_clock++;
    in[cur] = dfs_clock;
    for (auto &it : g) {
        if (it == pre) continue;
        DfsOrder(it, cur);
    }
    out[cur] = dfs_clock;
}
