#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 5e3 + 5;

struct Point {
	double X, Y;
	void Input() {
		scanf("%lf%lf", &X, &Y);
	}
	Point operator - (const Point &B) const {
		return Point {X - B.X, Y - B.Y};
	}
	double operator ^ (const Point &B) const {
		return X * B.Y - Y * B.X;
	}
};

struct Line {
	Point S, T;
};

int N, M;
double X1, Y1, X2, Y2;
Line lines[maxn];
int Cnt[maxn];
int Ans[maxn];

bool Cmp(Line A, Line B) {
	return A.S.X < B.S.X;
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", &N) && N) {
		scanf("%d%lf%lf%lf%lf", &M, &X1, &Y1, &X2, &Y2);
		for (int i = 0; i < N; ++i) {
			double U, L;
			scanf("%lf%lf", &U, &L);
			lines[i] = Line {Point {U, Y1}, Point {L, Y2}};
		}
		lines[N] = Line {Point {X2, Y1}, Point {X2, Y2}};
		sort(lines, lines + N + 1, Cmp);
		memset(Cnt, 0, sizeof(Cnt));
		for (int i = 0; i < M; ++i) {
			double X, Y;
			scanf("%lf%lf", &X, &Y);
			Point P = Point {X, Y};
			int Left = 0, Right = N;
			int Temp;
			while (Left <= Right) {
				int Mid = (Left + Right) >> 1;
				if (((lines[Mid].S - P) ^ (lines[Mid].T - P)) < 0) {
					Temp = Mid;
					Right = Mid - 1;
				}
				else {
					Left = Mid + 1;
				}
			}
			Cnt[Temp]++;
		}
		memset(Ans, 0, sizeof(Ans));
		for (int i = 0; i <= N; ++i) {
			if (Cnt[i] > 0) {
				Ans[Cnt[i]]++;
			}
		}
		printf("Box\n");
		for (int i = 1; i <= N; ++i) {
			if (Ans[i]) {
				printf("%d: %d\n", i, Ans[i]);
			}
		}
	}
    return 0;
}

