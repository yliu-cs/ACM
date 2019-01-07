#include<bits/stdc++.h>
using namespace std;

vector<unsigned long long> Array;

bool Check(unsigned long long X) {
    int Index = lower_bound(Array.begin(), Array.end(), X) - Array.begin();
    for (int i = Index; i >= 0; --i) {
        if (find(Array.begin(), Array.end(), X - Array[i]) != Array.end()) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    for (unsigned long long i = 1; i < 63; ++i) {
        Array.push_back((unsigned long long)1 << i);
    }
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        unsigned long long N;
        scanf("%llu", &N);
        if (N & 1) {
            printf("NO\n");
        }
        else if (Check(N)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

