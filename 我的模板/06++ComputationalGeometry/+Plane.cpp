#include<bits/stdc++.h>

namespace Geometry {
    const double INF = 1e20;
    const int maxn = 1;
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
        double X, Y;
    };

    typedef Point Vector;

    bool operator == (Point Key1, Point Key2) {
        return Sgn(Key1.X - Key2.X) == 0 && Sgn(Key1.Y - Key2.Y) == 0;
    }

    Vector operator + (Vector Key1, Vector Key2) {
        return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};
    }

    Vector operator - (Vector Key1, Vector Key2) {
        return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};
    }

    double operator * (Vector Key1, Vector Key2) {
        return Key1.X * Key2.X + Key1.Y * Key2.Y;
    }

    double operator ^ (Vector Key1, Vector Key2) {
        return Key1.X * Key2.Y - Key1.Y * Key2.X;
    }

    Vector operator * (Vector Key1, double Key2) {
        return (Vector){Key1.X * Key2, Key1.Y * Key2};
    }

    Vector operator / (Vector Key1, double Key2) {
        return (Vector){Key1.X / Key2, Key1.Y / Key2};
    }

    double Length(Vector Key) {
        return sqrt(Key * Key);
    }

    double Distance(Point Key1, Point Key2) {
        return sqrt((Key2 - Key1) * (Key2 - Key1));
    }

    bool IsConvexHull(vector<Point> points) {
        int N = (int)points.size();
        for (int i = 0; i < N; ++i) {
            if (Sgn((points[(i + 1) % N] - points[i]) ^ (points[(i + 2) % N] - points[(i + 1) % N])) < 0) {
                return false;
            }
        }
        return true;
    }

    /*----------多边形----------*/
    typedef vector<Point> Polygon;

    Polygon ConvexHull(vector<Point> points) {
        int N = (int)points.size();
        Polygon Ans;
        if (N < 3) {
            return Ans;
        }
        int Basic = 0;
        for (int i = 0; i < N; ++i) {
            if (points[i].Y > points[Basic].Y || (points[i].Y == points[Basic].Y && points[i].X < points[Basic].X)) {
                    Basic = i;
            }
        }
        std::swap(points[0], points[Basic]);
        std::sort(points.begin() + 1, points.end(), [&] (Point &Key1, Point &Key2) {
            double Temp = (Key1 - points[0]) ^ (Key2 - points[0]);
            if (Temp > 0) {
                return true;
            }
            else if (!Temp && Distance(Key1, points[0]) < Distance(Key2, points[0])) {
                return true;
            }
            return false;
        });
        Ans.push_back(points[0]);
        for (int i = 2; i < N; ++i) {
            while ((int)Ans.size() >= 2 && Sgn((Ans.back() - Ans[(Ans.size()) - 2]) ^ (points[i] - Ans[(int)Ans.size() - 2])) <= 0) {
                Ans.pop_back();
            }
        }
        return Ans;
    }

    double MinimimCircleCoverage(vector<Point> points) {
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

    bool IsParallel(Line Key1, Line Key2) {
        return Sgn((Key1.S - Key1.T) ^ (Key2.S - Key2.T)) == 0;
    }

    bool IsSegInterSeg(Segment Key1, Segment Key2) {
        return
            max(Key1.S.X, Key1.T.X) >= min(Key2.S.X, Key2.T.X) &&
            max(Key2.S.X, Key2.T.X) >= min(Key1.S.X, Key1.T.X) &&
            max(Key1.S.Y, Key1.T.Y) >= min(Key2.S.Y, Key2.T.Y) &&
            max(Key2.S.Y, Key2.T.Y) >= min(Key1.S.Y, Key1.T.Y) &&
            Sgn((Key2.S - Key1.T) ^ (Key1.S - Key1.T)) * Sgn((Key2.T - Key1.T) ^ (Key1.S - Key1.T)) <= 0 &&
            Sgn((Key1.S - Key2.T) ^ (Key2.S - Key2.T)) * Sgn((Key1.T - Key2.T) ^ (Key2.S - Key2.T)) <= 0;
    }

    bool IsLineInterSeg(Line Key1, Segment Key2) {
        return Sgn((Key2.S - Key1.T) ^ (Key1.S - Key1.T)) * Sgn((Key2.T - Key1.T) ^ (Key1.S - Key1.T)) <= 0;
    }

    bool IsLineInterLine(Line Key1, Line Key2) {
        return !IsParallel(Key1, Key2) || (IsParallel(Key1, Key2) && !(Sgn((Key1.S - Key2.S) ^ (Key2.T - Key2.S)) == 0));
    }

    Point Cross(Line Key1, Line Key2) {
        double Temp = ((Key1.S - Key2.S) ^ (Key2.S - Key2.T)) / ((Key1.S - Key1.T) ^ (Key2.S - Key2.T));
        return (Point){Key1.S.X + (Key1.T.X - Key1.S.X) * Temp, Key1.S.Y + (Key1.T.Y - Key1.S.Y) * Temp};
    }

    /*----------半平面----------*/
    // 表示S->T逆时针(左侧)的半平面
    struct HalfPlane:public Line {
        double Angle;
    };

    void CalAngle(HalfPlane Key) {
        Key.Angle = atan2(Key.T.Y - Key.S.Y, Key.T.X - Key.S.X);
    }

    bool operator < (HalfPlane Key1, HalfPlane Key2) {
        if (Sgn(Key1.Angle - Key2.Angle) > 0) {
            return Key1.Angle < Key2.Angle;
        }
        return Sgn((Key1.S - Key2.S) ^ (Key2.T - Key2.S)) < 0;
    }

    struct HalfPlaneInsert {
        int Tot;
        HalfPlane halfplanes[maxn];
        HalfPlane Deque[maxn];
        Point points[maxn];
        Point Res[maxn];
        int Front, Tail;

        void Push(HalfPlane Key) {
            halfplanes[Tot++] = Key;
        }

        void Unique() {
            int Cnt = 1;
            for (int i = 1; i < Tot; ++i) {
                if (fabs(halfplanes[i].Angle - halfplanes[i - 1].Angle) > eps) {
                    halfplanes[Cnt++] = halfplanes[i];
                }
            }
            Tot = Cnt;
        }

        bool IsHalfPlaneInsert() {
            for (int i = 0; i < Tot; ++i) {
                CalAngle(halfplanes[i]);
            }
            sort(halfplanes, halfplanes + Tot);
            Unique();
            Deque[Front = 0] = halfplanes[0];
            Deque[Tail = 1] = halfplanes[1];
            for (int i = 2; i < Tot; ++i) {
                if (fabs((Deque[Tail].T - Deque[Tail].S) ^ (Deque[Tail - 1].T - Deque[Tail - 1].S)) < eps || fabs((Deque[Front].T - Deque[Front].S) ^ (Deque[Front + 1].T - Deque[Front + 1].S)) < eps) {
                    return false;
                }
                while (Front < Tail && ((Cross(Deque[Tail], Deque[Tail - 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > eps) {
                    Tail--;
                }
                while (Front < Tail && ((Cross(Deque[Front], Deque[Front + 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > eps) {
                    Front++;
                }
                Deque[++Tail] = halfplanes[i];
            }
            while (Front < Tail && ((Cross(Deque[Tail], Deque[Tail - 1]) - Deque[Front].S) ^ (Deque[Front].T - Deque[Front].S)) > eps) {
                Tail--;
            }
            while (Front < Tail && ((Cross(Deque[Front], Deque[Front - 1]) - Deque[Tail].S) ^ (Deque[Tail].T - Deque[Tail].T)) > eps) {
                Front++;
            }
            if (Tail <= Front + 1) {
                return false;
            }
            return true;
        }

        void GetHalfPlaneInsertConvex() {
            int Cnt = 0;
            for (int i = Front; i < Tail; ++i) {
                Res[Cnt++] = Cross(Deque[i], Deque[i + 1]);
            }
            if (Front < Tail - 1) {
                Res[Cnt++] = Cross(Deque[Front], Deque[Tail]);
            }
        }
    };

    /*----------圆----------*/
    struct Circle {
        Point Center;
        double Radius;
    };
};
using namespace Geometry;

