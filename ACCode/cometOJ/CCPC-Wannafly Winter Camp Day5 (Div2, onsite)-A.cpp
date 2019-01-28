#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e3 + 5);

struct Edge {int V, Next;};

int Tot;
int Head[maxn];
Edge edges[maxn << 1];

void AddEdge(int U, int V) {
	edges[Tot] = (Edge){V, Head[U]};
	Head[U] = Tot++;
	edges[Tot] = (Edge){U, Head[V]};
	Head[V] = Tot++;
}

struct Point {int X, Y;};

int N, M;
int Pos[maxn];
Point Ans[maxn];

void Dfs(int Cur, int Pre, int Depth) {
	Ans[Cur] = (Point){Pos[Depth]++, Depth};
	for (int i = Head[Cur]; ~i; i = edges[i].Next) {
		if (edges[i].V == Pre) continue;
		Dfs(edges[i].V, Cur, Depth + 1);
	}
}


int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) Pos[i] = 1;
	for (int i = 1; i <= N; ++i) Head[i] = -1;
	for (int i = 1, U, V; i <= M; ++i) {
		scanf("%d%d", &U, &V);
		AddEdge(U, V);
	}
	Dfs(1, 0, 1);
	for (int i = 1; i <= N; ++i) printf("%d %d\n", Ans[i].X, Ans[i].Y);
	return 0;
}

