#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(3e5 + 5);

long long N;
long long A[maxn];
long long Left, Right;
long long Ans;

int main(int argc, char *argv[]) {
	scanf("%lld", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	sort(A + 1, A + N + 1);
	Left = 1; Right = N;
	for (int i = 1; i <= N / 2; ++i) {
		Ans += (A[Left] + A[Right]) * (A[Left] + A[Right]);
		Left++; Right--;
	}
	printf("%lld\n", Ans);
	return 0;
}
