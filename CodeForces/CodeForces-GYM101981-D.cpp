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

typedef Point Vector;

Vector operator + (Point Key1, Point Key2) {
    return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y, Key1.Z + Key2.Z};
}

Vector operator - (Point Key1, Point Key2) {
    return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};
}

Point operator * (Point Key1, double Key2) {
    return (Point){Key1.X * Key2, Key1.Y * Key2, Key1.Z * Key2};
}

Point operator / (Point Key1, double Key2) {
    return (Point){Key1.X / Key2, Key1.Y / Key2, Key1.Z / Key2};
}

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
        double Radius = Distance(Cur, points[Book]);
        Ans = min(Ans, Radius);
        Cur = Cur + (points[Book] - Cur) / Radius * Probability;
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

