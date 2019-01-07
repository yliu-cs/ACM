#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		string Str;
		cin >> Str;
		for (int i = 0; i < int(Str.length()); ++i) {
			Str[i] = tolower(Str[i]);
		}
		if (Str == "jessie") {
			printf("Good guy!\n");
		}
		else {
			printf("Dare you say that again?\n");
		}
	}
	return 0;
}
