#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn = 2e2 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}

struct Segment {
    db Left, Right;
    db Height;
    int Flag;
};
bool operator < (Segment &Key1, Segment &Key2) {return Cmp(Key1.Height, Key2.Height) < 0;}
vector<Segment> Seg;

vector<db> Pos;

int BinarySearch(db Key) {
    int Res = Pos.size() - 1, Left = 0, Right = Pos.size() - 1;
    while (Left <= Right) {
        int Mid = (Left + Right) >> 1;
        if (Cmp(Pos[Mid], Key) >= 0) {
            Res = Mid;
            Right = Mid - 1;
        }
        else {
            Left = Mid + 1;
        }
    }
    return Res;
}

struct Node {
    int Left, Right;
    int Cnt;
    db Len;
};
Node SGT[maxn << 2];

void PushUp(int Root) {
    if (SGT[Root].Cnt) SGT[Root].Len = Pos[SGT[Root].Right + 1] - Pos[SGT[Root].Left];
    else if (SGT[Root].Left == SGT[Root].Right) SGT[Root].Len = 0.0;
    else SGT[Root].Len = SGT[Root << 1].Len + SGT[Root << 1 | 1].Len;
}

void Build(int Left, int Right, int Root) {
    SGT[Root].Left = Left; SGT[Root].Right = Right;
    SGT[Root].Cnt = 0; SGT[Root].Len = 0.0;
    if (Left == Right) return;
    int Mid = (Left + Right) >> 1;
    Build(Left, Mid, Root << 1);
    Build(Mid + 1, Right, Root << 1 | 1);
    PushUp(Root);
}

void Update(int Left, int Right, int Value, int Root) {
    if (Left <= SGT[Root].Left && Right >= SGT[Root].Right) {
        SGT[Root].Cnt += Value;
        PushUp(Root);
        return;
    }
    int Mid = (SGT[Root].Left + SGT[Root].Right) >> 1;
    if (Right <= Mid) Update(Left, Right, Value, Root << 1);
    else if (Left > Mid) Update(Left, Right, Value, Root << 1 | 1);
    else {
        Update(Left, Mid, Value, Root << 1);
        Update(Mid + 1, Right, Value, Root << 1 | 1);
    }
    PushUp(Root);
}

int Case;
int N;
db X1, Y1, X2, Y2;
db Ans;

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N) {
        Seg.clear(); Pos.clear();
        for (int i = 0; i < N; ++i) {
            scanf("%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
            Seg.push_back((Segment){X1, X2, Y1, 1});
            Seg.push_back((Segment){X1, X2, Y2, -1});
            Pos.push_back(X1); Pos.push_back(X2);
        }
        sort(Seg.begin(), Seg.end());
        sort(Pos.begin(), Pos.end(), [&](db Key1, db Key2) {return Cmp(Key1, Key2) < 0;});
        int Cur = 1;
        for (int i = 1; i < (int)Pos.size(); ++i)
            if (Cmp(Pos[i], Pos[i - 1]) != 0)
                Pos[Cur++] = Pos[i];
        Pos.erase(Pos.begin() + Cur, Pos.end());
        Build(0, (int)Pos.size(), 1);
        Ans = 0.0;
        for (int i = 0; i < (int)Seg.size() - 1; ++i) {
            int Left = BinarySearch(Seg[i].Left), Right = BinarySearch(Seg[i].Right);
            Update(Left, Right - 1, Seg[i].Flag, 1);
            Ans += (Seg[i + 1].Height - Seg[i].Height) * SGT[1].Len;
        }
        printf("Test case #%d\n", ++Case);
        printf("Total explored area: %.2lf\n\n", Ans);
    }
    return 0;
}

