#include<bits/stdc++.h>
using namespace std;

int N, H;

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &H);
    for (int i = 1; i < N; ++i) {
        printf("%.12lf ", sqrt(double(i) / double(N)) * (double)H);
    }
    printf("\n");
    return 0;
}

