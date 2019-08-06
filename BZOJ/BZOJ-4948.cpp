#include <bits/stdc++.h>
using namespace std;

typedef long double db;
const int maxn = (int)(2e2 + 5);
const db eps = 1e-8;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;};
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;};
db DisPointToPoint(Point Key1, Point Key2) {return sqrt((Key2 - Key1) * (Key2 - Key1));}
struct Line {Point S, T;};
typedef Line Segment;
db DisLineToSeg(Line Key1, Segment Key2) {return ((Key2.S - Key1.S) ^ (Key2.T - Key1.S)) / ((Key2.T - Key2.S) ^ (Key1.T - Key1.S)) * DisPointToPoint(Key1.S, Key1.T);}

struct Status{db Length; int Flag;};
bool operator < (Status Key1, Status Key2) {return Sgn(Key2.Length - Key1.Length) > 0;}

int N;
Point Island[maxn];
db Ans;
Status Intersection[maxn];

void Solve(Line Key) {
    int Tot = 0;
    for (int i = 1; i <= N; ++i) {
        int Dir1 = Sgn((Key.T - Key.S) ^ (Island[i] - Key.S)), Dir2 = Sgn((Key.T - Key.S) ^ (Island[i % N + 1] - Key.S));
        if (Dir1 == Dir2) continue;
        if (Dir1 > Dir2) Intersection[++Tot] = (Status){DisLineToSeg(Key, (Segment){Island[i], Island[i % N + 1]}), (Dir1 && Dir2) ? 2 : 1};
        else Intersection[++Tot] = (Status){DisLineToSeg(Key, (Segment){Island[i], Island[i % N + 1]}), (Dir1 && Dir2) ? -2 : -1};
    }
    sort(Intersection + 1, Intersection + Tot + 1);
    int Flag = 0; db Len = 0.0;
    for (int i = 1; i <= Tot; ++i) {
        if (Flag) Len += Intersection[i].Length - Intersection[i - 1].Length;
        else {
            if (Sgn(Len - Ans) >= 0) Ans = Len;
            Len = 0.0;
        }
        Flag += Intersection[i].Flag;
    }
    if (Sgn(Len - Ans) >= 0) Ans = Len;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%Lf%Lf", &Island[i].X, &Island[i].Y);
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            Solve((Segment){Island[i], Island[j]});
    printf("%.9Lf\n", Ans);
    return 0;
}
