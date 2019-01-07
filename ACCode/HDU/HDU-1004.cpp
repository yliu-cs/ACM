#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
	int N;
	while (cin >> N && N) {
		map<string, int> Cnt;
		string Ans, Str;
		int AnsCnt = 0;
		for (int i = 0; i < N; ++i) {
			cin >> Str;
			Cnt[Str]++;
			if (Cnt[Str] > AnsCnt) {
				Ans = Str;
				AnsCnt = Cnt[Str];
			}
		}
		cout << Ans << endl;
	}
    return 0;
}
