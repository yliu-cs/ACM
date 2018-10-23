// 一般的SG函数

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int N = 1005;
int SG[N], f[N], S[N];
int m, n, p;
void ff() {
    for (int i = 0; i < N; i ++) {
        f[i] = i;
    }
}
void GetSG(int n, int m) {
    memset(SG, 0, sizeof(SG));
    for (int i = 1; i <= n; i ++) {
        memset(S, 0, sizeof(S));
        for (int j = 1; f[j] <= i && j <= m; j ++) {
            S[SG[i - f[j]]] = 1;
        }
        for (int j = 0; ; j ++) {
            if (!S[j]) {
                SG[i] = j;
                break;
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    int n;
    ff();
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        GetSG(a, b);
        //cout<<SG[a]<<endl;
        if (SG[a])
            printf("first\n");
        else
            printf("second\n");
    }
    return 0;
}