#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const double eps = 1e-8;

struct Point {
    long double X, Y;
    void input() {
        scanf("%LF%LF", &X, &Y);
    }
};

int N;
Point points[maxn];

bool Judge(long double R) {
    long double Left = -1e18, Right = 1e18;
    for (int i = 1; i <= N; ++i) {
        if (points[i].Y > R + R) {
            return false;
        }
        long double Dis = sqrt((2 * R - points[i].Y) * points[i].Y);
        Left = max(Left, points[i].X - Dis);
        Right = min(Right, points[i].X + Dis);
    }
    return Left <= Right;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    bool UpFlag = false, DownFlag = false;
    for (int i = 1; i <= N; ++i) {
        points[i].input();
        if (points[i].Y > 0) {
            UpFlag = true;
        }
        else if (points[i].Y < 0) {
            DownFlag = true;
        }
        points[i].Y = fabs(points[i].Y);
    }
    if (UpFlag && DownFlag) {
        printf("-1\n");
        return 0;
    }
    long double Left = 0, Right = 1e18;
    int Cnt = 100;
    while (Right - Left > eps && Cnt--) {
        long double Mid = (Left + Right) / 2.0;
        if (Judge(Mid)) {
            Right = Mid;
        }
        else {
            Left = Mid;
        }
    }
    printf("%LF\n", Left);
    return 0;
}
