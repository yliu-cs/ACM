#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn = 2e2 + 5;
const db eps = 1e-8;
const db pi = acos(-1.0);

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
db Format(db Key) {return Sgn(Key) == 0 ? (db)0 : Key;}
struct Point {db X, Y;};
typedef Point Vector;
bool operator == (Point Key1, Point Key2) {return Cmp(Key1.X, Key2.X) == 0 && Cmp(Key1.Y, Key2.Y) == 0;}
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
Vector operator * (Vector Key1, db Key2) {return (Vector){Key1.X * Key2, Key1.Y * Key2};}
Vector operator / (Vector Key1, db Key2) {return (Vector){Key1.X / Key2, Key1.Y / Key2};}
db GetLen(Vector Key) {return sqrt(Key * Key);}
db DisPointToPoint(Point Key1, Point Key2) {return GetLen(Key2 - Key1);}
Point Rotate(Point Key, db Angle) {return (Point){Key.X * cos(Angle) - Key.Y * sin(Angle),Key.X * sin(Angle) + Key.Y * cos(Angle)};}
Vector Rotate90(Vector Key) {return (Vector){-Key.Y, Key.X};}
struct Line {Point S, T;};
typedef Line Segment;
Point Cross(Line Key1, Line Key2) {
    db Temp = ((Key1.S - Key2.S) ^ (Key2.S - Key2.T)) / ((Key1.S - Key1.T) ^ (Key2.S - Key2.T));
    return (Point){Key1.S.X + (Key1.T.X - Key1.S.X) * Temp, Key1.S.Y + (Key1.T.Y - Key1.S.Y) * Temp};
}

int N, N1, N2;
db Angle, Rad;
Point points[maxn];
Point Center;

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &N, &N1, &N2);
    scanf("%lf%lf", &points[N1].X, &points[N1].Y);
    scanf("%lf%lf", &points[N2].X, &points[N2].Y);
    if (N1 > N2) swap(N1, N2);
    Rad = (pi - (db)min(N2 - N1, N + N1 - N2) * 2.0 * pi / (db)N) / 2.0;
    if (N2 - N1 == N + N1 - N2) Center = (points[N1] + points[N2]) / 2.0;
    else if (N2 - N1 < N + N1 - N2) Center = Rotate(points[N2] - points[N1], -Rad) / 2.0 / cos(Rad) + points[N1];
    else Center = Rotate(points[N2] - points[N1], Rad) / 2.0 / cos(Rad) + points[N1];
    int Cur = (N1 - 1) == 0 ? N : (N1 - 1), k = 1; Angle = 2.0 * pi / (db)N;
    while (Cur != N1) {
        if (Cur == N2) {
            Cur--; k++;
            if (Cur == 0) Cur = N;
            continue;
        }
        points[Cur] = Rotate(points[N1] - Center, Angle * (db)k) + Center;
        Cur--; k++;
        if (Cur == 0) Cur = N;
    }
    for (int i = 1; i <= N; ++i) printf("%.6lf %.6lf\n", Format(points[i].X), Format(points[i].Y));
    return 0;
}

