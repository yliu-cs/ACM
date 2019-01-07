#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e2 + 5;
const double eps = 1e-8;

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    if (X < 0) {
        return -1;
    }
    else {
        return 1;
    }
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

struct Circle {
    double R;
    Point Center;

    Circle() {}
    Circle(double _R, Point _Center) {
        R = _R;
        Center = _Center;
    }

    void Input() {
        scanf("%lf", &R);
        Center.Input();
    }
};

double Distance(Point A, Point B) {
    return sqrt((B - A) * (B - A));
}

bool IsIntersect(Segment A, Segment B) {
    return
        max(A.S.X, A.T.X) >= min(B.S.X, B.T.X) &&
        max(B.S.X, B.T.X) >= min(B.S.X, A.T.X) &&
        max(A.S.Y, A.T.Y) >= min(B.S.Y, B.T.Y) &&
        max(B.S.Y, B.T.Y) >= min(A.S.Y, A.T.Y) &&
        Sgn((B.S - A.T) ^ (A.S - A.T)) * Sgn((B.T - A.T) ^ (A.S - A.T)) <= 0 &&
        Sgn((A.S - B.T) ^ (B.S - B.T)) * Sgn((A.T - B.T) ^ (B.S - B.T)) <= 0;
}

double Shortest(Point X, Segment A) {
    return ((A.S - X) ^ (A.T - X)) / fabs(Distance(A.S, A.T));
}

bool IsConvexHull(Point points[], int N) {
    for (int i = 0; i < N; ++i) {
        if (Sgn((points[(i + 1) % N] - points[i]) ^ (points[(i + 2) % N] - points[(i + 1) % N])) < 0) {
            return false;
        }
    }
    return true;
}

bool PointIsInConvexHull(Point X, Point points[], int N) {
    for (int i = 0; i < N; ++i) {
        if (Sgn((points[i % N] - X) ^ (points[(i + 1) % N] - X)) < 0) {
            return false;
        }
    }
    return true;
}

bool CircleIsInConvexHull(Circle Round, Point points[], int N) {
    if (!PointIsInConvexHull(Round.Center, points, N)) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        if (Sgn(Shortest(Round.Center, Segment(points[i % N], points[(i + 1) % N])) - Round.R) < 0) {
            return false;
        }
    }
    return true;
}

int N;
Circle Round;
Point points[maxn];

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N >= 3) {
        Round.Input();
        for (int i = 0; i < N; ++i) {
            points[i].Input();
        }
        if (Sgn((points[1] - points[0]) ^ (points[2] - points[0])) < 0) {
            reverse(points, points + N);
        }
        if (!IsConvexHull(points, N)) {
            printf("HOLE IS ILL-FORMED\n");
            continue;
        }
        if (!CircleIsInConvexHull(Round, points, N)) {
            printf("PEG WILL NOT FIT\n");
        }
        else {
            printf("PEG WILL FIT\n");
        }
    }
	return 0;
}

