#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e5 + 5);

int N, M;
vector<int> G[maxn];
vector<int> Ans;
set<int> Vis;

void Bfs() {
	priority_queue<int, vector<int>, greater<int> > Que;
	Que.push(1);
	Vis.insert(1);
	while (!Que.empty()) {
		int Cur = Que.top(); Que.pop();
		Ans.push_back(Cur);
		for (auto it : G[Cur]) {
			if (Vis.find(it) != Vis.end()) continue;
			Que.push(it);
			Vis.insert(it);
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for (int i = 1, U, V; i <= M; ++i) {
		scanf("%d%d", &U, &V);
		G[U].push_back(V); G[V].push_back(U);
	}
	Bfs();
	for (auto it : Ans) printf("%d ", it);
	return 0;
}
