#include <bits/stdc++.h>
using namespace std;

bool IsPrime[110];
int Tot;
long long Prime[110];

void PrimeSieve() {
	for (int i = 2; i < 110; ++i) IsPrime[i] = true;
	for (int i = 2; i < 110; ++i) {
		if (IsPrime[i]) {
			Prime[Tot++] = i;
			for (int j = i * i; j < 110; j += i) IsPrime[j] = false;
		}
	}
}

int T;
long long A, B;

int main(int argc, char *argv[]) {
	PrimeSieve();
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%lld%lld", &A, &B);
		if (__gcd(A, B) == 1) printf("1\n%lld %lld\n", A, B);
		else {
			for (int i = 0; i < Tot; ++i) {
				if (__gcd(Prime[i], B - Prime[i]) == 1 && __gcd(A - Prime[i], Prime[i]) == 1) {
					printf("2\n%lld %lld\n%lld %lld\n", Prime[i], B - Prime[i], A - Prime[i], Prime[i]);
					break;
				}
			}
		}
	}
	return 0;
}

