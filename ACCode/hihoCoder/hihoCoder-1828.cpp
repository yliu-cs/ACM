#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

struct Statu {
	int X, Y, Step, Oxygen, Pill;
};

int N, M;
int StartX, StartY;
int EndX, EndY;
char Maze[maxn][maxn];
int Step[maxn][maxn][10];

void Bfs() {
	queue<Statu> Que;
	Que.push(Statu {StartX, StartY, 0, 0, 0});
	while (!Que.empty()) {
		Statu Keep = Que.front();
		Que.pop();
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (abs(i) != abs(j)) {
					int NX = Keep.X + i, NY = Keep.Y + j;
					if (NX >= 0 && NX < N && NY >= 0 && NY < M) {
						if (Maze[NX][NY] == '#') {
							if (Keep.Oxygen > 0) {
								if (Keep.Step + 2 - Keep.Pill < Step[NX][NY][Keep.Oxygen - 1]) {
									Que.push(Statu {NX, NY, Keep.Step + 2, Keep.Oxygen - 1, Keep.Pill});
									Step[NX][NY][Keep.Oxygen - 1] = Keep.Step + 2 - Keep.Pill;
								}
							}
						}
						else if (Maze[NX][NY] == 'B') {
							if (Keep.Oxygen == 5) {
								if (Keep.Step + 1 - Keep.Pill < Step[NX][NY][Keep.Oxygen]) {
									Que.push(Statu {NX, NY, Keep.Step + 1, Keep.Oxygen, Keep.Pill});
									Step[NX][NY][Keep.Oxygen] = Keep.Step + 1 - Keep.Pill;
								}
							}
							else {
								if (Keep.Step + 1 - Keep.Pill < Step[NX][NY][Keep.Oxygen + 1]) {
									Que.push(Statu {NX, NY, Keep.Step + 1, Keep.Oxygen + 1, Keep.Pill});
									Step[NX][NY][Keep.Oxygen + 1] = Keep.Step + 1 + Keep.Pill;
								}
							}
						}
						else if (Maze[NX][NY] == 'P') {
							if (Keep.Step - Keep.Pill < Step[NX][NY][Keep.Oxygen]) {
								Que.push(Statu {NX, NY, Keep.Step + 1, Keep.Oxygen, Keep.Pill + 1});
								Step[NX][NY][Keep.Oxygen] = Keep.Step - Keep.Pill;
							}
						}
						else {
							if (Keep.Step + 1 - Keep.Pill < Step[NX][NY][Keep.Oxygen]) {
								Que.push(Statu {NX, NY, Keep.Step + 1, Keep.Oxygen, Keep.Pill});
								Step[NX][NY][Keep.Oxygen] = Keep.Step + 1 - Keep.Pill;
							}
						}
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	while (~scanf("%d%d", &N, &M) && N + M) {
		for (int i = 0; i < N; ++i) {
			scanf("%s", Maze[i]);
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k < 6; ++k) {
					Step[i][j][k] = INF;
				}
				if (Maze[i][j] == 'S') {
					StartX = i; StartY = j;
				}
				else if (Maze[i][j] == 'T') {
					EndX = i; EndY = j;
				}
			}
		}
		Bfs();
		int Ans = INF;
		for (int i = 0; i < 6; ++i) {
			Ans = min(Ans, Step[EndX][EndY][i]);
		}
		Ans = Ans == INF ? -1 : Ans;
		printf("%d\n", Ans);
	}
	return 0;
}

