#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))

const int maxn = "Edit";

// 树状数组
int C[maxn];

// 更新树状数组信息
void Update(int X, int Val) {
    while (X < maxn) {
        C[X] += Val;
        X += lowbit(X);
    }
}

// 求和
int GetSum(int X) {
    int Res = 0;
    while (X > 0) {
        Res += C[X];
        X -= lowbit(X);
    }
    return Res;
}
