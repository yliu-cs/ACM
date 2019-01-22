#include<bits/stdc++.h>

namespace Geometry3D {
    const double INF = 1e20;
    const int maxn = "Edit";
    const double eps = 1e-8;
    const double delta = 0.98;

    int Sgn(double Key) {
        if (fabs(Key) < eps) {
            return 0;
        }
        return Key < 0 ? -1 : 1;
    }

    /*----------点(向量)----------*/
    struct Point {
        double X, Y, Z;
    };

    typedef Point Vector;

    bool operator == (Point Key1, Point Key2) {
        return Sgn(Key1.X - Key2.X) == 0 && Sgn(Key1.Y - Key2.Y) == 0 && Sgn(Key1.Z - Key1.Z) == 0;
    }

    Vector operator + (Vector Key1, Vector Key2) {
        return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y, Key1.Z + Key2.Z};
    }

    Vector operator - (Vector Key1, Vector Key2) {
        return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};
    }

    double operator * (Vector Key1, Vector Key2) {
        return Key1.X * Key2.X + Key1.Y * Key2.Y + Key1.Z * Key2.Z;
    }

    double Length(Vector Key) {
        return sqrt(Key * Key);
    }

    double operator ^ (Vector Key1, Vector Key2) {
        return Length((Vector){Key1.Y * Key2.Z - Key1.Z * Key2.Y, Key1.Z * Key2.X - Key1.X * Key2.Z, Key1.X * Key2.Y - Key1.Y * Key2.X});
    }

    Vector operator * (Vector Key1, double Key2) {
        return (Vector){Key1.X * Key2, Key1.Y * Key2, Key1.Z * Key2};
    }

    Vector operator / (Vector Key1, double Key2) {
        return (Vector){Key1.X / Key2, Key1.Y / Key2, Key1.Z / Key2};
    }

    double DisPointToPoint(Point Key1, Point Key2) {
        return sqrt((Key1 - Key2) * (Key1 - Key2));
    }

    double GetAngle(Vector Key1, Vector Key2) {
        return fabs(atan2(fabs(Key1 ^ Key2), Key1 * Key2));
    }

    double MinimimSphereCoverage(vector<Point> points, int N) {
        Point Cur = points[0];
        double Probability = 10000, Ans = INF;
        while (Probability > eps) {
            int Book = 0;
            for (int i = 0; i < (int)points.size(); ++i) {
                if (Distance(Cur, points[i]) > Distance(Cur, points[Book])) {
                    Book = i;
                }
            }
            double Radius = Distance(Cur, points[Book]);
            Ans = min(Ans, Radius);
            Cur = Cur + (points[Book] - Cur) / Radius * Probability;
            Probability *= delta;
        }
        return Ans;
    }

    /*----------线(线段)----------*/
    struct Line {
        Point S, T;
    };

    typedef Line Segment;

    double Length(Segment Key) {
        return DisPointToPoint(Key.S, Key.T);
    }

    double DisPointToLine(Point Key1, Line Key2) {
        return fabs((Key1 - Key2.S) ^ (Key2.T - Key2.S)) / Length(Key2);
    }

    double DisPointToSegment(Point Key1, Segment Key2) {
        if (Sgn((Key1 - Key2.S) * (Key2.T - Key2.S)) < 0 || Sgn((Key1 - Key2.T) * (Key2.S - Key2.T)) < 0) {
            return min(DisPointToPoint(Key1, Key2.S), DisPointToPoint(Key1, Key2.T));
        }
        return DisPointToLine(Key1, Key2);
    }

    /*----------球----------*/
    struct Sphere {
        Point Center;
        double Radius;
    };

    double CalVolume(Sphere Key) {
        return 4.0 / 3.0 * pi * Key.Radius * Key.Radius * Key.Radius;
    }

    double SphereIntersectVolume(Sphere Key1, Sphere Key2) {
        double Ans = 0.0;
        double Dis = DisPointToPoint(Key1.Center, Key2.Center);
        if (Sgn(Dis - Key1.Radius - Key2.Radius) >= 0) {
            return Ans;
        }
        if (Sgn(Key2.Radius - (Dis + Key1.Radius)) >= 0) {
            return CalVolume(Key1);
        }
        else if (Sgn(Key1.Radius - (Dis + Key2.Radius)) >= 0) {
            return CalVolume(Key2);
        }
        double Length1 = ((Key1.Radius * Key1.Radius - Key2.Radius * Key2.Radius) / Dis + Dis) / 2;
        double Length2 = Dis - Length1;
        double X1 = Key1.Radius - Length1, X2 = Key2.Radius - Length2;
        double V1 = pi * X1 * X1 * (Key1.Radius - X1 / 3.0);
        double V2 = pi * X2 * X2 * (Key2.Radius - X2 / 3.0);
        return V1 + V2;
    }
};
using namespace Geometry3D;
