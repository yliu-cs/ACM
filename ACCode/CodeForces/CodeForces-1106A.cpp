#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(5e2 + 5);

int N;
char Map[maxn][maxn];
int Ans;

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", Map[i]);
	}
	for (int i = 1; i < N - 1; ++i) {
		for (int j = 1; j < N - 1; ++j) {
			if (Map[i][j] == 'X' &&
				Map[i - 1][j - 1] == 'X' &&
				Map[i - 1][j + 1] == 'X'&&
				Map[i + 1][j - 1] == 'X'&&
				Map[i + 1][j + 1] == 'X') {
				Ans++;
			}
		}
	}
	printf("%d\n", Ans);
	return 0;
}

