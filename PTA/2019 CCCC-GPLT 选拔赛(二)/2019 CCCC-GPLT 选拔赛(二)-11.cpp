#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll Ans;

int main(int argc, char *argv[]) {
    while (~scanf("%d", &N) && N) {
        Ans = 0;
        int Day = 1, Cur = 1, Cnt = 1;
        while (Day <= N) {
            Ans += Cur;
            Cnt++;
            if (Cnt >= Cur) {
                Cur++;
                Cnt = 0;
            }
            Day++;
        }
        printf("%d %lld\n", N, Ans);
    }
    return 0;
}

