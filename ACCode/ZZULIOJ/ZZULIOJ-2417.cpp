#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

inline int Min(int A, int B, int C) {
    return min(A, min(B, C));
}

inline int Max(int A, int B, int C) {
    return max(A, max(B, C));
}

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    return X < 0 ? -1 : 1;
}

struct Point {
    double X, Y;

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point {X - B.X, Y - B.Y};
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

    void Input() {
        S.Input();
        T.Input();
    }

    double operator ^ (const Segment &B) const {
        return (T - S) ^ (B.T - B.S);
    }
};

int main(int argc, char *argv[]) {
    Point A, B, C;
    A.Input();
    B.Input();
    C.Input();
    int MinX = Min(A.X, B.X, C.X), MaxX = Max(A.X, B.X, C.X);
    int MinY = Min(A.Y, B.Y, C.Y), MaxY = Max(A.Y, B.Y, C.Y);
    int Ans = 0;
    for (int i = MinX; i <= MaxX; ++i) {
        for (int j = MinY; j <= MaxY; ++j) {
            Point Judge = Point {double(i), double(j)};
            if (Sgn(Segment {A, B} ^ Segment {A, Judge}) * (Segment {A, C} ^ Segment {A, Judge}) < 0) {
                if (Sgn(Segment {B, A} ^ Segment {B, Judge}) * (Segment {B, C} ^ Segment {B, Judge}) < 0) {
                    Ans++;
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}

