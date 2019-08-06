#include<bits/stdc++.h>
using namespace std;

struct Point {
    double X, Y;

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    void Output() {
        printf("%.0lf %.0lf\n", X, Y);
    }

    Point operator - (const Point &B) const {
        return Point {X - B.X, Y - B.Y};
    }

    Point operator + (const Point &B) const {
        return Point {X + B.X, Y + B.Y};
    }
};

Point points[3];
Point Ans;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) {
        points[i].Input();
    }
    printf("3\n");
    for (int i = 0; i < 3; ++i) {
        Ans = points[(i + 2) % 3] + (points[i % 3] - points[(i + 1) % 3]);
        Ans.Output();
    }
    return 0;
}

