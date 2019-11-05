#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;

char Str[maxn], Convert[maxn];
int Cur;

double Read() {
	int Pos = 0;
	double Ans;
	while (isalnum(Str[Cur]) || Str[Cur] == '.' || Str[Cur] == '-') {
		Convert[Pos++] = Str[Cur++];
	}
	Convert[Pos] = '\0';
	sscanf(Convert, "%lf", &Ans);
	return Ans;
}

double Cal() {
	double P = 0.0, A = 0.0, B = 0.0;
	while (Str[Cur] == ' ') {
		Cur++;
	}
	if (Str[Cur] == '(') {
		Cur++;
		P = Read();
		A = Cal();
		B = Cal();
		if (Str[Cur] == ')') {
			Cur++;
			return (A + B) * P + (A - B) * (1.0 - P);
		}
	}
	else {
		return Read();
	}
}

int main(int argc, char *argv[]) {
	while (fgets(Str, maxn, stdin)) {
		if (Str[strlen(Str) - 1] == '\n') {
			Str[strlen(Str) - 1] = '\0';
		}
		if (!strcmp(Str, "()")) {
			break;
		}
		Cur = 0;
		printf("%.2lf\n", Cal());
	}
    return 0;
}