#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double INF = 1e20;
const int maxn = 1e2 + 5;
const double eps = 1e-8;

struct Point {
    double X, Y;

    Point() {}
    Point(double _X, double _Y) {
        X = _X;
        Y = _Y;
    }

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point(X - B.X, Y - B.Y);
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

    Segment() {}
    Segment(Point _S, Point _T) {
        S = _S;
        T = _T;
    }

    double operator ^ (const Segment &B) const {
        return (T - S) ^ (B.T - B.S);
    }
};

int N;
bool Flag;
double Ans;
Point TopPoint[maxn], BottomPoint[maxn];

// 返回X正负性
int Sgn(double X) {
    if (fabs(X) < eps) {
        return 0;
    }
    if (X < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

// 判断线段A所在直线是否与线段B相交
bool IsIntersect(Segment A, Segment B) {
    return Sgn((B.S - A.T) ^ (A.S - A.T)) * Sgn((B.T - A.T) ^ (A.S - A.T)) <= 0;
}


// 直线交点
Point IntersectionPoint(Segment A, Segment B) {
    double X = (B.T - B.S) ^ (A.S - B.S), Y = (B.T - B.S) ^ (A.T - B.S);
    return Point((A.S.X * Y - A.T.X * X) / (Y - X), (A.S.Y * Y - A.T.Y * X) / (Y - X));
}

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N) {
        // 读入数据
        for (int i = 1; i <= N; ++i) {
            // 上顶点
            TopPoint[i].Input();
            // 下顶点
            BottomPoint[i] = Point(TopPoint[i].X, TopPoint[i].Y - 1.0);
        }
        // 穿过所有折角标记变量
        Flag = false;
        Ans = -INF;
        // 枚举直线<i,j>
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1, k; j <= N; ++j) {
                // 枚举折角k判断<i(up),j(down)>直线是否能够穿过所有折角
                for (k = 1; k <= N; ++k) {
                    if (!IsIntersect(Segment(TopPoint[i], BottomPoint[j]), Segment(TopPoint[k], BottomPoint[k]))) {
                        break;
                    }
                }
                // 若<i(up),j(down)>直线可以穿过所有折角则标记跳出
                if (k > N) {
                    Flag = true;
                    break;
                }
                // 若被挡折角在i、j点右侧则光线长度有效,求被挡位置
                if (k > max(i, j)) {
                    if (IsIntersect(Segment(TopPoint[i], BottomPoint[j]), Segment(TopPoint[k - 1], TopPoint[k]))) {
                        Point CrossPoint = IntersectionPoint(Segment(TopPoint[i], BottomPoint[j]), Segment(TopPoint[k - 1], TopPoint[k]));
                        Ans = max(Ans, CrossPoint.X);
                    }
                    if (IsIntersect(Segment(TopPoint[i], BottomPoint[j]), Segment(BottomPoint[k - 1], BottomPoint[k]))) {
                        Point CrossPoint = IntersectionPoint(Segment(TopPoint[i], BottomPoint[j]), Segment(BottomPoint[k - 1], BottomPoint[k]));
                        Ans = max(Ans, CrossPoint.X);
                    }
                }

                // 枚举折角k判断<i(down),j(up)>直线是否能够穿过所有折角
                for (k = 1; k <= N; ++k) {
                    if (!IsIntersect(Segment(BottomPoint[i], TopPoint[j]), Segment(TopPoint[k], BottomPoint[k]))) {
                        break;
                    }
                }
                // 若<i(down),j(up)>直线可以穿过所有折角则标记跳出
                if (k > N) {
                    Flag = true;
                    break;
                }
                // 若被挡折角在i、j点右侧则光线长度有效,求被挡位置
                if (k > max(i, j)) {
                    if (IsIntersect(Segment(BottomPoint[i], TopPoint[j]), Segment(TopPoint[k - 1], TopPoint[k]))) {
                        Point CrossPoint = IntersectionPoint(Segment(BottomPoint[i], TopPoint[j]), Segment(TopPoint[k - 1], TopPoint[k]));
                        Ans = max(Ans, CrossPoint.X);
                    }
                    if (IsIntersect(Segment(BottomPoint[i], TopPoint[j]), Segment(BottomPoint[k - 1], BottomPoint[k]))) {
                        Point CrossPoint = IntersectionPoint(Segment(BottomPoint[i], TopPoint[j]), Segment(BottomPoint[k - 1], BottomPoint[k]));
                        Ans = max(Ans, CrossPoint.X);
                    }
                }
            }
            if (Flag) {
                break;
            }
        }
        if (Flag) {
            printf("Through all the pipe.\n");
        }
        else {
            printf("%.2lf\n", Ans);
        }
    }
	return 0;
}

