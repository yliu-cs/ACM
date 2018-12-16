#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long QuickMul(long long A, long long B) {
    long long Ans = 0;
    while (B) {
        if (B & 1) {
            Ans = (Ans + A) % mod;
        }
        A = (A + A) % mod;
        B >>= 1;
    }
    return Ans;
}

long long QuickPow(long long A, long long B) {
    long long Ans = 1;
    while (B) {
        if (B & 1) {
            Ans = QuickMul(Ans, A) % mod;
        }
        A = QuickMul(A, A) % mod;
        B >>= 1;
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    long long A, B;
    char Op;
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> Op >> B;
        if (Op == '+') {
            cout << (A + B) % mod << endl;
        }
        else if (Op == '*') {
            cout << QuickMul(A, B) << endl;
        }
        else if (Op == '^') {
            cout << QuickPow(A, B) << endl;
        }
    }
    return 0;
}

