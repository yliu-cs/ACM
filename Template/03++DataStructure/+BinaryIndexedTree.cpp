#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))

const int maxn = "Edit";

// 树状数组
int Array[maxn];

// 更新树状数组信息
void Update(int X, int Val) {
    while (X < maxn) {
        Array[X] += Val;
        X += lowbit(X);
    }
}

// 查询
int Query(int X) {
    int Ans = 0;
    while (X > 0) {
        Ans += Array[X];
        X -= lowbit(X);
    }
    return Ans;
}
