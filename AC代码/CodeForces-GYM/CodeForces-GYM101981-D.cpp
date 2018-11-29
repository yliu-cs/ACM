#include <bits/stdc++.h>
using namespace std;

const double INF = 1e20;
const int maxn = 1e2 + 5;
const double eps = 1e-8;
const double delta = 0.98;

struct Point {
    double X, Y, Z;

    void Input() {
        scanf("%lf%lf%lf", &X, &Y, &Z);
    }
};

double Distance(Point A, Point B) {
    return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y) + (A.Z - B.Z) * (A.Z - B.Z));
}

int N;
Point points[maxn];

double MinimumSphereCoverage() {
    Point Cur = points[0];
    double Probability = 10000, Ans = INF;
    while (Probability > eps) {
        int Book = 0;
        for (int i = 0; i < N; ++i) {
            if (Distance(Cur, points[i]) > Distance(Cur, points[Book])) {
                Book = i;
            }
        }
        double Redius = Distance(Cur, points[Book]);
        Ans = min(Ans, Redius);
        Cur.X += (points[Book].X - Cur.X) / Redius * Probability;
        Cur.Y += (points[Book].Y - Cur.Y) / Redius * Probability;
        Cur.Z += (points[Book].Z - Cur.Z) / Redius * Probability;
        Probability *= delta;
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        points[i].Input();
    }
    printf("%.15lf\n", MinimumSphereCoverage());
    return 0;
}

