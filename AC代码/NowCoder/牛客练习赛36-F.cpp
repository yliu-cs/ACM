#include<bits/stdc++.h>
using namespace std;

const double INF = 1e20;
const int maxn = 1e5 + 5;

struct Point {
    double X, Y;
};

Point operator - (Point Key1, Point Key2) {
    return (Point){Key1.X - Key2.X, Key1.Y - Key2.Y};
}

double operator ^ (Point Key1, Point Key2) {
    return Key1.X * Key2.Y - Key1.Y * Key2.X;
}

int N, Q;
double Ans;
Point Polygon[maxn];
double Prefix[maxn];

double GetArea(int S, int T) {
    if (S == 1) {
        return Prefix[T];
    }
    return Prefix[T] - Prefix[S] - fabs((Polygon[T] - Polygon[1]) ^ (Polygon[S] - Polygon[1]));
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; ++i) {
        scanf("%lf%lf", &Polygon[i].X, &Polygon[i].Y);
    }
    Prefix[1] = Prefix[2] = 0.0;
    for (int i = 3; i <= N; ++i) {
        Prefix[i] = Prefix[i - 1] + fabs((Polygon[i - 1] - Polygon[1]) ^ (Polygon[i] - Polygon[1]));
    }
    Ans = -INF;
    for (int i = 1, S, T; i <= Q; ++i) {
        scanf("%d%d", &S, &T);
        if (S > T) {
            swap(S, T);
        }
        if (abs(T - S) < 2) {
            Ans = max(Ans, 0.0);
            continue;
        }
        Ans = max(Ans, min(GetArea(S, T), Prefix[N] - GetArea(S, T)));
    }
    printf("%.2lf\n", Ans / 2.0);
    return 0;
}

