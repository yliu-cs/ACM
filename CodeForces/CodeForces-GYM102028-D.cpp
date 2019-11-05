#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

int T;
double A, B, R, D;
double Tan;
double Sin, Cos;
double Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lf%lf%lf%lf", &A, &B, &R, &D);
        Tan = B / (A + R);
        if (Tan < tan(D * pi / 180) || (Tan > 0 && tan(D * pi / 180) < 0)) {
            Sin = B / sqrt(B * B + (A + R) * (A + R));
            Cos = (A + R) / sqrt(B * B + (A + R) * (A + R));
        }
        else {
            Sin = sin(D * pi / 180);
            Cos = cos(D * pi / 180);
        }
        Ans = A * Cos + B * Sin + R * Cos - R;
        printf("%.12lf\n", Ans);
    }
    return 0;
}

