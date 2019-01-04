#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5;

struct Point {
    double X, Y;

    void Output() {
        printf("(%lf,%lf)\n", X, Y);
    }

    Point operator - (const Point &B) const {
        return Point {X - B.X, Y - B.Y};
    }

    double operator * (const Point &B) const {
        return X * B.X + Y * B.Y;
    }

    double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }

    bool operator < (const Point &B) const {
        return X < B.X;
    }
};

double Distance(Point A, Point B) {
    return sqrt((B - A) * (B - A));
}

struct Line {
    Point S, T;

    Point operator & (const Line &B) const {
        double Temp = ((S - B.S) ^ (B.S - B.T)) / ((S - T) ^ (B.S - B.T));
        return Point {S.X + (T.X - S.X) * Temp, S.Y + (T.Y - S.Y) * Temp};
    }
};

struct Status {
    int Left, Right;
    double Length;

    bool operator < (const Status &B) const {
        return Length > B.Length;
    }
};

int T;
int N;
int Tot;
int Height[maxn];
Point points[maxn];

void Init() {
    for (int i = 0; i <= N; ++i) {
        Line SkyLine = Line {Point {-1.0, points[i].Y}, Point {55.0, points[i].Y}};
        for (int j = 0; j < N; ++j) {
            if ((points[i].Y - points[j].Y) * (points[i].Y - points[j + 1].Y) < 0) {
                points[Tot++] = SkyLine & Line {points[j], points[j + 1]};
            }
        }
    }
    sort(points, points + Tot);
}

bool Vis[maxn][maxn];

double Bfs() {
    memset(Vis, false, sizeof(Vis));
    priority_queue<Status> Que;
    Que.push(Status {0, Tot - 1, 0.0});
    while (!Que.empty()) {
        Status Cur = Que.top(); Que.pop();
        if (Cur.Left == Cur.Right) {
            return Cur.Length;
        }
        if (Vis[Cur.Left][Cur.Right]) {
            continue;
        }
        Vis[Cur.Left][Cur.Right] = true;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (i || j) {
                    int LeftIndex = Cur.Left + i, RightIndex = Cur.Right + j;
                    if (LeftIndex >= 0 && LeftIndex < Tot && RightIndex >= 0 && RightIndex < Tot) {
                        if (points[LeftIndex].Y == points[RightIndex].Y) {
                            Que.push(Status {LeftIndex, RightIndex, Cur.Length + Distance(points[Cur.Left], points[LeftIndex]) + Distance(points[Cur.Right], points[RightIndex])});
                        }
                    }
                }
            }
        }
    }
    return 0.0;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        Tot = 0;
        for (int i = 0; i <= N; ++i) {
            scanf("%d", &Height[i]);
            points[Tot++] = Point {double(i), double(Height[i])};
        }
        Init();
        printf("%.15lf\n", Bfs() * 2);
    }
    return 0;
}

