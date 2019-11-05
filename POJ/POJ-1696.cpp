#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e2 + 5;

struct Point {
	int Index;
	double X, Y;

	Point operator - (const Point &B) const {
		return Point {0, X - B.X, Y - B.Y};
	}

	double operator * (const Point &B) const {
		return X * B.X + Y * B.Y;
	}

	double operator ^ (const Point &B) const {
		return X * B.Y - Y * B.X;
	}
};

int T;
int N;
int Basic;
Point points[maxn];

double Distance(Point A, Point B) {
	return sqrt((B - A) * (B - A));
}

bool cmp(Point A, Point B) {
	double Temp = (A - points[Basic]) ^ (B - points[Basic]);
	return Temp > 0 || (!Temp && Distance(A, points[Basic]) < Distance(B, points[Basic]));
}

int main(int argc, char *argv[]) {
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d%lf%lf", &points[i].Index, &points[i].X, &points[i].Y);
			if (i > 1) {
				if (points[i].Y < points[1].Y || (points[i].Y == points[1].Y && points[i].X < points[1].X)) {
					swap(points[1], points[i]);
				}
			}
		}
		for (int i = 1; i <= N; ++i) {
			Basic = i;
			sort(points + i + 1, points + N + 1, cmp);
		}
		printf("%d", N);
		for (int i = 1; i <= N; ++i) {
			printf(" %d", points[i].Index);
		}
		printf("\n");
	}
	return 0;
}

