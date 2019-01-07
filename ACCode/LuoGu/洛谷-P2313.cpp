#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2 + 5;

struct Point {
	double X, Y;
	void Input() {
		scanf("%lf%lf", &X, &Y);
	}
};

struct Rectangle {
	double X1, Y1, X2, Y2;
	void Input() {
		double TempX1, TempY1, TempX2, TempY2;
		scanf("%lf%lf%lf%lf", &TempX1, &TempY1, &TempX2, &TempY2);
		X1 = min(TempX1, TempX2);
		Y1 = max(TempY1, TempY2);
		X2 = max(TempX1, TempX2);
		Y2 = min(TempY1, TempY2);
	}
	bool Judge(Point P) {
		return P.X > X1 && P.X < X2 && P.Y > Y2 && P.Y < Y1;
	}
};

struct Circle {
	double X, Y, R;
	void Input() {
		scanf("%lf%lf%lf", &X, &Y, &R);
	}
	bool Judge(Point P) {
		return hypot(fabs(P.X - X), fabs(P.Y - Y)) < R;
	}
};

int N, M;
Rectangle rectangles[maxn];
Circle circles[maxn];
int RCnt, CCnt;
Point points[maxn];
int Answer[maxn];

int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	RCnt = 0, CCnt = 0;
	for (int i = 0; i < N; ++i) {
		char Graph;
		cin >> Graph;
		if (Graph == 'r') {
			rectangles[RCnt++].Input();
		}
		else {
			circles[CCnt++].Input();
		}
	}
	for (int i = 0; i < M; ++i) {
		points[i].Input();
	}
	memset(Answer, 0, sizeof(Answer));
	for (int i = 0; i < RCnt; ++i) {
		for (int j = 0; j < M; ++j) {
			if (rectangles[i].Judge(points[j])) {
				Answer[j]++;
			}
		}
	}
	for (int i = 0; i < CCnt; ++i) {
		for (int j = 0; j < M; ++j) {
			if (circles[i].Judge(points[j])) {
				Answer[j]++;
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		printf("%d\n", Answer[i]);
	}
    return 0;
}
