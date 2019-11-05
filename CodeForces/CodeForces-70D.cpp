#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 1e5 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db GetLen(Vector Key) {return sqrt(Key * Key);}

int N;
Point Basic;
Point points[maxn];
set<Point> S;

bool operator < (Point Key1, Point Key2) {
    Key1 = Key1 - Basic; Key2 = Key2 - Basic;
    db Ang1 = atan2(Key1.Y, Key1.X), Ang2 = atan2(Key2.Y, Key2.X);
    db Len1 = GetLen(Key1), Len2 = GetLen(Key2);
    if (Cmp(Ang1, Ang2) != 0) return Cmp(Ang1, Ang2) < 0;
    return Cmp(Len1, Len2) < 0;
}

set<Point>::iterator Prev(set<Point>::iterator Key) {
    if (Key == S.begin()) Key = S.end();
    return --Key;
}

set<Point>::iterator Next(set<Point>::iterator Key) {
    ++Key;
    return Key == S.end() ? S.begin() : Key;
}

bool Query(Point Key) {
    set<Point>::iterator it = S.lower_bound(Key);
    if (it == S.end()) it = S.begin();
    return Sgn((Key - *(Prev(it))) ^ (*(it) - *(Prev(it)))) <= 0;
}

void Insert(Point Key) {
    if (Query(Key)) return;
    S.insert(Key);
    set<Point>::iterator Cur = Next(S.find(Key));
    while (S.size() > 3 && Sgn((Key - *(Next(Cur))) ^ (*(Cur) - *(Next(Cur)))) <= 0) {
        S.erase(Cur);
        Cur = Next(S.find(Key));
    }
    Cur = Prev(S.find(Key));
    while (S.size() > 3 && Sgn((Key - *(Cur)) ^ (*(Cur) - *(Prev(Cur)))) >= 0) {
        S.erase(Cur);
        Cur = Prev(S.find(Key));
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Basic.X = Basic.Y = 0.0;
    for (int i = 1, T; i <= 3; ++i) {
        scanf("%d%lf%lf", &T, &points[i].X, &points[i].Y);
        Basic.X += points[i].X; Basic.Y += points[i].Y;
    }
    Basic.X /= 3.0; Basic.Y /= 3.0;
    for (int i = 1; i <= 3; ++i) S.insert(points[i]);
    for (int i = 4, T; i <= N; ++i) {
        scanf("%d%lf%lf", &T, &points[i].X, &points[i].Y);
        if (T == 1) Insert(points[i]);
        else {
            if (Query(points[i])) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

