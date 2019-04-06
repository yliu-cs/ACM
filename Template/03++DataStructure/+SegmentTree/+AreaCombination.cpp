// HDU 1542 矩形面积并
#include <bits/stdc++.h>
typedef double db;
const int maxn = 1e2 + 5;
const db eps = 1e-9;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

struct seg {
  db l, r, h;
  int flag;
};
bool operator < (seg &k1, seg &k2) {return Cmp(k1.h, k2.h) < 0;}
std::vector<seg> segs;

std::vector<db> pos;

int BinarySearch(db k) {
  int ret = (int)pos.size() - 1, l = 0, r = (int)pos.size() - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (Cmp(pos[m], k) >= 0) {
      ret = m;
      r = m - 1;
    }
    else l = m + 1;
  }
  return ret;
}

struct node {
  int l, r, cnt;
  db len;
};
node seg_tree[maxn << 4];

void PushUp(int o) {
  if (seg_tree[o].cnt) seg_tree[o].len = pos[seg_tree[o].r + 1] - pos[seg_tree[o].l];
  else if (seg_tree[o].l == seg_tree[o].r) seg_tree[o].len = 0.0;
  else seg_tree[o].len = seg_tree[o << 1].len + seg_tree[o << 1 | 1].len;
}

void Build(int l, int r, int o) {
  seg_tree[o].l = l; seg_tree[o].r = r;
  seg_tree[o].cnt = 0; seg_tree[o].len = 0.0;
  if (l == r) return;
  int Mid = (l + r) >> 1;
  Build(l, Mid, o << 1);
  Build(Mid + 1, r, o << 1 | 1);
  PushUp(o);
}

void Update(int l, int r, int v, int o) {
  if (l <= seg_tree[o].l && r >= seg_tree[o].r) {
    seg_tree[o].cnt += v;
    PushUp(o);
    return;
  }
  int Mid = (seg_tree[o].l + seg_tree[o].r) >> 1;
  if (r <= Mid) Update(l, r, v, o << 1);
  else if (l > Mid) Update(l, r, v, o << 1 | 1);
  else {
    Update(l, Mid, v, o << 1);
    Update(Mid + 1, r, v, o << 1 | 1);
  }
  PushUp(o);
}

int cas;
int n;
db x1, y1, x2, y2;
db ans;

int main() {
  while (~scanf("%d", &n) && n) {
    segs.clear(); pos.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      segs.push_back((seg){x1, x2, y1, 1});
      segs.push_back((seg){x1, x2, y2, -1});
      pos.push_back(x1); pos.push_back(x2);
    }
    sort(segs.begin(), segs.end());
    sort(pos.begin(), pos.end(), [&](db k1, db k2) {return Cmp(k1, k2) < 0;});
    int Cur = 1;
    for (int i = 1; i < (int)pos.size(); ++i)
      if (Cmp(pos[i], pos[i - 1]) != 0)
        pos[Cur++] = pos[i];
    pos.erase(pos.begin() + Cur, pos.end());
    Build(0, (int)pos.size(), 1);
    ans = 0.0;
    for (int i = 0; i < (int)segs.size() - 1; ++i) {
      int l = BinarySearch(segs[i].l), r = BinarySearch(segs[i].r);
      Update(l, r - 1, segs[i].flag, 1);
      ans += (segs[i + 1].h - segs[i].h) * seg_tree[1].len;
    }
    printf("Test case #%d\n", ++cas);
    printf("Total explored area: %.2lf\n\n", ans);
  }
  return 0;
}