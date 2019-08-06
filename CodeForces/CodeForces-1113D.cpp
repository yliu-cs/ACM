#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[0] != s[i] || s[0] != s[s.size() - i - 1])
            flag = false;
    if (flag) {
        cout << "Impossible" << endl;
        return 0;
    }
    string t;
    for (int i = 0; i < s.size(); ++i) {
        t = s.substr(i) + s.substr(0, i);
        if (t == s) continue;
        flag = true;
        for (int j = 0; j <= t.size() / 2; ++j)
            if (t[j] != t[t.size() - j - 1])
                flag = false;
        if (flag) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}

