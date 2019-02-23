#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef double db;

int main(int argc, char *argv[]) {
    ull n; cin >> n;
    long double ans = 1;
    ull book = 1;
    for (ull i = 1; i <= min(n, (ull)60); ++i) {
        book *= i;
        ans += (db)1.0 / (db)book;
    }
    printf("%.8Lf\n", ans);
    return 0;
}

