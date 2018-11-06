#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;
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

	double operator ^ (const Segment &B) const {
		return (T - S) ^ (B.T - B.S);
	}
};

int N;
Point Treasure;
int Ans;
Segment segments[maxn];

bool IsIntersect(Segment A, Segment B) {
	return 
		max(A.S.X, A.T.X) >= min(B.S.X, B.T.X) &&
		max(B.S.X, B.T.X) >= min(A.S.X, A.T.X) &&
		max(A.S.Y, A.T.Y) >= min(B.S.Y, B.T.Y) &&
		max(B.S.Y, B.T.Y) >= min(A.S.Y, A.T.Y) &&
		(A ^ Segment {A.S, B.S}) * (A ^ Segment {A.S, B.T}) <= 0 &&
		(B ^ Segment {B.S, A.S}) * (B ^ Segment {B.S, A.T}) <= 0;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		segments[i].Input();
	}
	Treasure.Input();
	Ans = INF;
	if (!N) {
		Ans = 1;
	}
	else {
		for (int i = 1; i <= N; ++i) {
			int Cnt = 0;
			for (int j = 1; j <= N; ++j) {
				if (IsIntersect(Segment {Treasure, segments[i].S}, segments[j])) {
					Cnt++;
				}
			}
			Ans = min(Ans, Cnt);
			Cnt = 0;
			for (int j = 1; j <= N; ++j) {
				if (IsIntersect(Segment {Treasure, segments[i].T}, segments[j])) {
					Cnt++;
				}
			}
			Ans = min(Ans, Cnt);
		}
	}
	printf("Number of doors = %d\n", Ans);
	return 0;
}

