#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct Point {
    int X, Y;
};

bool operator >= (Point Key1, Point Key2) {
    return Key1.X >= Key2.X && Key1.Y >= Key2.Y;
}

struct Rectangle {
    Point S, T;
};

int N;
int X1[maxn], Y1[maxn];
int X2[maxn], Y2[maxn];
Rectangle rectangles[maxn];
Point Check, Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
        rectangles[i] = (Rectangle){(Point){X1[i], Y1[i]}, (Point){X2[i], Y2[i]}};
    }
    sort(X1 + 1, X1 + N + 1);
    sort(Y1 + 1, Y1 + N + 1);
    sort(X2 + 1, X2 + N + 1);
    sort(Y2 + 1, Y2 + N + 1);
    for (int i = 1; i <= N; ++i) {
        Check = (Point){X1[N], Y1[N]};
        Ans = (Point){X2[1], Y2[1]};
        if (rectangles[i].S.X == X1[N] && X1[N - 1] < X1[N]) {
            Check.X = X1[N - 1];
        }
        if (rectangles[i].S.Y == Y1[N] && Y1[N - 1] < Y1[N]) {
            Check.Y = Y1[N - 1];
        }
        if (rectangles[i].T.X == X2[1] && X2[2] > X2[1]) {
            Ans.X = X2[2];
        }
        if (rectangles[i].T.Y == Y2[1] && Y2[2] > Y2[1]) {
            Ans.Y = Y2[2];
        }
        if (Ans >= Check) {
            break;
        }
    }
    printf("%d %d\n", Ans.X, Ans.Y);
    return 0;
}

