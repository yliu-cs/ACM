#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e7 + 5);

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];
long long F[maxn];
long long Prefix[maxn];

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
	for (int i = 0; i < Tot; ++i) {
		for (int j = 1; Prime[i] * j < maxn; ++j) {
			F[j * Prime[i]] += Mu[j];
		}
	}
	for (int i = 1; i < maxn; ++i) Prefix[i] = Prefix[i - 1] + F[i];
}

long long Solve(int N, int M) {
	if (N > M) swap(N, M);
	long long Res = 0;
	for (int t = 1, tp; t <= N; t = tp + 1) {
		tp = min(N / (N / t), M / (M / t));
		Res += (Prefix[tp] - Prefix[t - 1]) * (N / t) * (M / t);
	}
	return Res;
}

int T;
int N, M;

int main(int argc, char *argv[]) {
	Moblus();
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d%d", &N, &M);
		printf("%lld\n", Solve(N, M));
	}
	return 0;
}

