#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;
const double pi = acos(-1.0);

double Ans;
int N;
double R[maxn];

int main(int argc, char *argv[]) {
    Ans = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lf", &R[i]);
    }
    sort(R + 1, R + N + 1);
    reverse(R + 1, R + N + 1);
    for (int i = 1; i <= N; ++i) {
        if (i & 1) {
            Ans += pi * R[i] * R[i];
        }
        else {
            Ans -= pi * R[i] * R[i];
        }
    }
    printf("%.10lf\n", Ans);
    return 0;
}

