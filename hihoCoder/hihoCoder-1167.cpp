#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct Edge {
	int V, Next;
};

struct Query {
	int Q, Next;
	int Index;
};

struct Input {
	int U, V;
};

int N, P;
int Pre[maxn << 2];
Edge edges[maxn << 2];
int Head[maxn];
int Tot;
Query querys[maxn << 2];
int QHead[maxn];
int QTot;
int Vis[maxn];
int Ancestor[maxn];
int Answer[maxn];
int Sum[maxn];
int Cnt[maxn];
Input inputs[maxn];
long long Ans;

int Find(int X) {
	int R = X;
	while (Pre[R] != -1) {
		R = Pre[R];
	}
	return R;
}

void Join(int U, int V) {
	int RU = Find(U), RV = Find(V);
	if (RU != RV) {
		Pre[RU] = RV;
	}
}

void Init() {
	Tot = 0;
	memset(Head, -1, sizeof(Head));
	QTot = 0;
	memset(QHead, -1, sizeof(QHead));
	memset(Vis, false, sizeof(Vis));
	memset(Pre, -1, sizeof(Pre));
	memset(Ancestor, 0, sizeof(Ancestor));
	memset(Sum, 0, sizeof(Sum));
	memset(Cnt, 0, sizeof(Cnt));
}

void Addedge(int U, int V) {
	edges[Tot] = Edge {V, Head[U]};
	Head[U] = Tot++;
}

void AddQuery(int U, int V, int Index) {
	querys[QTot] = Query {V, QHead[U], Index};
	QHead[U] = QTot++;
	querys[QTot] = Query {U, QHead[V], Index};
	QHead[V] = QTot++;
}

void Tarjan(int Node) {
	Ancestor[Node] = Node;
	Vis[Node] = true;
	for (int i = Head[Node]; ~i; i = edges[i].Next) {
		if (Vis[edges[i].V]) {
			continue;
		}
		Tarjan(edges[i].V);
		Join(Node, edges[i].V);
		Ancestor[Find(Node)] = Node;
	}
	for (int i = QHead[Node]; ~i; i = querys[i].Next) {
		if (Vis[querys[i].Q]) {
			Answer[querys[i].Index] = Ancestor[Find(querys[i].Q)];
		}
	}
}

void Dfs(int Cur, int Parent) {
	Vis[Cur] = true;
	Sum[Cur] = Sum[Parent] + Cnt[Cur];
	for (int i = Head[Cur]; ~i; i = edges[i].Next) {
		if (Vis[edges[i].V]) {
			continue;
		}
		Dfs(edges[i].V, Cur);
	}
}

int main(int argc, char *argv[]) {
	Init();
	scanf("%d%d", &N, &P);
	for (int i = 1, U, V; i < N; ++i) {
		scanf("%d%d", &U, &V);
		Addedge(U, V);
	}
	for (int i = 1; i <= P; ++i) {
		scanf("%d%d", &inputs[i].U, &inputs[i].V);
		AddQuery(inputs[i].U, inputs[i].V, i);
	}
	Tarjan(1);
	for (int i = 1; i <= P; ++i) {
		Cnt[Answer[i]]++;
	}
	memset(Vis, false, sizeof(Vis));
	Dfs(1, 0);
	Ans = 0;
	for (int i = 1; i <= P; ++i) {
		Ans += Sum[inputs[i].U] + Sum[inputs[i].V] - 2 * Sum[Answer[i]];
	}
	for (int i = 1; i <= N; ++i) {
		Ans += 1LL * Cnt[i] * (Cnt[i] - 1) / 2;
	}
	printf("%lld\n", Ans);
    return 0;
}
