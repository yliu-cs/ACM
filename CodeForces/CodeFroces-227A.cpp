#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point {
    double X, Y;

    void Input() {
        scanf("%lf%lf", &X, &Y);
    }

    Point operator + (Point B) {
        return (Point){X + B.X, Y + B.Y};
    }

    Point operator - (Point B) {
        return (Point){X - B.X, Y - B.Y};
    }

    double operator * (Point B) {
        return X * B.X + Y * B.Y;
    }

    double operator ^ (Point B) {
        return X * B.Y - Y * B.X;
    }
};

struct Line {
    Point S, T;

    double operator ^ (Line B) {
        return (T - S) ^ (B.T - B.S);
    }
};

int main(int argc, char *argv[]) {
    Point A, B, C;
    A.Input(); B.Input(); C.Input();
    double Judge = (Line){A, B} ^ (Line){B, C};
    if (fabs(Judge - 0.0) < eps) {
        printf("TOWARDS\n");
    }
    else if (Judge > 0.0) {
        printf("LEFT\n");
    }
    else if (Judge < 0.0) {
        printf("RIGHT\n");
    }
    return 0;
}

