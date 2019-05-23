namespace Geometry {
  typedef double db;
  const db inf = "Edit";
  const int maxn = "Edit";
  const db eps = "Edit";
  const db delta = 0.98;

  int Sgn(db k) { return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
  int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
  db Max(db k1, db k2) { return Cmp(k1, k2) > 0 ? k1 : k2; }
  db Min(db k1, db k2) { return Cmp(k1, k2) < 0 ? k1 : k2; }

  struct point { db x, y; };
  bool operator == (point k1, point k2) { return Cmp(k1.x, k2.x) == 0 && Cmp(k1.y, k2.y) == 0; }
  point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
  point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
  db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
  db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
  point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2}; }
  point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2}; }
  db GetLen(point k) { return sqrt(k * k); }
  point GetUnit(point k) { db len = Getlen(k); return (point){k.x / len, k.y / len}; }
  db GetDisP2P(point k1, point k2) { return sqrt((k1 - k2) * (k1 - k2)); }
  db GetDisP2P2(point k1, point k2) { return (k1 - k2) * (k1 - k2); }
  db GetAng(point k1, point k2) { return fabs(atan2(fabs(k1 ^ k2), k1 * k2)); }
  point Rotate(point k, db ang) { return (point){k.x * cos(ang) - k.y * sin(ang), k.x * sin(ang) + k.y * cos(ang)}; }
  point Rotate90(point k) { return (point){-k.y, k.x}; }
  bool IsConvexhull(const std::vector<point> &p) {
    int sz = (int)p.size();
    for (int i = 0; i < sz; ++i)
      if (Sgn((p[(i + 1) % sz] - p[i]) ^ (p[(i + 2) % sz] - p[(i + 1) % sz])) < 0)
        return false;
    return true;
  }
  db ClosestP2P(point p[], int l, int r) {
    if (l + 1 == r) return GetDisP2P(p[l], p[r]);
    if (l + 2 == r) return Min(GetDisP2P(p[l + 1], p[r]), Min(GetDisP2P(p[l], p[l + 1]), GetDisP2P(p[l], p[r])));
    int mid = (l + r) >> 1;
    db ret = Min(ClosestP2P(l, mid), ClosestP2P(mid + 1, r));
    std::vector<point> mid_p;
    for (int i = l; i <= r; ++i) {
      if (Cmp(fabs(p[i].x - p[mid].x), ret) <= 0) mid_p.push_back(p[i]);
    }
    std::sort(mid_p.begin(), mid_p.end(), [&](point k1, point k2) { return Cmp(k1.y, k2.y) < 0; });
    for (int i = 0; i < (int)mid_p.size(); ++i) {
      for (int j = i + 1; j < (int)mid_p.size(); ++j) {
        if (Cmp(mid_p[j].y - mid_p[i].y, ret) >= 0) break;
        ret = Min(ret, GetDisP2P(mid_p[i], mid_p[j]));
      }
    }
    return ret;
  }
  typedef std::vector<point> poly;
  db RotateCaliper(poly p) {
    db ret = -inf;
    if ((int)p.size() == 3) {
      if (Cmp(GetDisP2P(p[0], p[1]), ret) > 0) ret = GetDisP2P(p[0], p[1]);
      if (Cmp(GetDisP2P(p[0], p[2]), ret) > 0) ret = GetDisP2P(p[0], p[2]);
      if (Cmp(GetDisP2P(p[1], p[2]), ret) > 0) ret = GetDisP2P(p[1], p[2]);
      return;
    }
    int cur = 2, size = (int)p.size();
    for (int i = 0; i < size; ++i) {
      while (Cmp(fabs((p[i] - p[(i + 1) % size]) ^ (p[cur] - p[(i + 1) % size])), fabs((p[i] - p[(i + 1) % size]) ^ (p[(cur + 1) % size] - p[(i + 1) % size]))) < 0) cur = (cur + 1) % size;
      if (Cmp(GetDisP2P(p[i], p[cur]), ret) > 0) ret = GetDisP2P(p[i], p[cur]);
    }
    return ret;
  }
  poly Grahamscan(std::vector<point> p) {
    poly ret;
    if ((int)p.size() < 3) {
      for (point &v : p) ret.emplace_back(v);
      return ret;
    }
    int idx = 0;
    for (int i = 0; i < (int)p.size(); ++i)
      if (Cmp(p[i].x, p[idx].x) < 0 || (Cmp(p[i].x, p[idx].x) == 0 && Cmp(p[i].y, p[idx].y) < 0))
        idx = i;
    std::swap(p[0], p[idx]);
    std::sort(p.begin() + 1, p.end(), [&](point k1, point k2) {
      db tmp = (k1 - p[0]) ^ (k2 - p[0]);
      if (Sgn(tmp) > 0) return true;
      else if (Sgn(tmp) == 0 && Cmp(GetDisP2P(k1, p[0]), GetDisP2P(k2, p[0])) < 0) return true;
      return false;
    });
    ret.emplace_back(p[0]);
    for (int i = 1; i < (int)p.size(); ++i) {
      while ((int)ret.size() >= 2 && Sgn((ret.back() - ret[(int)ret.size() - 2]) ^ (p[i] - ret[(int)ret.size() - 2])) <= 0) ret.pop_back();
      ret.emplace_back(p[i]);
    }
    return ret;
  }
  bool IsIn(point p, const poly &ch) {
    point base = ch[0];
    if (Sgn((p - base) ^ (ch[1] - p)) > 0 || Sgn((p - base) ^ (ch.back() - base)) < 0) return false;
    if (Sgn((p - base) ^ (ch[1] - p)) == 0 && Cmp(GetLen(p - base), GetLen(ch[1] - base)) <= 0) return true;
    int idx = std::lower_bound(ch.begin(), ch.end(), p, [&] (point k1, point k2) { return Sgn((k1 - base) ^ (k2 - base)) > 0; }) - ch.begin() - 1;
    return Sgn((ch[idx + 1] - ch[idx]) ^ (p - ch[idx])) >= 0;
  }
  poly Minkowski(const poly &k1, const poly &k2) {
    int sz1 = (int)k1.size(), sz2 = (int)k2.size();
    std::queue<point> buf1, buf2;
    for (int i = 0; i < sz1; ++i) buf1.push(k1[(i + 1) % sz1] - k1[i]);
    for (int i = 0; i < sz2; ++i) buf2.push(k2[(i + 1) % sz2] - k2[i]);
    poly ret;
    ret.push_back(k1[0] + k2[0]);
    while (!buf1.empty() && !buf2.empty()) {
      point tmp1 = buf1.front(), tmp2 = buf2.front();
      if (Sgn(tmp1 ^ tmp2) > 0) {
        ret.push_back(ret.back() + tmp1);
        buf1.pop();
      }
      else {
        ret.push_back(ret.back() + tmp2);
        buf2.pop();
      }
    }
    while (!buf1.empty()) {
      ret.push_back(ret.back() + buf1.front());
      buf1.pop();
    }
    while (!buf2.empty()) {
      ret.push_back(ret.back() + buf2.front());
      buf2.pop();
    }
    return Grahamscan(ret);
  }
  db GetMinCircle(std::vector<point> p) {
    point cur = p[0];
    db pro = 10000, ret = inf;
    while (pro > eps) {
      int book = 0;
      for (int i = 0; i < (int)p.size(); ++i)
        if (GetDisP2P(cur, p[i]) > GetDisP2P(cur, p[book]))
          book = i;
      db r = GetDisP2P(cur, p[book]);
      if (Cmp(r, ret) < 0) ret = r;
      cur = cur + (p[book] - cur) / r * pro;
      pro *= delta;
    }
    return ret;
  }

  struct line { point s, t; };
  typedef line seg;
  db GetLen(seg k) { return GetDisP2P(k.s, k.t); }
  db GetDisP2Line(point k1, line k2) { return fabs((k1 - k2.s) ^ (k2.t - k2.s)) / GetLen(k2); }
  db GetDisP2Seg(point k1, seg k2) {
    if (Sgn((k1 - k2.s) * (k2.t - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) {
      return Min(GetDisP2P(k1, k2.s), GetDisP2P(k1, k2.t));
    }
    return GetDisP2Line(k1, k2);
  }
  bool IsParallel(line k1, line k2) { return Sgn((k1.s - k1.t) ^ (k2.s - k2.t)) == 0; }
  bool IsSegInterSeg(seg k1, seg k2) {
    return
      Max(k1.s.x, k1.t.x) >= Min(k2.s.x, k2.t.x) &&
      Max(k2.s.x, k2.t.x) >= Min(k1.s.x, k1.t.x) &&
      Max(k1.s.y, k1.t.y) >= Min(k2.s.y, k2.t.y) &&
      Max(k2.s.y, k2.t.y) >= Min(k1.s.y, k1.t.y) &&
      Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0 &&
      Sgn((k1.s - k2.t) ^ (k2.s - k2.t)) * Sgn((k1.t - k2.t) ^ (k2.s - k2.t)) <= 0;
  }
  bool IsLineInterSeg(line k1, seg k2) {
    return Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0;
  }
  bool IsLineInterLine(line k1, line k2) {
    return !IsParallel(k1, k2) || (IsParallel(k1, k2) && !(Sgn((k1.s - k2.s) ^ (k2.t - k2.s)) == 0));
  }
  bool IsPointOnSeg(point k1, seg k2) {
    return Sgn((k1 - k2.s) ^ (k2.t - k2.s)) == 0 && Sgn((k1 - k2.s) * (k1 - k2.t)) <= 0;
  }
  point Cross(line k1, line k2) {
    db temp = ((k1.s - k2.s) ^ (k2.s - k2.t)) / ((k1.s - k1.t) ^ (k2.s - k2.t));
    return (point){k1.s.x + (k1.t.x - k1.s.x) * temp, k1.s.y + (k1.t.y - k1.s.y) * temp};
  }

  // 表示s->t逆时针(左侧)的半平面
  struct hulfplane:public line { db ang; };
  void GetAng(halfplane k) { k.ang = atan2(k.t.y - k.s.y, k.t.x - k.s.x); }
  bool operator < (halfplane k1, halfplane k2) {
    if (Sgn(k1.ang - k2.ang) > 0) return k1.ang < k2.ang;
    return Sgn((k1.s - k2.s) ^ (k2.t - k2.s)) < 0;
  }
  struct HalfPlaneInsert {
    int tot;
    halfplane hp[maxn];
    halfplane deq[maxn];
    point points[maxn];
    point res[maxn];
    int front, tail;

    void Push(halfplane k) { hp[tot++] = k; }

    void Unique() {
      int cnt = 1;
      for (int i = 1; i < tot; ++i)
        if (fabs(hp[i].ang - hp[i - 1].ang) > eps)
          hp[cnt++] = hp[i];
      tot = cnt;
    }

    bool IsHalfPlaneInsert() {
      for (int i = 0; i < tot; ++i) GetAng(hp[i]);
      sort(hp, hp + tot);
      Unique();
      deq[front = 0] = hp[0];
      deq[tail = 1] = hp[1];
      for (int i = 2; i < tot; ++i) {
        if (fabs((deq[tail].t - deq[tail].s) ^ (deq[tail - 1].t - deq[tail - 1].s)) < eps || fabs((deq[front].t - deq[front].s) ^ (deq[front + 1].t - deq[front + 1].s)) < eps) return false;
        while (front < tail && ((Cross(deq[tail], deq[tail - 1]) - hp[i].s) ^ (hp[i].t - hp[i].s)) > eps) tail--;
        while (front < tail && ((Cross(deq[front], deq[front + 1]) - hp[i].s) ^ (hp[i].t - hp[i].s)) > eps) front++;
        deq[++tail] = hp[i];
      }
      while (front < tail && ((Cross(deq[tail], deq[tail - 1]) - deq[front].s) ^ (deq[front].t - deq[front].s)) > eps) tail--;
      while (front < tail && ((Cross(deq[front], deq[front - 1]) - deq[tail].s) ^ (deq[tail].t - deq[tail].t)) > eps) front++;
      if (tail <= front + 1) return false;
      return true;
    }

    void GetHalfPlaneInsertConvex() {
      int cnt = 0;
      for (int i = front; i < tail; ++i) res[cnt++] = Cross(deq[i], deq[i + 1]);
      if (front < tail - 1) res[cnt++] = Cross(deq[front], deq[tail]);
    }
  };

  struct circle {point o; db r;};
  std::pair<point, pair> TangentP2Cir(circle k1, point k2) {
    db a = GetLen(k2 - k1.o), b = k1.r * k1.r / a, c = sqrt(Max(0.0, k1.r * k1.r - b * b));
    point k = GetUnit(k2 - k1.o), m = k1.o + k * b, del = Rotate90(k) * c;
    return {m - del, m + del};
  }
  circle GetCircle(point k1, point k2, point k3) {
    db a1 = k2.x - k1.x, b1 = k2.y - k1.y, c1 = (a1 * a1 + b1 * b1) / 2;
    db a2 = k3.x - k1.x, b2 = k3.y - k1.y, c2 = (a2 * a2 + b2 * b2) / 2;
    db d = a1 * b2 - a2 * b1;
    point o = (point){k1.x + (c1 * b2 - c2 * b1) / d, k1.y + (a1 * c2 - a2 * c1) / d};
    return (circle){o, GetDisP2P(k1, o)};
  }
  circle GetMinCircle(std::vector<point> p) {
    std::random_shuffle(p.begin(), p.end());
    int n = (int)p.size();
    circle ret = (circle){p[0], 0.0};
    for (int i = 1; i < n; ++i) {
      if (Cmp(GetDisP2P(ret.o, p[i]), ret.r) <= 0) continue;
      ret = (circle){p[i], 0.0};
      for (int j = 0; j < i; ++j) {
        if (Cmp(GetDisP2P(ret.o, p[j]), ret.r) <= 0) continue;
        ret.o = (p[i] + p[j]) / 2; ret.r = GetDisP2P(ret.o, p[i]);
        for (int k = 0; k < j; ++k) {
          if (Cmp(GetDisP2P(ret.o, p[k]), ret.r) <= 0) continue;
          ret = GetCircle(p[i], p[j], p[k]);
        }
      }
    }
    return ret;
  }
};
using namespace Geometry;

