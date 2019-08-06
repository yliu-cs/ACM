#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;
const double pi = acos(-1.0);
const double eps = 1e-8;

int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    return X < 0 ? -1 : 1;
}

struct Point {
    double X, Y, Z;

    void Input() {
        scanf("%lf%lf%lf", &X, &Y, &Z);
    }
};

typedef Point Vector;

Vector operator + (Vector Key1, Vector Key2) {
    return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y, Key1.Z + Key2.Z};
}

Vector operator - (Vector Key1, Vector Key2) {
    return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};
}

double operator * (Vector Key1, Vector Key2) {
    return Key1.X * Key2.X + Key1.Y * Key2.Y + Key1.Z * Key2.Z;
}

double Length(Vector Key) {
    return sqrt(Key * Key);
}

double operator ^ (Vector Key1, Vector Key2) {
    return Length((Vector){Key1.Y * Key2.Z - Key1.Z * Key2.Y, Key1.Z * Key2.X - Key1.X * Key2.Z, Key1.X * Key2.Y - Key1.Y * Key2.X});
}

double DisPointToPoint(Point Key1, Point Key2) {
    return sqrt((Key1 - Key2) * (Key1 - Key2));
}

struct Sphere {
    Point Center;
    double Radius;

    void Input() {
        Center.Input();
        scanf("%lf", &Radius);
    }
};

double CalVolume(Sphere Key) {
    return 4.0 / 3.0 * pi * Key.Radius * Key.Radius * Key.Radius;
}

double SphereIntersectVolume(Sphere Key1, Sphere Key2) {
    double Ans = 0.0;
    double Dis = DisPointToPoint(Key1.Center, Key2.Center);
    if (Sgn(Dis - Key1.Radius - Key2.Radius) >= 0) {
        return Ans;
    }
    if (Sgn(Key2.Radius - (Dis + Key1.Radius)) >= 0) {
        return CalVolume(Key1);
    }
    else if (Sgn(Key1.Radius - (Dis + Key2.Radius)) >= 0) {
        return CalVolume(Key2);
    }
    double Length1 = ((Key1.Radius * Key1.Radius - Key2.Radius * Key2.Radius) / Dis + Dis) / 2;
    double Length2 = Dis - Length1;
    double X1 = Key1.Radius - Length1, X2 = Key2.Radius - Length2;
    double V1 = pi * X1 * X1 * (Key1.Radius - X1 / 3.0);
    double V2 = pi * X2 * X2 * (Key2.Radius - X2 / 3.0);
    return V1 + V2;
}

int T;
int N;
Sphere Planet[maxn];
Sphere Clean;
double Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            Planet[i].Input();
        }
        Clean.Input();
        Ans = 0.0;
        for (int i = 1; i <= N; ++i) {
            Ans += SphereIntersectVolume(Clean, Planet[i]);
        }
        printf("Case #%d: %.20lf\n", Case, Ans);
    }
    return 0;
}
