#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

// Root:Splay Tree根节点
int Root, Tot;
// Son[i][0]:i节点的左孩子，Son[i][0]:i节点的右孩子
int Son[maxn][2];
// Pre[i]:i节点的父节点
int Pre[maxn];
// Val[i]:i节点的权值
int Val[maxn];
// Size[i]:以i节点为根的Splay Tree的节点数(包含自身)
int Size[maxn];
// 惰性标记数组
bool Lazy[maxn];

void PushUp(int X) {
    Size[X] = Size[Son[X][0]] + Size[Son[X][1]] + 1;
}

void PushDown(int X) {
    if (Lazy[X]) {
        std::swap(Son[X][0], Son[X][1]);
        Lazy[Son[X][0]] ^= 1;
        Lazy[Son[X][1]] ^= 1;
        Lazy[X] ^= 1;
    }
}

// 判断X节点是其父节点的左孩子还是右孩子
bool Self(int X) {
    return Son[Pre[X]][1] == X;
}

// 旋转节点X
void Rotate(int X) {
    int Fa = Pre[X], FaFa = Pre[Fa], XJ = Self(X);
    PushDown(Fa); PushDown(X);
    Son[Fa][XJ] = Son[X][XJ ^ 1];
    Pre[Son[Fa][XJ]] = Pre[X];
    Son[X][XJ ^ 1] = Pre[X];
    Pre[Fa] = X;
    Pre[X] = FaFa;
    if (FaFa) {
        Son[FaFa][Fa == Son[FaFa][1]] = X;
    }
    PushUp(Fa); PushUp(X);
}

// 旋转X节点到节点Goal
void Splay(int X, int Goal = 0) {
    for (int Cur = Pre[X]; (Cur = Pre[X]) != Goal; Rotate(X)) {
        if (Pre[Cur] != Goal) {
            if (Self(X) == Self(Cur)) {
                Rotate(Cur);
            }
            else {
                Rotate(X);
            }
        }
    }
    PushUp(X);
    if (!Goal) {
        Root = X;
    }
}

// 获取以R为根节点Splay Tree中的第K大个元素在Splay Tree中的位置
int Kth(int R, int K) {
    PushDown(R);
    int Temp = Size[Son[R][0]] + 1;
    if (Temp == K) {
        return R;
    }
    if (Temp > K) {
        return Kth(Son[R][0], K);
    }
    else {
        return Kth(Son[R][1], K - Temp);
    }
}

// 翻转Splay Tree中Left~Right区间
void Reverse(int Left, int Right) {
    int X = Kth(Root, Left), Y = Kth(Root, Right + 2);
    Splay(X, 0);
    Splay(Y, X);
    PushDown(Root);
    Lazy[Son[Y][0]] ^= 1;
}

// 建立Splay Tree
void Build(int Left, int Right, int Cur) {
    if (Left > Right) {
        return;
    }
    int Mid = (Left + Right) >> 1;
    Build(Left, Mid - 1, Mid);
    Build(Mid + 1, Right, Mid);
    Pre[Mid] = Cur;
    Val[Mid] = Mid - 1;
    PushUp(Mid);
    if (Mid < Cur) {
        Son[Cur][0] = Mid;
    }
    else {
        Son[Cur][1] = Mid;
    }
}

int main(int argc, char *argv[]) {
    int N, M;
    scanf("%d%d", &N, &M);
    Build(1, N + 2, 0);
    Root = (N + 3) >> 1;
    for (int i = 0, Left, Right; i < M; ++i) {
        scanf("%d%d", &Left, &Right);
        Reverse(Left, Right);
    }
    for (int i = 2; i <= N + 1; ++i) {
        printf("%d ", Val[Kth(Root, i)]);
    }
    return 0;
}

