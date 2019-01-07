#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	long long T;
	scanf("%lld", &T);
	for (long long Case = 1, N, K; Case <= T; ++Case) {
		scanf("%lld%lld", &N, &K);
		long long Sum = 0;
		vector<long long> A(N);
		for (long long i = 0; i < N; ++i) {
			scanf("%lld", &A[i]);
			Sum += A[i];
		}
		printf("Case #%lld: ", Case);
		long long Average = Sum / K;
		if (Average * K != Sum) {
			printf("%lld\n", -1 * 1LL);
			continue;
		}
		long long Ans = 0;
		for (long long i = 0; i < N; ++i) {
			if (A[i] == Average || !A[i]) {
				continue;
			}
			while (A[i] >= Average) {
				if (A[i] != Average) {
					Ans++;
				}
				A[i] -= Average;
			}
			if (A[i]) {
				A[i + 1] += A[i];
				A[i] = 0;
				Ans++;
			}
		}
		printf("%lld\n", Ans);
	}
    return 0;
}
