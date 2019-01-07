#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct Node {
    int Left, Right, Max;
    Node(int _Left = 0, int _Right = 0, int _Max = 0): Left(_Left), Right(_Right), Max(_Max) {}
};

Node SegmentTree[maxn << 2];

void Build(int Left, int Right, int Root) {
    SegmentTree[Root].Left = Left;
    SegmentTree[Root].Right = Right;
    SegmentTree[Root].Max = 0;
    if (Left == Right) {
        return;
    }
    int Mid = (Left + Right) >> 1;
    Build(Left, Mid, Root << 1);
    Build(Mid + 1, Right, Root << 1 | 1);
    SegmentTree[Root].Max = max(SegmentTree[Root << 1].Max, SegmentTree[Root << 1 | 1].Max);
}

void PointUpdate(int Pos, int Value, int Root) {
    if (SegmentTree[Root].Left == Pos && SegmentTree[Root].Right == Pos) {
        SegmentTree[Root].Max = Value;
        return;
    }
    int Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Pos <= Mid) {
        PointUpdate(Pos, Value, Root << 1);
    }
    else {
        PointUpdate(Pos, Value, Root << 1 | 1);
    }
    SegmentTree[Root].Max = max(SegmentTree[Root << 1].Max, SegmentTree[Root << 1 | 1].Max);
}

int Query(int Left, int Right, int Root) {
    if (Left == SegmentTree[Root].Left && Right == SegmentTree[Root].Right) {
        return SegmentTree[Root].Max;
    }
    int Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Right <= Mid) {
        return Query(Left, Right, Root << 1);
    }
    else if (Left > Mid) {
        return Query(Left, Right, Root << 1 | 1);
    }
    else {
        return max(Query(Left, Mid, Root << 1), Query(Mid + 1, Right, Root << 1 | 1));
    }
}

struct Point {
    int X, Y, Weight;
    Point(int _X = 0, int _Y = 0, int _Weight = 0): X(_X), Y(_Y), Weight(_Weight) {}
};

int T;
int N;
int Ans;
int PosX[maxn], PosY[maxn];
int Dp[maxn];
Point points[maxn];

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d%d", &points[i].X, &points[i].Y, &points[i].Weight);
            PosX[i] = points[i].X;
            PosY[i] = points[i].Y;
        }
        // 离散化
        PosX[N] = 0; PosY[N] = 0;
        sort(PosX, PosX + N + 1);
        sort(PosY, PosY + N + 1);
        int XNum = unique(PosX, PosX + N + 1) - PosX;
        int YNum = unique(PosY, PosY + N + 1) - PosY;
        for (int i = 0; i < N; ++i) {
            points[i].X = lower_bound(PosX, PosX + XNum, points[i].X) - PosX;
            points[i].Y = lower_bound(PosY, PosY + YNum, points[i].Y) - PosY;
        }
        // 线段树中存储每一行中的最大值
        sort(points, points + N, [&] (const Point &a, const Point &b) {
                if (a.X == b.X) {
                    return a.Y > b.Y;
                }
                return a.X < b.X;
        });
        Build(0, YNum, 1);
        memset(Dp, 0, sizeof(Dp));
        // 根据线段数按列更新Dp数组和线段树
        for (int i = 0; i < N; ++i) {
            int Flag = points[i].X, j;
            for (j = i; j < N; ++j) {
                if (points[j].X != Flag) {
                    break;
                }
                int Temp = Query(0, points[j].Y - 1, 1) + points[j].Weight;
                if (Temp > Dp[points[j].Y]) {
                    Dp[points[j].Y] = Temp;
                    PointUpdate(points[j].Y, Dp[points[j].Y], 1);
                }
            }
            i = j - 1;
        }
        Ans = 0;
        for (int i = 0; i <= YNum; ++i) {
            Ans = max(Ans, Dp[i]);
        }
        printf("%d\n", Ans);
    }
    return 0;
}

