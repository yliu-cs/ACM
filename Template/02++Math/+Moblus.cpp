#include <bits/stdc++.h>

const int maxn = "Edit";

bool IsPrime[maxn];
int Tot;
int Prime[maxn];
int Mu[maxn];

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
}

