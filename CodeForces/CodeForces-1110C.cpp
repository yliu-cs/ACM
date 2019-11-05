#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll N;
ll Len;
map<ll, ll> Mp;

int main(int argc, char *argv[]) {
    Mp[3] = 1; Mp[7] = 1; Mp[15] = 5; Mp[31] = 1; Mp[63] = 21;
    Mp[127] = 1; Mp[255] = 85; Mp[511] = 73; Mp[1023] = 341;
    Mp[2047] = 89; Mp[4095] = 1365; Mp[8191] = 1;  Mp[16383] = 5461;
    Mp[32767] = 4681; Mp[65535] = 21845; Mp[131071] = 1;
    Mp[262143] = 87381; Mp[524287] = 1; Mp[1048575] = 349525;
    Mp[2097151] = 299593; Mp[4194303] = 1398101; Mp[8388607] = 178481;
    Mp[16777215] = 5592405; Mp[33554431] = 1082401;
    scanf("%d\n", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%lld", &N);
        Len = log2(N) + 1;
        if (Mp[N]) printf("%lld\n", Mp[N]);
        else printf("%lld\n", (1ll << Len) - 1);
    }
    return 0;
}

