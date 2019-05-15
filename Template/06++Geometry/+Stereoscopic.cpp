namespace Geometry3D {
  typedef double db;
  const db inf = "Edit";
  const int maxn = "Edit";
  const db eps = "Edit";
  const db delta = 0.98;

  int Sgn(db k) { return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
  int Cmp(db k1, db k2) { return Sgn(k1 - k2); }

  struct point { db x, y, z; };
  bool operator == (point k1, point k2) { return Sgn(k1.x - k2.x) == 0 && Sgn(k1.y - k2.y) == 0 && Sgn(k1.z - k1.z) == 0; }
  point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y, k1.z + k2.z}; }
  point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y, k1.z - k2.z}; }
  db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y + k1.z * k2.z; }
  db GetLen(point k) { return sqrt(k * k); }
  db GetLen2(point k) { return k * k; }
  db operator ^ (point k1, point k2) { return GetLen((point){k1.y * k2.z - k1.z * k2.y, k1.z * k2.x - k1.x * k2.z, k1.x * k2.y - k1.y * k2.x}); }
  point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2, k1.z * k2}; }
  point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2, k1.z / k2}; }
  db GetDisP2P(point k1, point k2) { return GetLen(k2 - k1); }
  db GetDisP2P2(point k1, point k2) { return GetLen2(k2 - k1); }
  db GetAngle(point k1, point k2) { return fabs(atan2(fabs(k1 ^ k2), k1 * k2)); }
  db GetMinSphere(std::vector<point> p) {
    point cur = p[0];
    db pro = 10000, ret = inf;
    while (pro > eps) {
      int mark = 0;
      for (int i = 0; i < (int)p.size(); ++i) {
        if (Cmp(GetDisP2P(cur, p[i]), GetDisP2P(cur, p[mark])) > 0) mark = i;
      }
      db r = GetDisP2P(cur, p[mark]);
      ret = min(ret, r);
      cur = cur + (p[mark] - cur) / r * pro;
      pro *= delta;
    }
    return ret;
  }

  struct line { point s, t; };
  typedef line seg;
  db GetLen(seg k) { return GetDisP2P(k.s, k.t); }
  db GetLe2(seg k) { return GetDisP2P2(k.s, k.t); }
  db GetDisP2Line(point k1, line k2) { return fabs((k1 - k2.s) ^ (k2.t - k2.s)) / GetLen(k2); }
  db GetDisP2Seg(point k1, seg k2) {
    if (Sgn((k1 - k2.s) * (k2.T - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) {
      return min(GetDisP2P(k1, k2.s), GetDisP2P(k1, k2.t));
    }
    return GetDisP2Line(k1, k2);
  }
  struct sphere { point o;db r; };
  db GetV(sphere k) { return 4.0 / 3.0 * pi * k.r * k.r * k.r; }
  db GetSphereInterV(sphere k1, sphere k2) {
    db ret = 0.0;
    db dis = GetDisP2P(k1.o, k2.o);
    if (Sgn(dis - k1.r - k2.r) >= 0) return ret;
    if (Sgn(k2.r - (dis + k1.r)) >= 0) return GetV(k1);
    else if (Sgn(k1.r - (dis + k2.r)) >= 0) return GetV(k2);
    db len1 = ((k1.r * k1.r - k2.r * k2.r) / dis + dis) / 2;
    db len2 = dis - len1;
    db x1 = k1.r - len1, x2 = k2.r - len2;
    db v1 = pi * x1 * x1 * (k1.r - x1 / 3.0);
    db v2 = pi * x2 * x2 * (k2.r - x2 / 3.0);
    return v1 + v2;
  }

  struct ray { point o, dir; };
  bool IsRayInterSphere(ray k1, sphere k2, db &dis) {
    db a = k1.dir * k1.dir;
    db b = (k1.o - k2.o) * k1.dir * 2.0;
    db c = ((k1.o - k2.o) * (k1.o - k2.o)) - (k2.r * k2.r);
    db dlt = b * b - 4.0 * a * c;
    if (Sgn(dlt) < 0) return false;
    db x1 = (-b - sqrt(dlt)) / (2.0 * a), x2 = (-b + sqrt(dlt)) / (2.0 * a);
    if (Cmp(x1, x2) > 0) swap(x1, x2);
    if (Sgn(x1) <= 0) return false;
    dis = x1;
    return true;
  }
  void Reflect(ray &k1, sphere k2, db dis) {
    point pos = k1.o + (k1.dir * dis);
    Vector temp = k2.o + (((pos - k2.o) * ((pos - k2.o) * (k1.o - k2.o))) / GetLen2(pos - k2.o));
    k1.dir = temp * 2.0 - k1.o - pos; k1.o = pos;
  }
};
using namespace Geometry3D;

