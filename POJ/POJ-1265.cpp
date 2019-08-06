#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e2 + 5;

struct Point {
    double X, Y;

    double operator ^ (Point B) {
        return X * B.Y - Y * B.X;
    }
};

int T;
int N;
Point points[maxn];
int In, On;
double Area;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        In = 0; On = 0; Area = 0.0;
        scanf("%d", &N);
        points[0].X = 0.0; points[0].Y = 0.0;
        for (int i = 1; i <= N; ++i) {
            scanf("%lf%lf", &points[i].X, &points[i].Y);
            On += __gcd(abs((int)points[i].X), abs((int)points[i].Y));
            points[i].X += points[i - 1].X;
            points[i].Y += points[i - 1].Y;
            Area += points[i] ^ points[i - 1];
        }
        Area = fabs(Area);
        In = (Area + 2 - On) / 2;
        printf("Scenario #%d:\n%d %d %.1f\n\n", Case, In, On, Area / 2.0);
    }
    return 0;
}

