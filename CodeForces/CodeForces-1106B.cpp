#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e5 + 5);

int N, M;
long long A[maxn];
long long C[maxn];
vector<pair<long long, int> > F;
int Pos;
int Cnt;
long long Ans;

int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &C[i]);
		F.push_back(make_pair(C[i], i));
	}
	sort(F.begin(), F.end());
	for (long long i = 1, T, D; i <= M; ++i) {
		scanf("%lld%lld", &T, &D);
		Ans = 0;
		if (A[T] >= D) {
			printf("%lld\n", C[T] * D);
			A[T] -= D;
			continue;
		}
		else if (A[T] > 0) {
			Ans += C[T] * A[T];
			D -= A[T];
			A[T] = 0;
		}
		for (int i = Pos; i < (int)F.size(); ++i) {
			if (A[F[i].second] == 0) continue;
			Pos = i;
			if (A[F[i].second] >= D) {
				A[F[i].second] -= D;
				Ans += C[F[i].second] * D;
				D = 0;
				break;
			}
			else {
				D -= A[F[i].second];
				Ans += A[F[i].second] * C[F[i].second];
				A[F[i].second] = 0;
			}
		}
		if (D != 0) Ans = 0;
		printf("%lld\n", Ans);
	}
	return 0;
}
