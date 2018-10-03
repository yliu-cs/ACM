#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

struct Node {
    int Left, Right;
    int Lazy, Tag;
    int Sum;
}SegmentTree[maxn * 3];

void Build(int Left, int Right, int Root) {
    SegmentTree[Root].Left = Left;
    SegmentTree[Root].Right = Right;
    SegmentTree[Root].Lazy = 0;
    SegmentTree[Root].Tag = 0;
    if (Left == Right) {
        scanf("%d", &SegmentTree[Root].Sum);
        return;
    }
    int Mid = (Left + Right) >> 1;
    Build(Left, Mid, Root << 1);
    Build(Mid + 1, Right, Root << 1 | 1);
    SegmentTree[Root].Sum = SegmentTree[Root << 1].Sum + SegmentTree[Root << 1 | 1].Sum;
}

void PointUpdate(int Pos, int Value, int Root) {
    SegmentTree[Root].Sum += Value;
    if (SegmentTree[Root].Left == Pos && SegmentTree[Root].Right == Pos) {
        return;
    }
    int Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Pos <= Mid) {
        PointUpdate(Pos, Value, Root << 1);
    }
    else {
        PointUpdate(Pos, Value, Root << 1 | 1);
    }
}

void IntervalUpdate(int Left, int Right, int Value, int Root) {
    if (SegmentTree[Root].Left == Left && SegmentTree[Root].Right == Right) {
        SegmentTree[Root].Lazy = 1;
        SegmentTree[Root].Tag = Value;
        SegmentTree[Root].Sum = (Right - Left + 1) * Value;
        return;
    }
    int Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (SegmentTree[Root].Lazy == 1) {
        SegmentTree[Root].Lazy = 0;
        IntervalUpdate(SegmentTree[Root].Left, Mid, SegmentTree[Root].Tag, Root << 1);
        IntervalUpdate(Mid + 1, SegmentTree[Root].Right, SegmentTree[Root].Tag, Root << 1 | 1);
        SegmentTree[Root].Tag = 0;
    }
    if (Right <= Mid) {
        IntervalUpdate(Left, Right, Value, Root << 1);
    }
    else if (Left > Mid) {
        IntervalUpdate(Left, Right, Value, Root << 1 | 1);
    }
    else {
        IntervalUpdate(Left, Mid, Value, Root << 1);
        IntervalUpdate(Mid + 1, Right, Value, Root << 1 | 1);
    }
    SegmentTree[Root].Sum = SegmentTree[Root << 1].Sum + SegmentTree[Root << 1 | 1].Sum;
}

int Query(int Left, int Right, int Root) {
    if (Left == SegmentTree[Root].Left && Right == SegmentTree[Root].Right) {
        return SegmentTree[Root].Sum;
    }
    int Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Right <= Mid) {
        return Query(Left, Right, Root << 1);
    }
    else if (Left > Mid) {
        return Query(Left, Right, Root << 1 | 1);
    }
    else {
        return Query(Left, Mid, Root << 1) + Query(Mid + 1, Right, Root << 1 | 1);
    }
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        Build(1, N, 1);
        std::string str;
        int I, J;
        printf("Case %d:\n", Case);
        while (std::cin >> str) {
            if (str == "End") {
                break;
            }
            else {
                scanf("%d%d", &I, &J);
                if (str == "Add") {
                    PointUpdate(I, J, 1);
                }
                else if (str == "Sub") {
                    PointUpdate(I, -J, 1);
                }
                else if (str == "Query") {
                    printf("%d\n", Query(I, J, 1));
                }
            }
        }
    }
    return 0;
}

