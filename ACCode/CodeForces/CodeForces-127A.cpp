#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

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

double Distance(Point A, Point B) {
    return sqrt((B - A) * (B - A));
}

int N, K;
double Ans;
Point points[maxn];

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &K);
    Ans = 0.0;
    points[0].Input();
    for (int i = 1; i < N; ++i) {
        points[i].Input();
        Ans += Distance(points[i], points[i - 1]);
    }
    printf("%.9lf\n", Ans * K / 50.0);
    return 0;
}

