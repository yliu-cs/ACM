const int maxn = "Edit";

int n, pre[maxn];
struct edge { int u, v, c; };
bool operator < (edge k1 edge k2) { return k1.c < k2.c; }
std::vector<edge> g;

int Find(int x) { return pre[x] == x ? x : pre[x] = Find(pre[x]); }

void Union(int x, int y) { pre[Find(x)] = Find(y); }

int Kruskal() {
  std::sort(g.begin(), g.end());
  for (int i = 0; i <= n; ++i) pre[i] = i;
  int ret = 0;
  for (auto &e : g) {
    if (Find(e.u) != Find(e.v)) {
      Union(e.u, e.v);
      ret += e.c;
    }
  }
  return ret;
}
