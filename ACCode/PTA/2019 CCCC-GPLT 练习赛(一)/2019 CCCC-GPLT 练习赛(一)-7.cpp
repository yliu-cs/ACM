#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    double ans = 0;
    for (int i = 0; i < 5; ++i) {
        double x; scanf("%lf", &x);
        if (i > 0 && i < 4) ans += x;
    }
    printf("%.2lf\n", ans / 3.0);
    return 0;
}

