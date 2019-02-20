#include <bits/stdc++.h>
using namespace std;

typedef double db;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp (db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db DisPointToPoint (Point Key1, Point Key2) {return sqrt((Key2 - Key1) * (Key2 - Key1));}
struct Circle {Point Center; db Radius;};

Circle S, T;
db Dis, Ans;

int main(int argc, char *argv[]) {
    scanf("%lf%lf%lf", &S.Center.X, &S.Center.Y, &S.Radius);
    scanf("%lf%lf%lf", &T.Center.X, &T.Center.Y, &T.Radius);
    Dis = DisPointToPoint(S.Center, T.Center); Ans = 0.0;
    if (Cmp(Dis, S.Radius + T.Radius) > 0) Ans = (Dis - S.Radius - T.Radius) * 0.5;
    else if (Cmp(S.Radius, Dis + T.Radius) > 0) Ans = (S.Radius - Dis - T.Radius) * 0.5;
    else if (Cmp(T.Radius, Dis + S.Radius) > 0) Ans = (T.Radius - Dis - S.Radius) * 0.5;
    printf("%.15lf\n", Ans);
    return 0;
}

