#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<string> s(3);
    for (auto &it : s) cin >> it;
    sort(s.begin(), s.end());
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ":" << s[i] << endl;
    }
    return 0;
}

