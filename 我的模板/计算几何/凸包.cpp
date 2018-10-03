#include <bits/stdc++.h>

// 点
struct Point {
    // X:横坐标，Y:纵坐标
    double X, Y;
    Point(double _X = 0, double _Y = 0): X(_X), Y(_Y) {}
    void input() {
        scanf("%lf%lf", &X, &Y);
    }
    void output() {
        printf("%lf%lf", X, Y);
    }
    // 坐标减法
    Point operator - (const Point &B) const {
        return Point (X - B.X, Y - B.Y);
    }
    // 向量叉乘
    double operator ^ (const Point &B) const {
        return X * B.Y - Y * B.X;
    }
};

// 两点间距离
double Distance(Point A, Point B) {
    return hypot(A.X - B.X, A.Y - B.Y);
}

// 凸包，points:所有点，返回凸包总长度
double ConvexHull(std::vector<Point> points) {
    int N = int(points.size());
    // 特判点数小于等于2的情况
    if (N == 1) {
        return 0;
    }
    else if (N == 2) {
        return Distance(points[0], points[1]);
    }
    // 查找最左下角的基准点
    int Basic = 0;
    for (int i = 0; i < N; ++i) {
        if (points[i].Y > points[Basic].Y || 
            (points[i].Y == points[Basic].Y && points[i].X < points[Basic].X)) {
                Basic = i;
        }
    }
    std::swap(points[0], points[Basic]);
    // 对其它点进行极角排序
    std::sort(points.begin() + 1, points.end(), [&] (const Point &A, const Point &B) {
        double Temp = (A - points[0]) ^ (B - points[0]);
        if (Temp > 0) {
            return true;
        }
        else if (!Temp && Distance(A, points[0]) < Distance(A, points[0])) {
            return true;
        }
        return false;
    });
    // 凸包选点
    std::vector<Point> Stack;
    Stack.push_back(points[0]);
    for (int i = 2; i < N; ++i) {
        while (Stack.size() >= 2 && ((Stack.back() - Stack[int(Stack.size()) - 2]) ^ (points[i] - Stack[int(Stack.size()) - 2])) <= 0) {
            Stack.pop_back();
        }
    }
    Stack.push_back(points[0]);
    // 计算总长
    double Ans = 0;
    for (int i = 1; i < int(Stack.size()); ++i) {
        Ans += Distance(Stack[i], Stack[i - 1]);
    }
    // 返回结果
    return Ans;
}
