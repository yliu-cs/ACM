#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5;
const double eps = 1e-8;

struct Gear {
    double X, Y, R, V;
};

int T;
int N;
double EndX, EndY;
int Start, End;
Gear gears[maxn];
bool Vis[maxn];
double Ans[maxn];

bool Check(Gear &A, Gear &B) {
    if (fabs((B.Y - A.Y) * (B.Y - A.Y) + (B.X - A.X) * (B.X - A.X)) - ((A.R + B.R) * (A.R + B.R)) < eps) {
        return true;
    }
    return false;
}

void Bfs() {
    for (int i = 0; i < N; ++i) {
        Vis[i] = false;
    }
    queue<int> Que;
    Que.push(Start);
    Vis[Start] = true;
    while (!Que.empty()) {
        int Cur = Que.front();
        Que.pop();
        if (Cur == End) {
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (Check(gears[Cur], gears[i]) && !Vis[i]) {
                gears[i].V = fabs(gears[Cur].V * gears[Cur].R / gears[i].R);
                Que.push(i);
                Ans[i] = Ans[Cur] + gears[i].V;
                Vis[i] = true;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%lf%lf", &N, &EndX, &EndY);
        for (int i = 0; i < N; ++i) {
            Ans[i] = 0;
            scanf("%lf%lf%lf", &gears[i].X, &gears[i].Y, &gears[i].R);
            if (fabs(gears[i].X - 0.0) < eps && fabs(gears[i].Y - 0.0) < eps) {
                Start = i;
                gears[i].V = 10000;
                Ans[Start] = 10000;
            }
            else if (fabs(gears[i].X - EndX) < eps && fabs(gears[i].Y - EndY) < eps) {
                End = i;
            }
        }
        Bfs();
        printf("%lld\n", (long long)Ans[End]);
    }
    return 0;
}

