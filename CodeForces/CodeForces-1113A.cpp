#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, v; cin >> n >> v;
    int ans = min(n - 1, v);
    if (n - 1 > v) {
        for (int i = 2, k = 0; k < n - 1 - v; ++k, ++i) ans += i;
    }
    cout << ans << endl;
    return 0;
}

