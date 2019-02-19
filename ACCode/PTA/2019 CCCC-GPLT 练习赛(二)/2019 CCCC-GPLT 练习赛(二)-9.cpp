#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    auto cal = [&](int key) -> string {
        string ans(n * 2 - 1, 'A');
        for (int i = 0; i < key; ++i) {
            for (int j = i; j < n * 2 - 1 - i; ++j) {
                ans[j] = 'A' + i;
            }
        }
        return ans;
    };
    string s[30];
    for (int i = 0; i < n; ++i) s[i] = cal(i + 1);
    for (int i = 0; i < n; ++i) cout << s[i] << endl;
    for (int i = n - 2; i >= 0; --i) cout << s[i] << endl;
    return 0;
}

