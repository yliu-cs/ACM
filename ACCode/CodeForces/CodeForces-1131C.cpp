#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &it : a) cin >> it;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i += 2) cout << a[i] << " ";
    for (int i = (a.size() & 1 ? (a.size() - 2) : (a.size() - 1)); i >= 0; i -= 2) cout << a[i] << " ";
    return 0;
}

