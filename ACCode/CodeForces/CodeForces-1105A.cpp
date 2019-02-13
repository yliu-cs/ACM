#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> len(n);
    for (auto &it : len) cin >> it;
    sort(len.begin(), len.end());
    int ans(1e9), t(0);
    for (int i = len[0]; i <= len.back(); ++i) {
        int book(0);
        for (auto &it : len) book += it == i ? 0 : abs(it - i) - 1;
        if (book < ans) {
            ans = book;
            t = i;
        }
    }
    cout << t << " " << ans << endl;
    return 0;
}

