const int maxn = "Edit";

struct edge {int u, v, c;};
bool operator < (edge k1 edge k2) {return k1.c < k2.c;}

int n, e, pre[maxn];
std::vector<edge> g;

void Init() {for (int i = 0; i <= n; ++i) pre[i] = i;}
int Find(int x) {return pre[x] == x ? x : pre[x] = Find(pre[x]);}
void Union(int x, int y) {pre[Find(x)] = Find(y);}

int Kruskal() {
  std::sort(g.begin(), g.end());
  Init();
  int ret = 0;
  for (auto &e : g) {
    if (Find(e.u) != Find(e.v)) {
      Union(e.u, e.v);
      ret += e.c;
    }
  }
  return ret;
}
