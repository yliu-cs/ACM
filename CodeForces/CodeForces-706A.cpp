#include<bits/stdc++.h>
using namespace std;

const double INF = 1e20;

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

Point Basic;
int N;
Point X;
double Speed;
double Ans;

int main(int argc, char *argv[]) {
    Ans = INF;
    Basic.Input();
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        X.Input();
        scanf("%lf", &Speed);
        Ans = min(Ans, Distance(Basic, X) / Speed);
    }
    printf("%.20lf\n", Ans);
    return 0;
}

