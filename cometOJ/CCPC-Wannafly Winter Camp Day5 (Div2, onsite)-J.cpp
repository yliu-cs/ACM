#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const long double eps = 1e-8;

struct Edge {
    int U, V;
};

Edge edges[maxn << 1];

int Sgn(double Key) {
    if (fabs(Key) < eps) {
        return 0;
    }
    return Key < 0 ? -1 : 1;
}

struct Point {
    double X, Y;
};

typedef Point Vector;

bool operator == (Point Key1, Point Key2) {
    return Sgn(Key1.X - Key2.X) == 0 && Sgn(Key1.Y - Key2.Y) == 0;
}

Vector operator + (Vector Key1, Vector Key2) {
    return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};
}

Vector operator - (Vector Key1, Vector Key2) {
    return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};
}

double operator * (Vector Key1, Vector Key2) {
    return Key1.X * Key2.X + Key1.Y * Key2.Y;
}

double operator ^ (Vector Key1, Vector Key2) {
    return Key1.X * Key2.Y - Key1.Y * Key2.X;
}

struct Line {
    Point S, T;
};

typedef Line Segment;

bool IsParallel(Line Key1, Line Key2) {
    return Sgn((Key1.S - Key1.T) ^ (Key2.S - Key2.T)) == 0;
}

bool IsSegInterSeg(Segment Key1, Segment Key2) {
    return
            Sgn(max(Key1.S.X, Key1.T.X) - min(Key2.S.X, Key2.T.X)) >= 0 &&
            Sgn(max(Key2.S.X, Key2.T.X) - min(Key1.S.X, Key1.T.X)) >= 0 &&
            Sgn(max(Key1.S.Y, Key1.T.Y) - min(Key2.S.Y, Key2.T.Y)) >= 0 &&
            Sgn(max(Key2.S.Y, Key2.T.Y) - min(Key1.S.Y, Key1.T.Y)) >= 0 &&
            Sgn((Key2.S - Key1.T) ^ (Key1.S - Key1.T)) * Sgn((Key2.T - Key1.T) ^ (Key1.S - Key1.T)) <= 0 &&
            Sgn((Key1.S - Key2.T) ^ (Key2.S - Key2.T)) * Sgn((Key1.T - Key2.T) ^ (Key2.S - Key2.T)) <= 0;
}

Point Cross(Line Key1, Line Key2) {
    double Temp = ((Key1.S - Key2.S) ^ (Key2.S - Key2.T)) / ((Key1.S - Key1.T) ^ (Key2.S - Key2.T));
    return (Point){Key1.S.X + (Key1.T.X - Key1.S.X) * Temp, Key1.S.Y + (Key1.T.Y - Key1.S.Y) * Temp};
}

int N, M;
Point points[maxn];
long long Cnt;
Vector Vec1, Vec2;

bool Check(Segment Key1, Segment Key2) {
    if (IsParallel(Key1, Key2)) {
        if (Key1.S == Key2.S) {
        }
        else if (Key1.S == Key2.T) {
            swap(Key2.S, Key2.T);
        }
        else if (Key1.T == Key2.S) {
            swap(Key1.S, Key1.T);
        }
        else if (Key1.T == Key2.T) {
            swap(Key1.S, Key1.T);
            swap(Key2.S, Key2.T);
        }
        Vec1 = Key1.T - Key1.S; Vec2 = Key2.T - Key2.S;
        if (Sgn(Vec1.X) == Sgn(Vec2.X) && Sgn(Vec1.Y) == Sgn(Vec2.Y)) {
            return false;
        }
        return true;
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1, U, V; i <= M; ++i) {
        scanf("%d%d", &U, &V);
        edges[i] = (Edge){U, V};
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%lf%lf", &points[i].X, &points[i].Y);
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = i + 1; j <= M; ++j) {
            if (edges[i].U == edges[j].U || edges[i].U == edges[j].V ||
                edges[i].V == edges[j].U || edges[i].V == edges[j].V) {
                if (Check((Segment){points[edges[i].U], points[edges[i].V]}, (Segment){points[edges[j].U], points[edges[j].V]})) {
                    continue;
                }
            }
            if (IsSegInterSeg((Segment){points[edges[i].U], points[edges[i].V]}, (Segment){points[edges[j].U], points[edges[j].V]})) {
                Cnt++;
            }
        }
    }
    printf("%lld", Cnt);
    return 0;
}
