#include <bits/stdc++.h>
using namespace std;

const int mod = 7;
const int maxn = 5e1 + 5;

int main(int argc, char *argv[]) {
	int A, B, N;
	while (scanf("%d%d%d", &A, &B, &N) && A + B + N) {
		int F[maxn];
		F[1] = F[2] = 1;
		for (int i = 3; i < maxn; ++i) {
			F[i] = (A * F[i - 1] + B * F[i - 2]) % 7;
		}
		printf("%d\n", F[N % 49]);
	}
    return 0;
}
