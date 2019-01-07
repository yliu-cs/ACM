#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-8;

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    return X < 0 ? -1 : 1;
}

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
};

Point IntersectionPoint(Segment A, Segment B) {
	double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
	return Point((A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X));
}

bool IsParallel(Segment A, Segment B) {
    return Sgn((A.S - A.T) ^ (B.S - B.T)) == 0;
}

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
        return Angle < B.Angle;
    }
};

int N;
int Tot;
HalfPlane halfplanes[maxn];
Point points[maxn];
int Front, Tail;
int Deque[maxn];

void Push(HalfPlane X) {
    halfplanes[Tot++] = X;
}

void Unique() {
    int Cnt = 1;
    for (int i = 1; i < Tot; ++i) {
        if (Sgn(halfplanes[i].Angle - halfplanes[i - 1].Angle) != 0) {
            halfplanes[Cnt++] = halfplanes[i];
        }
        else if (Sgn((halfplanes[Cnt - 1].T - halfplanes[Cnt - 1].S) ^ (halfplanes[i].S - halfplanes[Cnt - 1].S)) > 0) {
            halfplanes[Cnt - 1] = halfplanes[i];
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
    Deque[Front = 0] = 0;
    Deque[Tail = 1] = 1;
    points[1] = IntersectionPoint(halfplanes[0], halfplanes[1]);
    for (int i = 2; i < Tot; ++i) {
        while (Front < Tail && Sgn((halfplanes[i].T - halfplanes[i].S) ^ (points[Tail] - halfplanes[i].S)) < 0) {
            Tail--;
        }
        while (Front < Tail && Sgn((halfplanes[i].T - halfplanes[i].S) ^ (points[Front + 1] - halfplanes[i].S)) < 0) {
            Front++;
        }
        Deque[++Tail] = i;
        if (IsParallel(halfplanes[i], halfplanes[Deque[Tail - 1]])) {
            return false;
        }
        points[Tail] = IntersectionPoint(halfplanes[i], halfplanes[Deque[Tail - 1]]);
    }
    while (Front < Tail && Sgn((halfplanes[Deque[Front]].T - halfplanes[Deque[Front]].S) ^ (points[Tail] - halfplanes[Deque[Front]].S)) < 0) {
        Tail--;
    }
    while (Front < Tail && Sgn((halfplanes[Deque[Tail]].T - halfplanes[Deque[Tail]].S) ^ (points[Front + 1] - halfplanes[Deque[Tail]].S)) < 0) {
        Front++;
    }
    if (Front + 1 >= Tail) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N) {
        Tot = 0;
        for (int i = 0; i < N; ++i) {
            points[i].Input();
        }
        for (int i = 0; i < N; ++i) {
            Push(HalfPlane(points[i], points[(i + 1) % N]));
        }
        if (HalfPlaneInsert()) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
	return 0;
}

