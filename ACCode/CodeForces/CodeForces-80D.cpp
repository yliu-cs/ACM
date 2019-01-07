#include<bits/stdc++.h>
using namespace std;

double H, M;

int main(int argc, char *argv[]) {
    scanf("%lf:%lf", &H, &M);
    if (H >= 12) {
        H -= 12;
    }
    printf("%lf %lf\n", 360 * (H / 12) + 30 * (M / 60), 360 * (M / 60));
    return 0;
}

