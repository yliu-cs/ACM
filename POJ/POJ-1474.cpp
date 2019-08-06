#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 2e4 + 5;
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

    bool IsParallel(const Segment &B) {
        return Sgn((S - T) ^ (B.S - B.T)) == 0;
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
        if (Sgn(Angle - B.Angle)) {
            return Angle < B.Angle;
        }
        return ((S - B.S) ^ (B.T - B.S)) < 0;
    }
};

int N;
int Case;
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
        if (Sgn(halfplanes[i].Angle - halfplanes[i - 1].Angle)) {
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
        if (!Sgn((Deque[Tail].T - Deque[Tail].S) ^ (Deque[Tail - 1].T - Deque[Tail - 1].S)) || !Sgn((Deque[Front].T - Deque[Front].S) ^ (Deque[Front + 1].T - Deque[Front + 1].S))) {
            return false;
        }
        while (Front < Tail && Sgn(((Deque[Tail] & Deque[Tail - 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > 0) {
            Tail--;
        }
        while (Front < Tail && Sgn(((Deque[Front] & Deque[Front + 1]) - halfplanes[i].S) ^ (halfplanes[i].T - halfplanes[i].S)) > 0) {
            Front++;
        }
        Deque[++Tail] = halfplanes[i];
    }
    while (Front < Tail && Sgn(((Deque[Tail] & Deque[Tail - 1]) - Deque[Front].S) ^ (Deque[Front].T - Deque[Front].S)) > 0) {
        Tail--;
    }
    while (Front < Tail && Sgn(((Deque[Front] & Deque[Front - 1]) - Deque[Tail].S) ^ (Deque[Tail].T - Deque[Tail].T)) > 0) {
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
        Res[Cnt++] = Deque[i] & Deque[i + 1];
    }
    if (Front < Tail - 1) {
        Res[Cnt++] = Deque[Front] & Deque[Tail];
    }
}

int main(int argc, char *argv[]) {
    Case = 0;
    while (~scanf("%d", &N) && N) {
        Tot = 0;
        for (int i = 0; i < N; ++i) {
            points[i].Input();
        }
        reverse(points, points + N);
        for (int i = 0; i < N; ++i) {
            Push(HalfPlane(points[i], points[(i + 1) % N]));
        }
        printf("Floor #%d\n", ++Case);
        if (HalfPlaneInsert()) {
            printf("Surveillance is possible.\n");
        }
        else {
            printf("Surveillance is impossible.\n");
        }
        printf("\n");
    }
    return 0;
}
