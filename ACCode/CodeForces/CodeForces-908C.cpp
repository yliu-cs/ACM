#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-8;

struct Point {
    double X, Y;
};

int N;
double R;
Point points[maxn];

int main(int argc, char *argv[]) {
    scanf("%d%lf", &N, &R);
    scanf("%lf", &points[1].X);
    points[1].Y = R;
    for (int i = 2; i <= N; ++i) {
        scanf("%lf", &points[i].X);
        points[i].Y = R;
        for (int j = 1; j < i; ++j) {
            if (fabs(points[i].X - points[j].X) <= 2.0 * R) {
                double Pos = points[j].Y + sqrt(4.0 * R * R - fabs(points[i].X - points[j].X) * fabs(points[i].X - points[j].X));
                points[i].Y = max(points[i].Y, Pos);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        printf("%.9lf ", points[i].Y);
    }
    printf("\n");
    return 0;
}

