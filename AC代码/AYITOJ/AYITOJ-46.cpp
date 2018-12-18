#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e5 + 5;

struct Node {
    long long Left, Right;
    long long Lazy1, Lazy2;
    long long Sum;
};

Node SegmentTree[maxn << 2];

void PushDown(long long Root) {
    if (SegmentTree[Root].Lazy1) {
        SegmentTree[Root].Sum += SegmentTree[Root].Lazy1 * (SegmentTree[Root].Right - SegmentTree[Root].Left + 1);
        if (SegmentTree[Root].Left < SegmentTree[Root].Right) {
            SegmentTree[Root << 1].Lazy1 += SegmentTree[Root].Lazy1;
            SegmentTree[Root << 1 | 1].Lazy1 += SegmentTree[Root].Lazy1;
        }
        SegmentTree[Root].Lazy1 = 0;
    }
    if (SegmentTree[Root].Lazy2) {
        SegmentTree[Root].Sum += SegmentTree[Root].Lazy2 * (SegmentTree[Root].Right - SegmentTree[Root].Left + 1) * (SegmentTree[Root].Right - SegmentTree[Root].Left + 2) / 2;
        if (SegmentTree[Root].Left < SegmentTree[Root].Right) {
            SegmentTree[Root << 1].Lazy2 += SegmentTree[Root].Lazy2;
            SegmentTree[Root << 1 | 1].Lazy2 += SegmentTree[Root].Lazy2;
            SegmentTree[Root << 1 | 1].Lazy1 += SegmentTree[Root].Lazy2 * (SegmentTree[Root << 1].Right - SegmentTree[Root << 1].Left + 1);
        }
        SegmentTree[Root].Lazy2 = 0;
    }
}

void PushUp(long long Root) {
    PushDown(Root << 1); PushDown(Root << 1 | 1);
    SegmentTree[Root].Sum = SegmentTree[Root << 1].Sum + SegmentTree[Root << 1 | 1].Sum;
}

void Build(long long Left, long long Right, long long Root) {
    SegmentTree[Root] = Node {Left, Right, 0, 0, 0};
    if (Left == Right) {
        return;
    }
    long long Mid = (Left + Right) >> 1;
    Build(Left, Mid, Root << 1);
    Build(Mid + 1, Right, Root << 1 | 1);
}

void IntervalUpdate(long long Left, long long Right, long long Root) {
    if (SegmentTree[Root].Left >= Left && SegmentTree[Root].Right <= Right) {
        SegmentTree[Root].Lazy1 += SegmentTree[Root].Left - Left;
        SegmentTree[Root].Lazy2++;
        return;
    }
    long long Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Left <= Mid) {
        PushDown(Root);
        IntervalUpdate(Left, Right, Root << 1);
    }
    if (Right > Mid) {
        PushDown(Root);
        IntervalUpdate(Left, Right, Root << 1 | 1);
    }
    if (SegmentTree[Root].Left < SegmentTree[Root].Right) {
        PushUp(Root);
    }
}

long long Query(long long Left, long long Right, long long Root) {
    long long Ans = 0;
    PushDown(Root);
    if (SegmentTree[Root].Left >= Left && SegmentTree[Root].Right <= Right) {
        return SegmentTree[Root].Sum;
    }
    long long Mid = (SegmentTree[Root].Left + SegmentTree[Root].Right) >> 1;
    if (Left <= Mid) {
        Ans += Query(Left, Right, Root << 1);
    }
    if (Right > Mid) {
        Ans += Query(Left, Right, Root << 1 | 1);
    }
    return Ans;
}

long long T;
long long Op, Left, Right;
const long long Max = 1e5;

int main(int argc, char *argv[]) {
    Build(1, Max, 1);
    scanf("%lld", &T);
    for (long long Case = 1; Case <= T; ++Case) {
        scanf("%lld%lld%lld", &Op, &Left, &Right);
        if (Op == 0) {
            IntervalUpdate(Left, Right, 1);
        }
        else {
            printf("%lld\n", Query(Left, Right, 1));
        }
    }
    return 0;
}

