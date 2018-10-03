#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1e4 + 5;

struct Edge {
    int V, Next;
};

struct Query {
    int Q, Next;
    int Index;
};

int Pre[maxn << 2];
Edge edges[maxn << 2];
int Head[maxn];
int Tot;
Query querys[maxn << 2];
int Answer[maxn];
int QHead[maxn];
int QTot;
int Vis[maxn];
int Ancestor[maxn];
int F[maxn];

int Find(int X) {
    int R = X;
    while (Pre[R] != -1) {
        R = Pre[R];
    }
    return R;
}

void Join(int U, int V) {
    int RU = Find(U);
    int RV = Find(V);
    if (RU != RV) {
        Pre[RU] = RV;
    }
}

void AddEdge(int U, int V) {
    edges[Tot] = Edge {V, Head[U]};
    Head[U] = Tot++;
}

void AddQuery(int U, int V, int Index) {
    querys[QTot] = Query {V, QHead[U], Index};
    QHead[U] = QTot++;
    querys[QTot] = Query {U, QHead[V], Index};
    QHead[V] = QTot++;
}

void Init() {
    Tot = 0;
    memset(Head, -1, sizeof(Head));
    QTot = 0;
    memset(QHead, -1, sizeof(QHead));
    memset(Vis, false, sizeof(Vis));
    memset(Pre, -1, sizeof(Pre));
    memset(Ancestor, 0, sizeof(Ancestor));
    memset(F, -1, sizeof(F));
}

void LCA(int Node) {
    Ancestor[Node] = Node;
    Vis[Node] = true;
    for (int i = Head[Node]; i != -1; i = edges[i].Next) {
        if (Vis[edges[i].V]) {
            continue;
        }
        LCA(edges[i].V);
        Join(Node, edges[i].V);
        Ancestor[Find(Node)] = Node;
    }
    for (int i = QHead[Node]; i != -1; i = querys[i].Next) {
        if (Vis[querys[i].Q]) {
            Answer[querys[i].Index] = Ancestor[Find(querys[i].Q)];
        }
    }
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        Init();
        scanf("%d", &N);
        for (int i = 1, U, V; i < N; ++i) {
            scanf("%d%d", &U, &V);
            AddEdge(U, V);
            F[V] = U;
        }
        for (int i = 1, U, V; i <= 1; ++i) {
            scanf("%d%d", &U, &V);
            AddQuery(U, V, i);
        }
        int Root = 1;
        while (F[Root] != -1) {
            Root = F[Root];
        }
        LCA(Root);
        printf("%d\n", Answer[1]);
    }
    return 0;
}
