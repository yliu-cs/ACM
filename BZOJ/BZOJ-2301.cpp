#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(5e4 + 5);

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];
int PrefixMu[maxn];

void Moblus() {
	for (int i = 0; i < maxn; ++i) IsPrime[i] = true;
	Mu[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (IsPrime[i]) {
			Prime[Tot++] = i;
			Mu[i] = -1;
		}
		for (int j = 0; j < Tot && Prime[j] * i < maxn; ++j) {
			IsPrime[i * Prime[j]] = false;
			if (i % Prime[j] == 0) {
				Mu[i * Prime[j]] = 0;
				break;
			}
			Mu[i * Prime[j]] = -Mu[i];
		}
	}
	for (int i = 1; i < maxn; ++i) PrefixMu[i] = PrefixMu[i - 1] + Mu[i];
}

int T;
int A, B, C, D, K;
int Ans;

int Solve(int N, int M) {
	if (N > M) swap(N, M);
	int Res = 0;
	for (int d = 1, tp; d <= N; d = tp + 1) {
		tp = min(N / (N / d), M / (M / d));
		Res += (PrefixMu[tp] - PrefixMu[d - 1]) * (N / d) * (M / d);
	}
	return Res;
}

int main(int argc, char *argv[]) {
	Moblus();
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d%d%d%d%d", &A, &B, &C, &D, &K);
		Ans = 0;
		Ans += Solve(B / K, D / K);
		Ans -= Solve((B / K), (C - 1) / K);
		Ans -= Solve((A - 1) / K, D / K);
		Ans += Solve((A - 1) / K, (C - 1) / K);
		printf("%d\n", Ans);
	}
	return 0;
}

