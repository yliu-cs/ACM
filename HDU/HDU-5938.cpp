#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e1 + 5;

int T;
char Str[maxn];

long long GetNum(int LeftIndex, int RightIndex) {
	long long Ans = 0;
	for (int i = LeftIndex; i <= RightIndex; ++i) {
		Ans = Ans * 10 + (Str[i] - '0');
	}
	return Ans;
}

int main(int argc, char *argv[]) {
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%s", Str);
		int Len = strlen(Str);
		long long Ans;
		Ans = max(GetNum(0, 0) + GetNum(1, Len - 4) - GetNum(Len - 3, Len - 3) * GetNum(Len - 2, Len - 2) / GetNum(Len - 1, Len - 1), 
			GetNum(0, Len - 5) + GetNum(Len - 4, Len - 4) - GetNum(Len - 3, Len - 3) * GetNum(Len - 2, Len - 2) / GetNum(Len - 1, Len - 1));
		if (Len > 5) {
			Ans = max(Ans, GetNum(0, 0) + GetNum(1, Len - 5) - GetNum(Len - 4, Len - 4) * GetNum(Len - 3, Len - 3) / GetNum(Len - 2, Len - 1));
			Ans = max(Ans, GetNum(0, Len - 6) + GetNum(Len - 5, Len - 5) - GetNum(Len - 4, Len - 4) * GetNum(Len - 3, Len - 3) / GetNum(Len - 2, Len - 1));
		}
		printf("Case #%d: %lld\n", Case, Ans);
	}
    return 0;
}
