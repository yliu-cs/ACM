#include<bits/stdc++.h>
using namespace std;

struct Point {
    int X, Y;
};

int Dis(Point Key1, Point Key2) {
    return abs(Key1.X - Key2.X) + abs(Key1.Y - Key2.Y);
}

int N, M;
Point Treasure[100010][2];
long long Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &Treasure[i][0].X, &Treasure[i][0].Y);
        scanf("%d%d", &Treasure[i][1].X, &Treasure[i][1].Y);
    }
    for (int i = 1; i < N; ++i) {
        Ans += min(Dis(Treasure[i][0], Treasure[i + 1][0]) + Dis(Treasure[i][1], Treasure[i + 1][1]),
                Dis(Treasure[i][0], Treasure[i + 1][1]) + Dis(Treasure[i][1], Treasure[i + 1][0]));
    }
    Ans += Dis(Treasure[N][0], Treasure[N][1]);
    printf("%lld\n", Ans);
    return 0;
}

