#include<bits/stdc++.h>
using namespace std;

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

struct Line {
    Point S, T;

    void Input() {
        S.Input();
        T.Input();
    }

    double operator ^ (const Line &B) const {
        return (T - S) ^ (B.T - B.S);
    }
};

double N, D;
int M;
Point Left, Right, Top, Bottom;
Point Judge;
bool Flag;

int main(int argc, char *argv[]) {
    scanf("%lf%lf", &N, &D);
    Left = Point {0.0, D};
    Right = Point {N, N - D};
    Top = Point {N - D, N};
    Bottom = Point {D, 0.0};
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        Judge.Input();
        Flag = true;
        if ((Line {Left, Top} ^ Line {Left, Judge}) * (Line {Bottom, Right} ^ Line {Bottom, Judge}) > 0) {
            Flag = false;
        }
        if ((Line {Bottom, Left} ^ Line {Bottom, Judge}) * (Line {Right, Top} ^ Line {Right, Judge}) > 0) {
            Flag = false;
        }
        if (Flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

