#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db inf = 1e20;
const int maxn = 1e4 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
struct Line {Point S, T;};
typedef Line Segment;
typedef Line Ray;
bool IsPointOnSeg(Point Key1, Segment Key2) {
    return Sgn((Key1 - Key2.S) ^ (Key2.T - Key2.S)) == 0 && Sgn((Key1 - Key2.S) * (Key1 - Key2.T)) <= 0;
}
bool IsSegInterSeg(Segment Key1, Segment Key2) {
    return
        max(Key1.S.X, Key1.T.X) >= min(Key2.S.X, Key2.T.X) &&
        max(Key2.S.X, Key2.T.X) >= min(Key1.S.X, Key1.T.X) &&
        max(Key1.S.Y, Key1.T.Y) >= min(Key2.S.Y, Key2.T.Y) &&
        max(Key2.S.Y, Key2.T.Y) >= min(Key1.S.Y, Key1.T.Y) &&
        Sgn((Key2.S - Key1.T) ^ (Key1.S - Key1.T)) * Sgn((Key2.T - Key1.T) ^ (Key1.S - Key1.T)) <= 0 &&
        Sgn((Key1.S - Key2.T) ^ (Key2.S - Key2.T)) * Sgn((Key1.T - Key2.T) ^ (Key2.S - Key2.T)) <= 0;
}

int N;
Segment Segs[maxn];
Point Dot;
Ray Judge;

bool IsPointOnPolygon() {
    for (int i = 1; i <= N; ++i)
        if (IsPointOnSeg(Dot, Segs[i])) return true;
    return false;
}

bool IsPointInPolygon() {
    int Cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (Cmp(Segs[i].S.Y, Segs[i].T.Y) == 0) continue;
        if (IsSegInterSeg(Judge, Segs[i]) && Cmp(Segs[i].T.Y, Dot.Y)) {
            Cnt++;
        }
    }
    return Cnt & 1;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lf%lf%lf%lf", &Segs[i].S.X, &Segs[i].S.Y, &Segs[i].T.X, &Segs[i].T.Y);
        if (Cmp(Segs[i].S.Y, Segs[i].T.Y) > 0) swap(Segs[i].S, Segs[i].T);
    }
    scanf("%lf%lf", &Dot.X, &Dot.Y);
    Judge = (Ray){Dot, (Point){inf, Dot.Y}};
    if (IsPointOnPolygon()) printf("BORDER\n");
    else if (IsPointInPolygon()) printf("INSIDE\n");
    else printf("OUTSIDE\n");
    return 0;
}

