#include<bits/stdc++.h>
using namespace std;

int X, Y;
int Len;
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d", &X, &Y);
    if (X == 0 && Y == 0) {
        printf("0\n");
        return 0;
    }
    Len = max(abs(X), abs(Y));
    Ans = (Len - 1) * 4;
    if (X == Len && Y > -(Len - 1) && Y <= Len) {
        Ans += 1;
    }
    else if (Y == Len && X >= -Len && X <= Len) {
        Ans += 2;
    }
    else if (-X == Len && Y >= -Len && Y <= Len) {
        Ans += 3;
    }
    else if (-Y == Len && X > Y && X <= -Y) {
        Ans += 4;
    }
    printf("%d\n", Ans);
    return 0;
}

