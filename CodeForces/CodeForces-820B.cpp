#include<bits/stdc++.h>
using namespace std;

int N;
double A;
double Angle;
double Block;
double Difference;
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%lf", &N, &A);
    Angle = 180.0 - 360.0 / (double)N;
    Block = Angle / ((double)N - 2.0);
    Difference = abs(Angle - A);
    Ans = 3;
    for (int i = 4; i <= N; ++i) {
        Angle -= Block;
        if (abs(Angle - A) < Difference) {
            Ans = i;
            Difference = abs(Angle - A);
        }
    }
    printf("1 2 %d\n", Ans);
    return 0;
}

