#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; cin >> s;
    bool flag = false;
    for (int k = 0; k < 4; ++k) {
        int ans = 0;
        for (int j = 7; j >= 0; --j) {
            int pos = k * 8 + j;
            if (s[pos] == '1') ans += (1 << (8 - j - 1));
        }
        if (flag) cout << ".";
        cout << ans;
        flag = true;
    }
    return 0;
}

