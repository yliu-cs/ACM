#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

struct Point {int X, Y;};
bool operator < (Point Key1, Point Key2) {
    if (Key1.X == Key2.X) return Key1.Y < Key2.Y;
    return Key1.X < Key2.X;
}
bool operator == (Point Key1, Point Key2) {
    return Key1.X == Key2.X && Key1.Y == Key2.Y;
}

int N;
Point S, T;
bool Map[maxn][maxn];
set<Point> Vis;
set<Point> SetS, SetT;
int Ans;

bool Bfs() {
    queue<Point> Que;
    Que.push(S); Vis.insert(S);
    while (!Que.empty()) {
        Point Cur = Que.front(); Que.pop();
        if (Cur == T) return true;
        SetS.insert(Cur);
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) == abs(j)) continue;
                Point Next = (Point){Cur.X + i, Cur.Y + j};
                if (Vis.find(Next) != Vis.end()) continue;
                if (Next.X > 0 && Next.X <= N && Next.Y > 0 && Next.Y <= N && Map[Next.X][Next.Y]) {
                    Que.push(Next);
                    Vis.insert(Next);
                }
            }
        }
    }
    Vis.clear();
    while (!Que.empty()) Que.pop();
    Que.push(T); Vis.insert(T);
    while (!Que.empty()) {
        Point Cur = Que.front(); Que.pop();
        SetT.insert(Cur);
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) == abs(j)) continue;
                Point Next = (Point){Cur.X + i, Cur.Y + j};
                if (Vis.find(Next) != Vis.end()) continue;
                if (Next.X > 0 && Next.X <= N && Next.Y > 0 && Next.Y <= N && Map[Next.X][Next.Y]) {
                    Que.push(Next);
                    Vis.insert(Next);
                }
            }
        }
    }
    return false;
}

int GetCost(Point Key1, Point Key2) {
    return (Key1.X - Key2.X) * (Key1.X - Key2.X) + (Key1.Y - Key2.Y) * (Key1.Y - Key2.Y);
}

int main(int argc, char *argv[]) {
    cin >> N;
    cin >> S.X >> S.Y;
    cin >> T.X >> T.Y;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            char X; cin >> X;
            if (X == '0') Map[i][j] = true;
        }
    }
    if (Bfs()) {
        cout << 0 << endl;
        return 0;
    }
    Ans = INF;
    for (auto &i : SetS)
        for (auto &j : SetT)
            Ans = min(Ans, GetCost(i, j));
    cout << Ans << endl;
    return 0;
}

