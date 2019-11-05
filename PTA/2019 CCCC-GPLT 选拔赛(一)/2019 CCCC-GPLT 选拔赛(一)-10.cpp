#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30;

int main(int argc, char *argv[]) {
    vector<int> a(maxn, 0), sum(maxn, 0);
    a[1] = 1;
    sum[1] = sum[2] = 1;
    for (int i = 3; i < maxn; ++i) {
        a[i] = sum[i - 2];
        sum[i] = sum[i - 1] + a[i];
    }
    int n; cin >> n;
    cout << lower_bound(sum.begin(), sum.end(), n) - sum.begin() << endl;
    return 0;
}

