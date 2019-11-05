#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    string s; cin >> s;
    string color("RGB");
    sort(color.begin(), color.end());
    string res(""); int ans(1e6);
    do {
        string book(""); int cnt(0);
        for (int i = 0; i < n; ++i) {
            book += color[i % 3];
            cnt += s[i] != color[i % 3];
        }
        if (cnt < ans) {
            ans = cnt;
            res = book;
        }
    } while (next_permutation(color.begin(), color.end()));
    cout << ans << endl << res << endl;
    return 0;
}

