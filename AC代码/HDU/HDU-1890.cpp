#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

struct Node;

Node* Null;

struct Node {
    Node *Son[2], *Pre;
    int Size;
    int Rev;
    Node() {
        Son[0] = Son[1] = Pre = Null;
        Rev = 0;
    }
    inline void PushUp() {
        if (this == Null) {
            return;
        }
        Size = Son[0] -> Size + Son[1] -> Size + 1;
    }
    inline void Adjust(Node* P, int WhichSon) {
        Son[WhichSon] = P;
        P -> Pre = this;
    }
    inline bool SelfJudge() {
        return Pre -> Son[1] == this;
    }
    void Clear() {
        Size = 1;
        Son[0] = Son[1] = Pre = Null;
        Rev = 0;
    }
    void UpdateRev() {
        if (this == Null) {
            return;
        }
        std::swap(Son[0], Son[1]);
        Rev ^= 1;
    }
    inline void PushDown() {
        if (this == Null) {
            return;
        }
        if (Rev) {
            Son[0] -> UpdateRev();
            Son[1] -> UpdateRev();
            Rev = 0;
        }
    }
    inline bool IsRoot() {
        return Pre == Null || this != Pre -> Son[0] && this != Pre -> Son[1];
    }
};

inline void Rotate(Node* X) {
    Node *Pre = X -> Pre, *PrePre = X -> Pre -> Pre;
    Pre -> PushDown();
    X -> PushDown();
    int J = X -> SelfJudge(), PreJ = Pre -> SelfJudge();
    Pre -> Adjust(X -> Son[!J], J);
    X -> Adjust(Pre, !J);
    if (PrePre -> Son[PreJ] == Pre) {
        PrePre -> Adjust(X, PreJ);
    }
    else {
        X -> Pre = PrePre;
    }
    Pre -> PushUp();
}

inline void Splay(Node* &Root, Node* X, Node* Goal) {
    while (X -> Pre != Goal) {
        if (X -> Pre -> Pre == Goal) {
            Rotate(X);
        }
        else {
            X -> Pre -> Pre -> PushDown();
            X -> Pre -> PushDown();
            X -> PushDown();
            if (X -> SelfJudge() == (X -> Pre -> SelfJudge())) {
                Rotate(X -> Pre);
            }
            else {
                Rotate(X);
            }
            Rotate(X);
        }
    }
    X -> PushUp();
    if (Goal == Null) {
        Root = X;
    }
}

Node* GetKth(Node* Root, int K) {
    Node* X = Root;
    X -> PushDown();
    while (X -> Son[0] -> Size + 1 != K) {
        if (K < X -> Son[0] -> Size + 1) {
            X = X -> Son[0];
        }
        else {
            K -= X -> Son[0] -> Size + 1;
            X = X -> Son[1];
        }
        X -> PushDown();
    }
    return X;
}

Node Pool[maxn], *Tail;
Node *SplayTree[maxn];
Node *Root;

void Build(Node* &X, int Left, int Right, Node* Pre) {
    if (Left > Right) {
        return;
    }
    int Mid = (Left + Right) / 2;
    X = Tail++;
    X -> Clear();
    X -> Pre = Pre;
    SplayTree[Mid] = X;
    Build(X -> Son[0], Left, Mid - 1, X);
    Build(X -> Son[1], Mid + 1, Right, X);
    X -> PushUp();
}

void Init(int N) {
    Tail = Pool;
    Null = Tail++;
    Null -> Pre = Null -> Son[0] = Null -> Son[1] = Null;
    Null -> Size = 0;
    Null -> Rev = 0;
    Node* P = Tail++;
    P -> Clear();
    Root = P;
    P = Tail++;
    P -> Clear();
    Root -> Adjust(P, 1);
    Build(Root -> Son[1] -> Son[0], 1, N, Root -> Son[1]);
    Root -> Son[1] -> PushUp();
    Root -> PushUp();
}

int A[maxn], B[maxn];

bool Cmp(int i, int j) {
    if (A[i] != A[j]) {
        return A[i] < A[j];
    }
    else {
        return i < j;
    }
}

int main(int argc, char *argv[]) {
    int N;
    while (~scanf("%d", &N) && N) {
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &A[i]);
            B[i] = i;
        }
        Init(N);
        std::sort(B + 1, B + N + 1, Cmp);
        for (int i = 1; i <= N; ++i) {
            Splay(Root, SplayTree[B[i]], Null);
            int Sz = Root -> Son[0] -> Size;
            printf("%d", Root -> Son[0] -> Size);
            if (i == N) {
                printf("\n");
            }
            else {
                printf(" ");
            }
            Splay(Root, GetKth(Root, i), Null);
            Splay(Root, GetKth(Root, Sz + 2), Root);
            Root -> Son[1] -> Son[0] -> UpdateRev();
        }
    }
    return 0;
}
