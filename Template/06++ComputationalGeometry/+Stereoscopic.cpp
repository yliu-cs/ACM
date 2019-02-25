#include<bits/stdc++.h>

namespace Geometry3D {
    typedef double db;
    const db INF = 1e20;
    const int maxn = "Edit";
    const db eps = 1e-9;
    const db delta = 0.98;

    int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
    int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}

    /*----------点(向量)----------*/
    struct Point {db X, Y, Z;};
    typedef Point Vector;
    bool operator == (Point Key1, Point Key2) {return Sgn(Key1.X - Key2.X) == 0 && Sgn(Key1.Y - Key2.Y) == 0 && Sgn(Key1.Z - Key1.Z) == 0;}
    Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y, Key1.Z + Key2.Z};}
    Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};}
    db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y + Key1.Z * Key2.Z;}
    db GetLen(Vector Key) {return sqrt(Key * Key);}
    db GetLen2(Vector Key) {return Key * Key;}
    db operator ^ (Vector Key1, Vector Key2) {return GetLen((Vector){Key1.Y * Key2.Z - Key1.Z * Key2.Y, Key1.Z * Key2.X - Key1.X * Key2.Z, Key1.X * Key2.Y - Key1.Y * Key2.X});}
    Vector operator * (Vector Key1, db Key2) {return (Vector){Key1.X * Key2, Key1.Y * Key2, Key1.Z * Key2};}
    Vector operator / (Vector Key1, db Key2) {return (Vector){Key1.X / Key2, Key1.Y / Key2, Key1.Z / Key2};}
    db DisPointToPoint(Point Key1, Point Key2) {return GetLen(Key2 - Key1);}
    db DisPointToPoint2(Point Key1, Point Key2) {return GetLen2(Key2 - Key1);}
    db GetAngle(Vector Key1, Vector Key2) {return fabs(atan2(fabs(Key1 ^ Key2), Key1 * Key2));}

    db MinimimSphereCoverage(vector<Point> points, int N) {
        Point Cur = points[0];
        db Probability = 10000, Ans = INF;
        while (Probability > eps) {
            int Book = 0;
            for (int i = 0; i < (int)points.size(); ++i) {
                if (Cmp(Distance(Cur, points[i]), Distance(Cur, points[Book])) > 0) {
                    Book = i;
                }
            }
            db Radius = Distance(Cur, points[Book]);
            Ans = min(Ans, Radius);
            Cur = Cur + (points[Book] - Cur) / Radius * Probability;
            Probability *= delta;
        }
        return Ans;
    }

    /*----------线(线段)----------*/
    struct Line {Point S, T;};
    typedef Line Segment;
    db Length(Segment Key) {return DisPointToPoint(Key.S, Key.T);}
    db DisPointToLine(Point Key1, Line Key2) {return fabs((Key1 - Key2.S) ^ (Key2.T - Key2.S)) / Length(Key2);}
    db DisPointToSeg(Point Key1, Segment Key2) {
        if (Sgn((Key1 - Key2.S) * (Key2.T - Key2.S)) < 0 || Sgn((Key1 - Key2.T) * (Key2.S - Key2.T)) < 0) {
            return min(DisPointToPoint(Key1, Key2.S), DisPointToPoint(Key1, Key2.T));
        }
        return DisPointToLine(Key1, Key2);
    }

    /*----------球----------*/
    struct Sphere {Point Center;db Radius;};
    db GetVolume(Sphere Key) {return 4.0 / 3.0 * pi * Key.Radius * Key.Radius * Key.Radius;}
    db SphereIntersectVolume(Sphere Key1, Sphere Key2) {
        db Ans = 0.0;
        db Dis = DisPointToPoint(Key1.Center, Key2.Center);
        if (Sgn(Dis - Key1.Radius - Key2.Radius) >= 0) {
            return Ans;
        }
        if (Sgn(Key2.Radius - (Dis + Key1.Radius)) >= 0) {
            return CalVolume(Key1);
        }
        else if (Sgn(Key1.Radius - (Dis + Key2.Radius)) >= 0) {
            return CalVolume(Key2);
        }
        db Length1 = ((Key1.Radius * Key1.Radius - Key2.Radius * Key2.Radius) / Dis + Dis) / 2;
        db Length2 = Dis - Length1;
        db X1 = Key1.Radius - Length1, X2 = Key2.Radius - Length2;
        db V1 = pi * X1 * X1 * (Key1.Radius - X1 / 3.0);
        db V2 = pi * X2 * X2 * (Key2.Radius - X2 / 3.0);
        return V1 + V2;
    }

    bool IsRayInterSphere(Ray Key1, Sphere Key2, db &Dis) {
        db A = Key1.Dir * Key1.Dir;
        db B = (Key1.Origin - Key2.Center) * Key1.Dir * 2.0;
        db C = ((Key1.Origin - Key2.Center) * (Key1.Origin - Key2.Center)) - (Key2.Radius * Key2.Radius);
        db Delta = B * B - 4.0 * A * C;
        if (Sgn(Delta) < 0) return false;
        db X1 = (-B - sqrt(Delta)) / (2.0 * A), X2 = (-B + sqrt(Delta)) / (2.0 * A);
        if (Cmp(X1, X2) > 0) swap(X1, X2);
        if (Sgn(X1) <= 0) return false;
        Dis = X1;
        return true;
    }

    void Reflect(Ray &Key1, Sphere Key2, db Dis) {
        Point Pos = Key1.Origin + (Key1.Dir * Dis);
        Vector Temp = Key2.Center + (((Pos - Key2.Center) * ((Pos - Key2.Center) * (Key1.Origin - Key2.Center))) / GetLen2(Pos - Key2.Center));
        Key1.Dir = Temp * 2.0 - Key1.Origin - Pos; Key1.Origin = Pos;
    }
};
using namespace Geometry3D;
