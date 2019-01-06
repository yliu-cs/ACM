#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

long long func(int x){
    if (x==1||x==0){
        return 1;
    }
    return (x*func(x-1)+(x-1)*func(x-2))%mod;
}

long long Data[maxn];

void Init() {
    Data[0] = Data[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        Data[i] = (i * Data[i - 1] % mod + (i - 1) * Data[i - 2] % mod) % mod;
    }
}

int main(int argc, char *argv[]) {
    Init();
    int n;
    scanf("%d", &n);
    printf("%lld\n", Data[n]);
    return 0;
}
