#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
const double eps = 1e-8;

struct Point {
	double X, Y;

	void Input() {
		scanf("%lf%lf", &X, &Y);
	}

	Point operator - (const Point &B) const {
		return Point {X - B.X, Y - B.Y};
	}

	double operator * (const Point &B) const {
		return X * B.X + Y * B.Y;
	}

	double operator ^ (const Point &B) const {
		return X * B.Y - Y * B.X;
	}
};

struct Segment {
	Point S, T;

	void Input() {
		S.Input();
		T.Input();
	}

	double operator ^ (const Segment B) const {
		return (T - S) ^ (B.T - B.S);
	}

	bool operator < (const Segment B) const {
		return S.X < B.S.X;
	}
};

int N;
int Cnt;
Segment segments[maxn];
bool Flag[maxn];

bool IsIntersect(Segment A, Segment B) {
	return (A ^ Segment {A.S, B.S}) * (A ^ Segment {A.S, B.T}) <= 0 && (B ^ Segment {B.S, A.S}) * (B ^ Segment {B.S, A.T}) <= 0;
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", &N) && N) {
		for (int i = 1; i <= N; ++i) {
			segments[i].Input();
		}
		Cnt = 0;
		memset(Flag, true, sizeof(Flag));
		for (int i = 1; i <= N; ++i) {
			for (int j = i + 1; j <= N; ++j) {
				if (IsIntersect(segments[i], segments[j])) {
					Flag[i] = false;
					break;
				}
			}
			if (Flag[i]) {
				Cnt++;
			}
		}
		printf("Top sticks:");
		for (int i = 1; i <= N; ++i) {
			if (Flag[i]) {
				printf(" %d", i);
				Cnt--;
				if (Cnt) {
					printf(",");
				}
				else {
					printf(".");
				}
			}
		}
		printf("\n");
	}
	return 0;
}

