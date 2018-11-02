#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1e1 + 5;
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

bool Parallel(Segment A, Segment B) {
	return fabs((A.T - A.S) ^ (B.T - B.S)) <= eps;
}

bool IsIntersect(Segment A, Segment B) {
	return fabs((A ^ Segment {A.S, B.S}) * (A ^ Segment {A.S, B.T})) <= eps && fabs((B ^ Segment {B.S, A.S}) * (B ^ Segment {B.S, A.T})) <= eps;
}

Point IntersectionPoint(Segment A, Segment B) {
	double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
	return Point {(A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X)};
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	printf("INTERSECTING LINES OUTPUT\n");
	for (int i = 0; i < N; ++i) {
		Segment A, B;
		A.Input();
		B.Input();
		if (Parallel(A, B)) {
			if (IsIntersect(A, B)) {
				printf("LINE\n");
			}
			else {
				printf("NONE\n");
			}
		}
		else {
			Point P = IntersectionPoint(A, B);
			printf("POINT %.2f %.2f\n", P.X, P.Y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}

