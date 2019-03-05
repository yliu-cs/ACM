#include<bits/stdc++.h>

namespace Geometry {
    typedef double db;
    const db inf = 1e20;
    const int maxn = 1;
    const db eps = 1e-8;
    const db delta = 0.98;

    int Sgn(db k) { return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
    int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

    /*----------点(向量)----------*/
    struct point {db X, Y;};
    bool operator == (point k1, point k2) {return Cmp(k1.X, k2.X) == 0 && Cmp(k1.Y, k2.Y) == 0;}
    point operator + (point k1, point k2) {return (point){k1.X + k2.X, k1.Y + k2.Y};}
    point operator - (point k1, point k2) {return (point){k1.X - k2.X, k1.Y - k2.Y};}
    db operator * (point k1, point k2) {return k1.X * k2.X + k1.Y * k2.Y;}
    db operator ^ (point k1, point k2) {return k1.X * k2.Y - k1.Y * k2.X;}
    point operator * (point k1, db k2) {return (point){k1.X * k2, k1.Y * k2};}
    point operator / (point k1, db k2) {return (point){k1.X / k2, k1.Y / k2};}
    db GetLen(point k) {return sqrt(k * k);}
    db DisP2P(point k1, point k2) {return sqrt((k1 - k2) * (k1 - k2));}
    db DisP2P2(point k1, point k2) {return (k1 - k2) * (k1 - k2);}
    db GetAng(point k1, point k2) {return fabs(atan2(fabs(k1 ^ k2), k1 * k2));}
    point Rotate(point k, db ang) {return (point){k.X * cos(ang) - k.Y * sin(ang), k.X * sin(ang) + k.Y * cos(ang)};}
    point Rotate90(point k) {return (point){-k.Y, k.X};}
    bool IsConvexHull(vector<point> points) {
        int N = (int)points.size();
        for (int i = 0; i < N; ++i)
            if (Sgn((points[(i + 1) % N] - points[i]) ^ (points[(i + 2) % N] - points[(i + 1) % N])) < 0)
                return false;
        return true;
    }

    db ClosestP2P(point p[], int l, int r) {
        if (l + 1 == r) return GetDisP2P(p[l], p[r]);
        if (l + 2 == r) return min(GetDisP2P(p[l + 1], p[r]), min(GetDisP2P(p[l], p[l + 1]), GetDisP2P(p[l], p[r])));
        int mid = (l + r) >> 1;
        db ans = min(solve(l, mid), solve(mid + 1, r));
        vector<point> mid_p;
        for (int i = l; i <= r; ++i) {
            if (Cmp(fabs(p[i].x - p[mid].x), ans) <= 0) mid_p.push_back(p[i]);
        }
        sort(mid_p.begin(), mid_p.end(), [&](point k1, point k2) {return Cmp(k1.y, k2.y) < 0;});
        for (int i = 0; i < mid_p.size(); ++i) {
            for (int j = i + 1; j < mid_p.size(); ++j) {
                if (Cmp(mid_p[j].y - mid_p[i].y, ans) >= 0) break;
                ans = min(ans, GetDisP2P(mid_p[i], mid_p[j]));
            }
        }
        return ans;
    }

    /*----------多边形----------*/
    typedef vector<point> poly;
    void RotateCaliper() {
        ans = -1e20;
        if (ConvexHull.size() == 3) {
            if (Cmp(Dispointtopoint2(ConvexHull[0], ConvexHull[1]), ans) > 0) ans = Dispointtopoint2(ConvexHull[0], ConvexHull[1]);
            if (Cmp(Dispointtopoint2(ConvexHull[0], ConvexHull[2]), ans) > 0) ans = Dispointtopoint2(ConvexHull[0], ConvexHull[2]);
            if (Cmp(Dispointtopoint2(ConvexHull[1], ConvexHull[2]), ans) > 0) ans = Dispointtopoint2(ConvexHull[1], ConvexHull[2]);
            return;
        }
        int cur = 2, size = ConvexHull.size();
        for (int i = 0; i < size; ++i) {
            while (Cmp(fabs((ConvexHull[i] - ConvexHull[(i + 1) % size]) ^ (ConvexHull[cur] - ConvexHull[(i + 1) % size])), fabs((ConvexHull[i] - ConvexHull[(i + 1) % size]) ^ (ConvexHull[(cur + 1) % size] - ConvexHull[(i + 1) % size]))) < 0) cur = (cur + 1) % size;
            if (Cmp(Dispointtopoint2(ConvexHull[i], ConvexHull[cur]), ans) > 0) ans = Dispointtopoint2(ConvexHull[i], ConvexHull[cur]);
        }
    }

    poly Grahamscan(point points[], int N) {
        poly ans;
        if (N < 3) {
            for (int i = 0; i < N; ++i) ans.push_back(points[i]);
            return ans;
        }
        int Basic = 0;
        for (int i = 0; i < N; ++i)
            if (Cmp(points[i].X, points[Basic].X) < 0 || (Cmp(points[i].X, points[Basic].X) == 0 && Cmp(points[i].Y, points[Basic].Y) < 0))
                Basic = i;
        std::swap(points[0], points[Basic]);
        std::sort(points + 1, points + N, [&](point k1, point k2) {
            double temp = (k1 - points[0]) ^ (k2 - points[0]);
            if (Sgn(temp) > 0) return true;
            else if (Sgn(temp) == 0 && Cmp(Dispointtopoint(k2, points[0]), Dispointtopoint(k1, points[0])) > 0) return true;
            return false;
        });
        ans.push_back(points[0]);
        for (int i = 1; i < N; ++i) {
            while ((int)ans.size() >= 2 && Sgn((ans.back() - ans[(ans.size()) - 2]) ^ (points[i] - ans[(int)ans.size() - 2])) <= 0) {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        return ans;
    }

    db MinCircleCoverage(vector<point> points) {
        point cur = points[0];
        db Probability = 10000, ans = inf;
        while (Probability > eps) {
            int Book = 0;
            for (int i = 0; i < (int)points.size(); ++i)
                if (Distance(cur, points[i]) > Distance(cur, points[Book]))
                    Book = i;
            db r = Distance(cur, points[Book]);
            if (Cmp(r, ans) < 0) ans = r;
            cur = cur + (points[Book] - cur) / r * Probability;
            Probability *= delta;
        }
        return ans;
    }

    /*----------线(线段)----------*/
    struct line {point s, t;};
    typedef line seg;
    db GetLen(seg k) {return Disp2p(k.s, k.t);}
    db DisP2Line(point k1, line k2) {return fabs((k1 - k2.s) ^ (k2.t - k2.s)) / Length(k2);}
    db DisP2Seg(point k1, seg k2) {
        if (Sgn((k1 - k2.s) * (k2.t - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) {
            return min(Dispointtopoint(k1, k2.s), Dispointtopoint(k1, k2.t));
        }
        return Dispointtoline(k1, k2);
    }
    bool IsParallel(line k1, line k2) {return Sgn((k1.s - k1.t) ^ (k2.s - k2.t)) == 0;}
    bool IsSegInterSeg(seg k1, seg k2) {
        return
            max(k1.s.X, k1.t.X) >= min(k2.s.X, k2.t.X) &&
            max(k2.s.X, k2.t.X) >= min(k1.s.X, k1.t.X) &&
            max(k1.s.Y, k1.t.Y) >= min(k2.s.Y, k2.t.Y) &&
            max(k2.s.Y, k2.t.Y) >= min(k1.s.Y, k1.t.Y) &&
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
        return (point){k1.s.X + (k1.t.X - k1.s.X) * temp, k1.s.Y + (k1.t.Y - k1.s.Y) * temp};
    }

    /*----------半平面----------*/
    // 表示s->t逆时针(左侧)的半平面
    struct hulfplane:public line {db ang;};
    void CalAng(halfplane k) {k.ang = atan2(k.t.Y - k.s.Y, k.t.X - k.s.X);}
    bool operator < (halfplane k1, halfplane k2) {
        if (Sgn(k1.ang - k2.ang) > 0) return k1.ang < k2.ang;
        return Sgn((k1.s - k2.s) ^ (k2.t - k2.s)) < 0;
    }
    struct HalfPlaneInsert {
        int tot;
        halfplane hp[maxn];
        halfplane deq[maxn];
        point points[maxn];
        point Res[maxn];
        int front, tail;

        void Push(halfplane k) {hp[tot++] = k;}

        void Unique() {
            int Cnt = 1;
            for (int i = 1; i < tot; ++i)
                if (fabs(hp[i].ang - hp[i - 1].ang) > eps)
                    hp[Cnt++] = hp[i];
            tot = Cnt;
        }

        bool IsHalfPlaneInsert() {
            for (int i = 0; i < tot; ++i) CalAngle(hp[i]);
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
            if (tail <= front + 1) {
                return false;
            }
            return true;
        }

        void GetHalfPlaneInsertConvex() {
            int Cnt = 0;
            for (int i = front; i < tail; ++i) Res[Cnt++] = Cross(deq[i], deq[i + 1]);
            if (front < tail - 1) Res[Cnt++] = Cross(deq[front], deq[tail]);
        }
    };

    /*----------圆----------*/
    struct Circle {point o; db r;};
};
using namespace Geometry;

