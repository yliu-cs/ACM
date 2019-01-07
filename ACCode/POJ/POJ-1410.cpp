#include <iostream>
#include <cstdio>
using namespace std;

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

int T;
bool Flag;
double XStart, YStart, XEnd, YEnd, XLeft, YTop, XRight, YBottom;

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
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		Flag = false;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &XStart, &YStart, &XEnd, &YEnd, &XLeft, &YTop, &XRight, &YBottom);
		if (XLeft > XRight) {
			swap(XLeft, XRight);
		}
		if (YBottom > YTop) {
			swap(YTop, YBottom);
		}
		Segment Judge = Segment {Point {XStart, YStart}, Point {XEnd, YEnd}};
		Segment Left = Segment {Point {XLeft, YBottom}, Point {XLeft, YTop}}, Right = Segment {Point {XRight, YBottom}, Point{XRight, YTop}};
		Segment Top = Segment {Point {XLeft, YTop}, Point {XRight, YTop}}, Bottom = Segment {Point {XLeft, YBottom}, Point {XRight, YBottom}};
		if (IsIntersect(Left, Judge) || IsIntersect(Right, Judge) || IsIntersect(Top, Judge) || IsIntersect(Bottom, Judge)) {
			Flag = true;
		}
		if (!Flag) {
			if (XStart >= XLeft && XStart <= XRight && YStart >= YBottom && YStart <= YTop) {
				Flag = true;
			}
		}
		if (Flag) {
			printf("T\n");
		}
		else {
			printf("F\n");
		}
	}
	return 0;
}

