#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

int Sgn(long double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    return X > 0 ? 1 : -1;
}

struct Point {
    long double X, Y;

    void Input() {
        scanf("%Lf%Lf", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point {X - B.X, Y - B.Y};
    }

    long double operator * (const Point &B) const {
        return X * B.X + Y * B.Y;
    }

    long double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }

    long double Dis(Point &B) {
        return sqrt((B - *this) * (B - *this));
    }
};

struct Line {
    Point S, T;

    bool IsParallel(Line &B) {
        return Sgn((S - T) ^ (B.S -B.T)) == 0;
    }
};

Point A, B, C;
Line AB, BC;

int main(int argc, char *argv[]) {
    A.Input();
    B.Input();
    C.Input();
    AB = Line {A, B}; BC = Line {B, C};
    if (AB.IsParallel(BC) || A.Dis(B) != B.Dis(C)) {
        printf("No\n");
    }
    else {
        printf("Yes\n");
    }
    return 0;
}

