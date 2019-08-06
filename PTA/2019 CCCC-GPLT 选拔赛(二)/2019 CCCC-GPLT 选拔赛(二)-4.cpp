#include <bits/stdc++.h>
using namespace std;

int N;
bool Flag;

bool Check(int Key) {
    int Temp = sqrt(Key);
    return Temp * Temp == Key;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int Temp = N - i * i;
        if (Temp <= 0 || (int)sqrt(Temp) < i) break;
        if (Check(N - i * i)) {
            printf("%d %d\n", i, (int)sqrt(N - i * i));
            Flag = true;
        }
    }
    if (!Flag) printf("No Solution\n");
    return 0;
}

