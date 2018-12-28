#include<bits/stdc++.h>
using namespace std;

const int maxn = 998244353;

int T;
int Ang;
int Angle;
int Data[185];

void Init() {
    for (int i = 1; i <= 179; ++i) {
        for (int j = 3; j <= maxn; ++j) {
            if (360 % j != 0) {
                continue;
            }
            Angle = (180 - 360 / j);
            if (Angle == i) {
                Data[i] = j;
                break;
            }
            if (Angle % (j - 2) != 0 || Angle < i) {
                continue;
            }
            Angle /= (j - 2);
            if (i % Angle == 0) {
                Data[i] = j;
                break;
            }
        }
        if (Data[i] == 0) {
            Data[i] = -1;
        }
    }
    Data[180] = -1;
}

int main(int argc, char *argv[]) {
    Init();
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &Ang);
        printf("%d\n", Data[Ang]);
    }
    return 0;
}

