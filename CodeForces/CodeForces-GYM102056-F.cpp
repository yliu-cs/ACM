#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

int Sgn(double Key) {
    if (fabs(Key) < eps) {
        return 0;
    }
    return Key < 0 ? -1 : 1;
}

struct Point {
    double X, Y, Z;
};

typedef Point Vector;

Vector operator - (Vector Key1, Vector Key2) {
    return (Vector){Key1.X - Key2.X,
                    Key1.Y - Key2.Y,
                    Key1.Z - Key2.Z};
}

double operator * (Point Key1, Point Key2) {
    return Key1.X * Key2.X + Key1.Y * Key2.Y + Key1.Z * Key2.Z;
}

double Length(Vector Key) {
    return sqrt(Key * Key);
}

double operator ^ (Vector Key1, Vector Key2) {
    return Length((Vector){Key1.Y * Key2.Z - Key1.Z * Key2.Y,
                           Key1.Z * Key2.X - Key1.X * Key2.Z,
                           Key1.X * Key2.Y - Key1.Y * Key2.X});
}

double DisPointToPoint(Point Key1, Point Key2) {
    return sqrt((Key1 - Key2) * (Key1 - Key2));
}

double GetAngle(Vector Key1, Vector Key2) {
    return fabs(atan2(fabs(Key1 ^ Key2), Key1 * Key2));
}

struct Line {
    Point S, T;
};

typedef Line Segment;

double Length(Segment Key) {
    return DisPointToPoint(Key.S, Key.T);
}

double DisPointToLine(Point Key1, Line Key2) {
    return fabs((Key1 - Key2.S) ^ (Key2.T - Key2.S)) / Length(Key2);
}

double DisPointToSegment(Point Key1, Segment Key2) {
    if (Sgn((Key1 - Key2.S) * (Key2.T - Key2.S)) < 0 || Sgn((Key1 - Key2.T) * (Key2.S - Key2.T)) < 0) {
        return min(DisPointToPoint(Key1, Key2.S), DisPointToPoint(Key1, Key2.T));
    }
    return DisPointToLine(Key1, Key2);
}

struct Sphere {
    Point Center;
    double Radius;
};

int T;
Sphere Obstacle;
Point Start, End;
double DisOS, DisOE;
double Angle;
double Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lf%lf%lf%lf", &Obstacle.Center.X, &Obstacle.Center.Y, &Obstacle.Center.Z, &Obstacle.Radius);
        scanf("%lf%lf%lf", &Start.X, &Start.Y, &Start.Z);
        scanf("%lf%lf%lf", &End.X, &End.Y, &End.Z);
        Ans = 0.0;
        if (Sgn(DisPointToSegment(Obstacle.Center, (Segment){Start, End}) - Obstacle.Radius) >= 0) {
            printf("%.8lf\n", DisPointToPoint(Start, End));
            continue;
        }
        DisOS = DisPointToPoint(Obstacle.Center, Start);
        DisOE = DisPointToPoint(Obstacle.Center, End);
        Angle = GetAngle(Start - Obstacle.Center, End - Obstacle.Center) -
                acos(Obstacle.Radius / DisOS) -
                acos(Obstacle.Radius / DisOE);
        Ans += sqrt(DisOS * DisOS - Obstacle.Radius * Obstacle.Radius);
        Ans += sqrt(DisOE * DisOE - Obstacle.Radius * Obstacle.Radius);
        Ans += Angle * Obstacle.Radius;
        printf("%.8lf\n", Ans);
    }
    return 0;
}
