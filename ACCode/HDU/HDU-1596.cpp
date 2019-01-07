#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int maxn = 1010;

int n;
double e[maxn][maxn] = {0};

// 弗洛伊德算法求多源最短路
void Floyd() {
    for (int k = 1;k <= n;++k) {
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                if (e[i][j] < e[i][k] * e[k][j]) {
                    e[i][j] = e[i][k] * e[k][j];
                }
            }
        }
    }
}

int main() {
    mem(e, 0);
    while (cin >> n) {
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                scanf("%lf",&e[i][j]);
            }
        }
        Floyd();
        int Q;
        scanf("%d",&Q);
        while (Q--){
            int a,b;
            scanf("%d %d",&a,&b);
            if (e[a][b] == 0) {
                printf("What a pity!\n");
            }
            else {
                printf("%.3f\n",e[a][b]);
            }
        }
    }
    return 0;
}
