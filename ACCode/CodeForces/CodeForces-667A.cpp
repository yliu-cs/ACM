#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

double D, H, V, E;
double DrinkSpeed;

int main(int argc, char *argv[]) {
    scanf("%lf%lf%lf%lf", &D, &H, &V, &E);
    DrinkSpeed = V / (pi * (D / 2) * (D / 2));
    if (DrinkSpeed < E) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        printf("%.12lf\n", H / (DrinkSpeed - E));
    }
    return 0;
}

