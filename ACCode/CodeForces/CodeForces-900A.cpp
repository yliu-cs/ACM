#include<bits/stdc++.h>
using namespace std;

int N;
int X, Y;
int LeftCnt, RightCnt;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    LeftCnt = 0; RightCnt = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &X, &Y);
        if (X > 0) {
            RightCnt++;
        }
        else if (X < 0) {
            LeftCnt++;
        }
    }
    if (!LeftCnt || !RightCnt || LeftCnt < 2 || RightCnt < 2) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}

