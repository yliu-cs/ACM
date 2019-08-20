#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;
const int maxn = 1e6 + 5;
int Sgn(db k) { return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
db Max(db k1, db k2) { return Cmp(k1, k2) > 0 ? k1 : k2; }
db Min(db k1, db k2) { return Cmp(k1, k2) < 0 ? k1 : k2; }
struct point { db x, y; };
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2}; }
point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
typedef std::vector<point> polygon;
db GetArea(polygon &poly) {
  db ret = 0.;
  for (int i = 0; i < poly.size(); ++i) ret += poly[i] ^ poly[(i + 1) % poly.size()];
  return ret * 0.5;
}
struct line { point s, t; };
bool IsParallel(line k1, line k2) { return !Sgn((k1.t - k1.s) ^ (k2.t - k2.s)); }
point Cross(line k1, line k2) {
  db a = (k2.t - k2.s) ^ (k1.s - k2.s);
  db b = (k2.t - k2.s) ^ (k1.t - k2.s);
  return (point){(k1.s.x * b - k1.t.x * a) / (b - a), (k1.s.y * b - k1.t.y * a) / (b - a)};
}
struct edge { int u, v; db ang; };
struct PSLG {
  int n, m, face_cnt;
  point p[maxn];
  std::vector<edge> e;
  std::vector<int> g[maxn];
  bool vis[maxn * 2];
  int left[maxn * 2], prev[maxn * 2];
  std::vector<polygon> faces;
  db area[maxn];
  void Init() {
    n = m = 0;
    for (int i = 0; i < n; ++i) g[i].clear();
    e.clear();
    faces.clear();
  }
  db GetAng(point pt) {
    return std::atan2(pt.y, pt.x);
  }
  void AddEdge(int u, int v) {
    e.push_back((edge){u, v, GetAng(p[v] - p[u])});
    e.push_back((edge){v, u, GetAng(p[u] - p[v])});
    m = e.size();
    g[u].push_back(m - 2);
    g[v].push_back(m - 1);
  }
  void Build() {
    for (int u = 0; u < n; ++u) {
      int sz = g[u].size();
      for (int i = 0; i < sz; ++i)
        for (int j = i + 1; j < sz; ++j)
          if (e[g[u][i]].ang > e[g[u][j]].ang) std::swap(g[u][i], g[u][j]);
      for (int i = 0; i < sz; ++i) prev[g[u][(i + 1) % sz]] = g[u][i];
    }
    face_cnt = 0;
    memset(vis, false, sizeof(vis));
    for (int u = 0; u < n; ++u) {
      int sz = g[u].size();
      for (int i = 0; i < sz; ++i) {
        int v = g[u][i];
        if (!vis[v]) {
          ++face_cnt;
          polygon poly;
          while (true) {
            vis[v] = 1;
            left[v] = face_cnt;
            int f = e[v].u;
            poly.push_back(p[f]);
            v = prev[v ^ 1];
            if (v == g[u][i]) break;
            assert(vis[v] == 0);
          }
          faces.push_back(poly);
        }
      }
    }
    for (int i = 0; i < face_cnt; ++i) area[i] = GetArea(faces[i]);
  }
};
line l[maxn];
std::vector<std::pair<db, int> > p[maxn];
PSLG pslg;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf%lf%lf%lf", &l[i].s.x, &l[i].s.y, &l[i].t.x, &l[i].t.y);
  pslg.Init();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (IsParallel(l[i], l[j])) continue;
      point inter = Cross(l[i], l[j]);
      pslg.p[pslg.n++] = inter;
      p[i].push_back({((inter - l[i].s) * (l[i].t - l[i].s)), pslg.n - 1});
      p[j].push_back({((inter - l[j].s) * (l[j].t - l[j].s)), pslg.n - 1});
    }
    std::sort(p[i].begin(), p[i].end(),
      [&](const std::pair<db, int> &k1, const std::pair<db, int> &k2) {
        return Cmp(k1.first, k2.first) < 0;
      }
    );
    for (int j = 1; j < p[i].size(); ++j) pslg.AddEdge(p[i][j - 1].second, p[i][j].second);
  }
  pslg.Build();
  std::sort(pslg.area, pslg.area + pslg.face_cnt,
    [&](const db &k1, const db &k2) {
      return Cmp(k1, k2) > 0;
    }
  );
  printf("%d %.15lf %.15lf\n", pslg.face_cnt - 1, pslg.area[0], pslg.area[pslg.face_cnt - 2]);
  int m;
  scanf("%d", &m);
  while (m--) {
    int q;
    scanf("%d", &q);
    if (q >= pslg.face_cnt) printf("Invalid question\n");
    else printf("%.15lf\n", pslg.area[q - 1]);
  }
  return 0;
}
