#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-8;

int Sgn(double X) {
    if (fabs(X - 0) < eps) {
        return 0;
    }
    return X < 0 ? -1 : 1;
}

struct Point {
    double X, Y;

    Point operator - (Point B) {
        return (Point){X - B.X, Y - B.Y};
    }

    double operator ^ (Point B) {
        return X * B.Y - Y * B.X;
    }
};

struct Line {
    Point S, T;

    double operator ^ (Line B) {
        return (T - S) ^ (B.T - B.S);
    }
};

int N;
int Ans;
Point points[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i <= N; ++i) {
        scanf("%lf%lf", &points[i].X, &points[i].Y);
    }
    for (int i = 1; i < N; ++i) {
        if (Sgn((Line){points[i - 1], points[i]} ^ (Line){points[i], points[i + 1]}) > 0) {
            Ans++;
        }
    }
    printf("%d\n", Ans);
    return 0;
}

