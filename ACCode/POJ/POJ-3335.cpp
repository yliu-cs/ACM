#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1e2 + 5;
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

    double operator ^ (const Segment &B) const {
        return (T - S) ^ (B.T - B.S);
    }
};

bool IsParallel(Segment A, Segment B) {
    return Sgn((A.T - A.S) ^ (B.T - B.S)) == 0;
}

Point IntersectionPoint(Segment A, Segment B) {
    double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
    return Point((A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X));
}

// 半平面，表示S->T逆时针（左侧）的半平面
struct HalfPlane:public Segment {
    double Angle;

    HalfPlane() {}
    HalfPlane(Point _S, Point _T) {
        S = _S;
        T = _T;
    }
    HalfPlane(Segment _ST) {
        S = _ST.S;
        T = _ST.T;
    }

    // 计算极角
    void CalAngle() {
        Angle = atan2(T.Y - S.Y, T.X - S.X);
    }
    
    // 极角排序
    bool operator < (const HalfPlane &B) const {
        return Angle < B.Angle;
    }
};

int T;
int N;
int Tot;
HalfPlane halfplanes[maxn];
Point points[maxn];
int Front, Tail;
int Que[maxn];

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
    Que[Front = 0] = 0;
    Que[Tail = 1] = 1;
    points[1] = IntersectionPoint(halfplanes[0], halfplanes[1]);
    for (int i = 2; i < Tot; ++i) {
        while (Front < Tail && Sgn((halfplanes[i].T - halfplanes[i].S) ^ (points[Tail] - halfplanes[i].S)) < 0) {
            Tail--;
        }
        while (Front < Tail && Sgn((halfplanes[i].T - halfplanes[i].S) ^ (points[Front + 1] - halfplanes[i].S)) < 0) {
            Front++;
        }
        Que[++Tail] = i;
        if (IsParallel(halfplanes[i], halfplanes[Que[Tail - 1]])) {
            return false;
        }
        points[Tail] = IntersectionPoint(halfplanes[i], halfplanes[Que[Tail - 1]]);
    }
    while (Front < Tail && Sgn((halfplanes[Que[Front]].T - halfplanes[Que[Front]].S) ^ (points[Tail] - halfplanes[Que[Front]].S)) < 0) {
        Tail--;
    }
    while (Front < Tail && Sgn((halfplanes[Que[Tail]].T - halfplanes[Que[Tail]].S) ^ (points[Front + 1] - halfplanes[Que[Tail]].S)) < 0) {
        Front++;
    }
    if (Front + 1 >= Tail) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        Tot = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            points[i].Input();
        }
        reverse(points, points + N);
        for (int i = 0; i < N; ++i) {
            Push(HalfPlane(points[i], points[(i + 1) % N]));
        }
        if (HalfPlaneInsert()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
	return 0;
}

