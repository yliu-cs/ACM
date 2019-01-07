#include<bits/stdc++.h>
using namespace std;
#define maxn 10000005
#define LL long long
int minu[maxn], prim[maxn], vis[maxn], cnt;

void Init() {
    int N = maxn;
    memset(prim, 0, sizeof(prim));
    memset(minu, 0, sizeof(minu));
    memset(vis, 0, sizeof(vis));
    minu[1] = 1;
    cnt = 0;
    for (int i = 2; i < N; i ++) {
        if(!vis[i]) {
            prim[cnt++] = i;
            minu[i] = -1;
        }
        for (int j = 0; j < cnt && i * prim[j] < N; j ++) {
            vis[i * prim[j]] = 1;
            if(i % prim[j]) minu[i * prim[j]] = - minu[i];
            else {
                minu[i * prim[j]] = 0;
                break;
            }
        }
    }
}

LL solve(int d) {
    LL ans = 0;
    for (int i = 1; i <= d; i ++)
        ans += (LL)minu[i] * (d/i) * (d/i);
    return ans;
}

int main() {
    return 0;
}