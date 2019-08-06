#include<bits/stdc++.h>
using namespace std;

int T;
int N;

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        // 利用多边形外交和360判断
        if (360 % (180 - N)) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}

