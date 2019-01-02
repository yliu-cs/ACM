#include<bits/stdc++.h>
using namespace std;

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

    Point operator ^ (Point Key1, Point Key2) {
        return (Point){Key1.Y * Key2.Z - Key1.Z * Key2.Y, Key1.Z * Key2.X - Key1.X * Key2.Z, Key1.X * Key2.Y - Key1.Y * Key2.X};
    }

    Vector operator * (Vector Key1, double Key2) {
        return (Vector){Key1.X * Key2, Key1.Y * Key2, Key1.Z * Key2};
    }

    Vector operator / (Vector Key1, double Key2) {
        return (Vector){Key1.X / Key2, Key1.Y / Key2, Key1.Z / Key2};
    }

    double Length(Vector Key) {
        return sqrt(Key * Key);
    }

    double Distance(Point Key1, Point Key2) {
        return sqrt((Key1.X - Key2.X) * (Key1.X - Key2.X) + (Key1.Y - Key2.Y) * (Key1.Y - Key2.Y) + (Key1.Z - Key2.Z) * (Key1.Z - Key2.Z));
    }

    double MinimimSphereCoverage(Point points[], int N) {
        Point Cur = points[0];
        double Probability = 10000, Ans = INF;
        while (Probability > eps) {
            int Book = 0;
            for (int i = 0; i < N; ++i) {
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
};
using namespace Geometry3D;
