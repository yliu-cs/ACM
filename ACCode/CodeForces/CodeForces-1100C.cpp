#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

int N;
double R;
double Angle;
double Ans;

int main(int argc, char *argv[]) {
    scanf("%d%lf", &N, &R);
    Angle = pi / (double)N;
    Ans = R * sin(Angle) / (1 - sin(Angle));
    printf("%.7lf\n", Ans);
    return 0;
}
