#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e3 + 5);

struct Edge {int V, Next;};

int Tot;
int Head[maxn];
Edge edges[maxn * maxn];
int InDegree[maxn];

void AddEdge(int U, int V) {
	edges[Tot] = (Edge){V, Head[U]};
	Head[U] = Tot++;
	++InDegree[V];
}

int N;
long long A[maxn];
long long B[maxn];

struct Cmp {
	bool operator () (int Key1, int Key2) {
		return B[Key1] > B[Key2];
	}
};

void TopoSort() {
	priority_queue<int, vector<int>, Cmp > Que;
	for (int i = 0; i < N; ++i)
		if (InDegree[i] == 0) Que.push(i);
	for (int i = 0; i < N; ++i) {
		int Cur = Que.top(); Que.pop();
		A[i] = B[Cur];
		for (int j = Head[Cur]; ~j; j = edges[j].Next) {
			InDegree[edges[j].V]--;
			if (InDegree[edges[j].V] == 0) Que.push(edges[j].V);
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) Head[i] = -1;
	for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
	for (int i = 0; i < N; ++i) {
		int Pos = B[i] % N;
		while (Pos % N != i) {
			AddEdge(Pos % N, i);
			++Pos;
		}
	}
	TopoSort();
	for (int i = 0; i < N; ++i) printf("%d ", A[i]);
	printf("\n");
	return 0;
}

