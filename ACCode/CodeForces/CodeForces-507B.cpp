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

    double Dis(Point &B) {
        return sqrt((B - *this) * (B - *this));
    }
};

double R;
Point Origin;
Point Target;

int main(int argc, char *argv[]) {
    scanf("%lf", &R);
    Origin.Input(); Target.Input();
    double Dis = Origin.Dis(Target);
    double Ans = Dis / (2.0 * R);
    printf("%d\n", (int)ceil(Ans));
    return 0;
}

