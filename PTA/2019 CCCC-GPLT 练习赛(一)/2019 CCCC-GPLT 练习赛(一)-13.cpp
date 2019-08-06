#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    auto check = [&](string key) {
        if (key.size() != 11) return false;
        for (auto &it : key)
            if (!isdigit(it))
                return false;
        if (key[0] != '1') return false;
        return true;
    };
    string s; cin >> s;
    if (check(s)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}

