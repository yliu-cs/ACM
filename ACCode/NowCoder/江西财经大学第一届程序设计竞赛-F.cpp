#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-8;

int Sgn(long double Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}

long double Cal(long double X, long double Y) {
    return 2018.0 * X * X * X * X + 21.0 * X + 5.0 * X * X * X + 5.0 * X * X + 14.0 - Y;
}

int T;
long double Y;
bool Flag;
long double Left, Right;
long double Mid;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%Lf", &Y);
        if (Cal(0.0, Y) * Cal(100.0, Y) > 0) {
            printf("-1\n");
            continue;
        }
        Flag = Sgn(Cal(0.0, Y) - Cal(100.0, Y)) > 0 ? true : false;
        Left = 0.0, Right = 100.0;
        while (Sgn(Right - Left) > 0) {
            Mid = (Left + Right) / 2.0;
            if (Cal(Mid, Y) > 0) {
                if (Flag) Left = Mid;
                else Right = Mid;
            }
            else {
                if (Flag) Right = Mid;
                else Left = Mid;
            }
        }
        printf("%.4Lf\n", Left);
    }
    return 0;
}

