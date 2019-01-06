#include <bits/stdc++.h>
using namespace std;

struct Point {
    double X, Y, Z;
};

typedef Point Vector;

Point operator - (Point Key1, Point Key2) {
    return (Point){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};
}

struct Sphere {
    Point Center;
    double Radius;
};

int T;
Sphere Obstacle;
Point Start, End;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lf%lf%lf%lf", &Obstacle.Center.X, &Obstacle.Center.Y, &Obstacle.Center.Z, &Obstacle.Radius);
        scanf("%lf%lf%lf", &Start.X, &Start.Y, &Start.Z);
        scanf("%lf%lf%lf", &End.X, &End.Y, &End.Z);
    }
    return 0;
}
