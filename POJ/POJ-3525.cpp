#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1e20;
const int maxn = 1e5 + 5;
const double eps = 1e-8;

struct Point {
    double X, Y;

    Point() {}
    Point(double _X, double _Y) {
        X = _X;
        Y = _Y;
    }

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point(X - B.X, Y - B.Y);
    }

    double operator * (const Point &B) const {
        return X * B.X + Y * B.Y;
    }

    double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }
};

double Distance(Point A, Point B) {
    return sqrt((A - B) * (A - B));
}

struct Segment {
    Point S, T;

    Segment() {}
    Segment(Point _S, Point _T) {
        S = _S;
        T = _T;
    }

    void Input() {
        S.Input();
        T.Input();
    }

    double operator ^ (const Segment &B) const {
        return (T - S) ^ (B.T - B.S);
    }

    Point operator & (const Segment &B) const {
        double Temp = ((S - B.S) ^ (B.S - B.T)) / ((S - T) ^ (B.S - B.T));
        return Point(S.X + (T.X - S.X) * Temp, S.Y + (T.Y - S.Y) * Temp);
    }
};

struct HalfPlane:public Segment {
    double Angle;

    HalfPlane() {}
    HalfPlane(Point _S, Point _T) {
        S = _S;
        T = _T;
    }
    HalfPlane(Segment ST) {
        S = ST.S;
        T = ST.T;
    }

    void CalAngle() {
        Angle = atan2(T.Y - S.Y, T.X - S.X);
    }

    bool operator < (const HalfPlane &B) const {
        if (fabs(Angle - B.Angle) > eps) {
            return Angle < B.Angle;
        }
        return ((S - B.S) ^ (B.T - B.S)) < 0;
    }
};

int Tot;
HalfPlane halfplanes[maxn];
HalfPlane Deque[maxn];
Point points[maxn];
Point Res[maxn];
int Front, Tail;

void Push(HalfPlane X) {
    halfplanes[Tot++] = X;
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

bool HalfPlaneInsert() {
    for (int i = 0; i < Tot; ++i) {
        halfplanes[i].CalAngle();
    }
    sort(halfplanes, halfplanes + Tot);
    Unique();
    Deque[Front = 0] = halfplanes[0];
    Deque[Tail = 1] = halfplanes[1];
    for (int i = 2; i < Tot; ++i) {
        if (fabs((Deque[Tail].T - Deque[Tail].S) ^ (Deque[Tail - 1].T - Deque[Tail - 1].S)) < eps || fabs((Deque[Front].T - Deque[Front].S) ^ (Deque[Front + 1].T - Deque[Front + 1].S)) < eps) {
            return false;
        }
        while (Front < Tail && (((Deque[Tail] & Deque[Tail - 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > eps) {
            Tail--;
        }
        while (Front < Tail && (((Deque[Front] & Deque[Front + 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > eps) {
            Front++;
        }
        Deque[++Tail] = halfplanes[i];
    }
    while (Front < Tail && (((Deque[Tail] & Deque[Tail - 1]) - Deque[Front].S) ^ (Deque[Front].T - Deque[Front].S)) > eps) {
        Tail--;
    }
    while (Front < Tail && (((Deque[Front] & Deque[Front - 1]) - Deque[Tail].S) ^ (Deque[Tail].T - Deque[Tail].T)) > eps) {
        Front++;
    }
    if (Tail <= Front + 1) {
        return false;
    }
    return true;
}

void Change(Point A, Point B, Point &X, Point &Y, double Dis) {
    double Len = Distance(A, B);
    double DX = (A.Y - B.Y) * Dis / Len, DY = (B.X - A.X) * Dis / Len;
    X.X = A.X + DX; X.Y = A.Y + DY;
    Y.X = B.X + DX; Y.Y = B.Y + DY;
}

int main(int argc, char *argv[]) {
    int N;
    while (~scanf("%d", &N) && N) {
        Tot = 0;
        for (int i = 0; i < N; ++i) {
            points[i].Input();
        }
        double Ans = 0;
        double Left = 0, Right = INF;
        while (Right - Left >= eps) {
            double Mid = (Left + Right) / 2;
            Tot = 0;
            for (int i = 0; i < N; ++i) {
                Point S, T;
                Change(points[i], points[(i + 1) % N], S, T, Mid);
                Push(HalfPlane(S, T));
            }
            if (HalfPlaneInsert()) {
                Ans = Mid;
                Left = Mid;
            }
            else {
                Right = Mid;
            }
        }
        printf("%.6lf\n", Ans);
    }
    return 0;
}

