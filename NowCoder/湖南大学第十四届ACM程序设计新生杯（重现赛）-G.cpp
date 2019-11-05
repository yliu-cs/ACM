#include <bits/stdc++.h>
using namespace std;

int t;
long double a, b, c, d;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
        printf("%.0Lf\n", floor(a + b + c + d));
    }
    return 0;
}
