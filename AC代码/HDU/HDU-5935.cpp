#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	for (int Case = 1, N; Case <= T; ++Case) {
		scanf("%d", &N);
		vector<int> Pos(N + 1, 0);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &Pos[i]);
		}
		long long Ans = 0;
		double Speed = (Pos[N] - Pos[N - 1]) * 1.0;
		for (int i = N; i > 0; --i) {
			double Length = (Pos[i] - Pos[i - 1]) * 1.0;
			int Time = Length / Speed;
			Ans += Time;
			if (Length / Time != Speed) {
				Ans++;
				Speed = Length / (Time + 1);
			}
		}
		printf("Case #%d: %lld\n", Case, Ans);
	}
    return 0;
}
