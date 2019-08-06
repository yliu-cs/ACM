#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const double INF = 1e20;
const int maxn = 1e4 + 5;

struct Point {
	double X, Y;

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

	double operator ^ (const Segment &B) const {
		return (T - S) ^ (B.T - B.S);
	}
};

struct Edge {
	int V;
	double Weight;
	int Next;
};

Edge edges[maxn << 2];
int Head[maxn];
int Tot;
int N;
double X, Y1, Y2, Y3, Y4;
Point points[maxn << 2];
double Dis[maxn];

void Init() {
	Tot = 0;
	memset(Head, -1, sizeof(Head));
}

void AddEdge(int U, int V, double Weight) {
	edges[Tot] = Edge {V, Weight, Head[U]};
	Head[U] = Tot++;
	edges[Tot] = Edge {U, Weight, Head[V]};
	Head[V] = Tot++;
}

double Distance(Point A, Point B) {
	return sqrt((B - A) * (B - A));
}

bool IsIntersect(Segment A, Segment B) {
	return 
		(A ^ Segment {A.S, B.S}) * (A ^ Segment {A.S, B.T}) <= 0 &&
		(B ^ Segment {B.S, A.S}) * (B ^ Segment {B.S, A.T}) <= 0;
}

struct Cmp {
	bool operator () (const int &A, const int &B) {
		return Dis[A] > Dis[B];
	}
};

void Dijkstra(int Start) {
	priority_queue<int, vector<int>, Cmp> Que;
	for (int i = 0; i <= 4 * N + 1; ++i) {
		Dis[i] = INF;
	}
	Dis[Start] = 0;
	Que.push(Start);
	while (!Que.empty()) {
		int Cur = Que.top(); Que.pop();
		for (int i = Head[Cur]; ~i; i = edges[i].Next) {
			if (Dis[edges[i].V] > Dis[Cur] + edges[i].Weight) {
				Dis[edges[i].V] = Dis[Cur] + edges[i].Weight;
				Que.push(edges[i].V);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", &N) && ~N) {
		Init();

		points[0] = Point {0, 5};
		for (int i = 1; i <= N; ++i) {
			scanf("%lf%lf%lf%lf%lf", &X, &Y1, &Y2, &Y3, &Y4);
			points[i * 4 - 3] = Point {X, Y1};
			points[i * 4 - 2] = Point {X, Y2};
			points[i * 4 - 1] = Point {X, Y3};
			points[i * 4] = Point {X, Y4};
		}
		points[4 * N + 1] = Point {10, 5};

		for (int i = 1; i <= 4 * N; ++i) {
			bool Flag = true;
			Segment Judge = Segment {points[0], points[i]};
			for (int j = 4; j < i; j += 4) {
				double CurX = points[j].X;
				if (IsIntersect(Judge, Segment {Point {CurX, 0}, points[j - 3]}) ||
					IsIntersect(Judge, Segment {points[j - 2], points[j - 1]}) ||
					IsIntersect(Judge, Segment {points[j], Point {CurX, 10}})) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				AddEdge(0, i, Distance(points[0], points[i]));
			}

			Flag = true;
			Judge = Segment {points[i], points[4 * N + 1]};
			for (int j = 4 * N; j - 3 > i; j -= 4) {
				double CurX = points[j].X;
				if (IsIntersect(Judge, Segment {Point {CurX, 0}, points[j - 3]}) ||
					IsIntersect(Judge, Segment {points[j - 2], points[j - 1]}) ||
					IsIntersect(Judge, Segment {points[j], Point {CurX, 10}})) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				AddEdge(i, 4 * N + 1, Distance(points[i], points[4 * N + 1]));
			}
		}

		for (int i = 1; i <= 4 * N; ++i) {
			for (int l = 4 * N; l - 3 > i; l -= 4) {
				for (int j = l; j >= l - 3; --j) {
					bool Flag = true;
					Segment Judge = Segment {points[i], points[j]};
					for (int k = l - 4; k - 3 > i; k -= 4) {
						double CurX = points[k].X;
						if (IsIntersect(Judge, Segment {Point {CurX, 0}, points[k - 3]}) ||
							IsIntersect(Judge, Segment {points[k - 2], points[k - 1]}) ||
							IsIntersect(Judge, Segment {points[k], Point {CurX, 10}})) {
							Flag = false;
							break;
						}
					}
					if (Flag) {
						AddEdge(i, j, Distance(points[i], points[j]));
					}
				}
			}
		}

		bool Flag = true;
		Segment Judge = Segment {points[0], points[4 * N + 1]};
		for (int j = 4; j <= 4 * N; j += 4) {
			double CurX = points[j].X;
			if (IsIntersect(Judge, Segment {Point {CurX, 0}, points[j - 3]}) ||
				IsIntersect(Judge, Segment {points[j - 2], points[j - 1]}) ||
				IsIntersect(Judge, Segment {points[j], Point {CurX, 10}})) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			AddEdge(0, 4 * N + 1, Distance(points[0], points[4 * N + 1]));
		}

		Dijkstra(0);
		printf("%.2f\n", Dis[4 * N + 1]);
	}
	return 0;
}

