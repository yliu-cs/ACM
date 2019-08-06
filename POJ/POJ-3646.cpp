#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int N, M;
	while (~scanf("%d%d", &N, &M) && N + M) {
		vector<int> A(N), B(M);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < M; ++i) {
			scanf("%d", &B[i]);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int Ans = 0, Cur = 0;
		bool Suc = true;
		for (int i = 0; i < N; ++i) {
			bool Flag = false;
			for (int j = Cur; j < M; ++j) {
				if (B[j] >= A[i]) {
					Cur = j + 1;
					Ans += B[j];
					Flag = true;
					break;
				}
			}
			if (!Flag) {
				Suc = false;
			}
		}
		if (Suc) {
			printf("%d\n", Ans);
		}
		else {
			printf("Loowater is doomed!\n");
		}
	}
	return 0;
}