std::vector<std::vector<int>> g;
int dfs_clock;
std::vector<int> in, out;

// Dfs序
void DfsOrder(int cur, int pre) {
  in[cur] = ++dfs_clock;
  for (auto &it : g) {
    if (it == pre) continue;
    DfsOrder(it, cur);
  }
  out[cur] = dfs_clock;
}
