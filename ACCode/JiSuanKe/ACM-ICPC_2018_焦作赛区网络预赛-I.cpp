#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int A, B, C;
	while (~scanf("%d%d%d", &A, &B, &C)) {
		if ((A * B * C) % 2) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
