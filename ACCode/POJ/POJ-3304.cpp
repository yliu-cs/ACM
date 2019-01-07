#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 1e2 + 5;
const double eps = 1e-8;

// 点
struct Point {
	double X, Y;
	void Input() {
		scanf("%lf%lf", &X, &Y);
	}
	// 坐标相减
	Point operator - (const Point &B) {
		return Point {X - B.X, Y - B.Y};
	}
	// 点乘
	double operator * (const Point &B) {
		return X * B.X + Y * B.Y;
	}
	// 叉乘
	double operator ^ (const Point &B) {
		return X * B.Y - Y * B.X;
	}
};

// 线段
struct Segment {
	// 端点S、T
	Point S, T;
	void Input() {
		S.Input();
		T.Input();
	}
};

int T;
int N;
bool Flag;
Segment segments[maxn];

bool Check(Segment X) {
	// 去除重合的点
	if (hypot(X.S.X - X.T.X, X.S.Y - X.T.Y) <= eps) {
		return false;
	}
	for (int i = 0; i < N; ++i) {
		// 判断线段X所在直线是否与所有线段都相交
		if (((X.S - segments[i].S) ^ (X.T - segments[i].S)) * ((X.S - segments[i].T) ^ (X.T - segments[i].T)) > eps) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			segments[i].Input();
		}
		Flag = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				// 检验是否有两个断电所在直线可以与所有线段相交
				if (Check(Segment {segments[i].S, segments[j].S}) || Check(Segment {segments[i].S, segments[j].T}) || Check(Segment {segments[i].T, segments[j].S}) || Check(Segment {segments[i].T, segments[j].T})) {
					Flag = true;
					break;
				}
			}
			if (Flag) {
				break;
			}
		}
		if (Flag) {
			printf("Yes!\n");
		}
		else {
			printf("No!\n");
		}
	}
	return 0;
}

