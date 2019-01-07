#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);
    vector<int> Suit(N, 2);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &Suit[i]);
    }
    bool Flag = true;
    int Cnt = 0, Ans = 0;;
    int Mid = N / 2;
    for (int i = 0; i < Mid; ++i) {
        if (Suit[i] == 2) {
            if (Suit[N - i - 1] == 0) {
                Ans += A;
            }
            else if (Suit[N - i - 1] == 1) {
                Ans += B;
            }
            else {
                if (Suit[N - i - 1] == 2) {
                    Cnt += 2;
                }
                else {
                    Cnt++;
                }
            }
        }
        else if (Suit[N - i - 1] == 2) {
            if (Suit[i] == 0) {
                Ans += A;
            }
            else if (Suit[i] == 1) {
                Ans += B;
            }
            else {
                if (Suit[i] == 2) {
                    Cnt += 2;
                }
                else {
                    Cnt++;
                }
            }
        }
        else if (Suit[i] != Suit[N - i - 1]) {
            Flag = false;
        }
    }
    Ans += Cnt * min(A, B);
    if ((N & 1) && Suit[(N + 1) / 2 - 1] == 2) {
        Ans += min(A, B);
    }
    Ans = Flag ? Ans : -1;
    printf("%d\n", Ans);
    return 0;
}

