#include <bits/stdc++.h>

const int maxn = "Edit";

// 链式前向星建图
struct Link {
    int V, Next;
};

Link edges[maxn << 1];
int Head[maxn];
int Tot = 0;

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V) {
    edges[++Tot] = Link {V, Head[U]};
    Head[U] = Tot;
    edges[++Tot] = Link {U, Head[V]};
    Head[V] = Tot;
}

int Cnt;
int InIndex[maxn], OutIndex[maxn];

// Dfs序
void DfsOrder(int Cur, int Pre) {
    Cnt++;
    InIndex[Cur] = Cnt;
    for (int i = Head[Cur]; i != -1; i = edges[i].Next) {
        if (edges[i].V != Pre) {
            DfsOrder(edges[i].V, Node);
        }
    }
    OutIndex[Cur] = Cnt;
}
