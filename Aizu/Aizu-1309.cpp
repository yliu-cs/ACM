#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;

struct Point {
    double X, Y;

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    void Output() {
        printf("(%lf,%lf)", X, Y);
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

    void Input() {
        S.Input();
        T.Input();
    }

    Point operator & (const Line &B) const {
        double Temp = ((S - B.S) ^ (B.S - B.T)) / ((S - T) ^ (B.S - B.T));
        return Point {S.X + (T.X - S.X) * Temp, S.Y + (T.Y - S.Y) * Temp};
    }
};

struct Statu {
    int Left, Right;
    double Length;

    bool operator < (const Statu &B) const {
        return Length > B.Length;
    }
};

int N;
int Tot;
Point points[maxn];
set<pair<int, int> > Vis;

void Init() {
    for (int i = 0; i < N; ++i) {
        double Height = points[i].Y;
        Line SkyLine = Line {Point {-1005.0, Height}, Point {1005.0, Height}};
        for (int j = 0; j < N - 1; ++j) {
            if ((Height - points[j].Y) * (Height - points[j + 1].Y) < 0) {
                points[Tot++] = SkyLine & Line {points[j], points[j + 1]};
            }
        }
    }
    sort(points, points + Tot);
}

double Bfs() {
    Vis.clear();
    priority_queue<Statu> Que;
    Que.push(Statu {0, Tot - 1, 0.0});
    while (!Que.empty()) {
        Statu Cur = Que.top(); Que.pop();
        if (Cur.Left == Cur.Right) {
            return Cur.Length;
        }
        if (Vis.find(make_pair(Cur.Left, Cur.Right)) != Vis.end()) {
            continue;
        }
        Vis.insert(make_pair(Cur.Left, Cur.Right));
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (i || j) {
                    int LeftIndex = Cur.Left + i, RightIndex = Cur.Right + j;
                    if (LeftIndex >= 0 && LeftIndex < Tot && RightIndex >= 0 && RightIndex < Tot) {
                        if (points[LeftIndex].Y == points[RightIndex].Y) {
                            Que.push(Statu {LeftIndex, RightIndex, Cur.Length + Distance(points[Cur.Left], points[LeftIndex]) + Distance(points[Cur.Right], points[RightIndex])});
                        }
                    }
                }
            }
        }
    }
    return 0.0;
}

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N) {
        Tot = 0;
        for (int i = 0; i < N; ++i) {
            points[Tot++].Input();
        }
        Init();
        printf("%.10lf\n", Bfs());
    }
    return 0;
}

