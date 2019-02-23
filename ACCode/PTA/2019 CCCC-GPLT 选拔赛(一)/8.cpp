#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s, ans;
    for (int i = 0; i < 4; ++i) {
        cin >> s;
        for (int i = 0; i < 2; ++i) ans += s[i];
    }
    ans += '\n';
    cout << ans;
    return 0;
}

