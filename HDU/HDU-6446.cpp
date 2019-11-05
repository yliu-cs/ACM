#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

struct Link {
	int V, Weight, Next;
	Link(int _V = 0, int _Weight = 0, int _Next = 0): V(_V), Weight(_Weight), Next(_Next) {}
};

int N;
int Tot;
long long Ans, Cnt;
Link edges[maxn << 1];
int Head[maxn];
long long Sum[maxn];

void AddEdge(int U, int V, int Weight) {
	edges[Tot].V = V;
	edges[Tot].Weight = Weight;
	edges[Tot].Next = Head[U];
	Head[U] = Tot++;
}

void Dfs(int Vertex, int Father) {
	Sum[Vertex] = 1;
	for (int i = Head[Vertex]; i != -1; i = edges[i].Next) {
		if (edges[i].V != Father) {
			Dfs(edges[i].V, Vertex);
			Sum[Vertex] += Sum[edges[i].V];
			Ans = (Ans + Sum[edges[i].V] * (N - Sum[edges[i].V]) * edges[i].Weight % mod) % mod;
		}
	}
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", &N)) {
		Tot = 0;
		memset(Head, -1, sizeof(Head));
		for (int i = 1, U, V, C; i < N; ++i) {
			scanf("%d%d%d", &U, &V, &C);
			AddEdge(U, V, C);
			AddEdge(V, U, C);
		}
		memset(Sum, 0, sizeof(Sum));
		Ans = 0;
		Dfs(1, -1);
		Cnt = 2;
		for (int i = 3; i <= N; ++i) {
			Cnt = Cnt * (i - 1) % mod;
		}
		printf("%lld\n", Ans * Cnt % mod);
	}
	return 0;
}
