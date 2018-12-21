#include<bits/stdc++.h>
using namespace std;

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

    double Dis(Point &B) {
        return sqrt((B - *this) * (B - *this));
    }
};

Point Origin;
double R, D;
int N;
Point Judge;
double Radious;
double Dis;
int Cnt;

int main(int argc, char *argv[]) {
    Origin = Point {0.0, 0.0};
    scanf("%lf%lf", &R, &D);
    D = R - D;
    scanf("%d", &N);
    Cnt = 0;
    for (int i = 1; i <= N; ++i) {
        Judge.Input();
        scanf("%lf", &Radious);
        Dis = Origin.Dis(Judge);
        if (Dis <= R - Radious && Dis >= D + Radious) {
            Cnt++;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}

