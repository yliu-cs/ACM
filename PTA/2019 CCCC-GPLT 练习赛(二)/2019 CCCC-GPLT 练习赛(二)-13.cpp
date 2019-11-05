#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; getline(cin, s);
    vector<int> cnt(11, 0);
    for (int i = 0; i < s.size() && s[i] != '#'; ++i) {
        if (isdigit(s[i])) cnt[s[i] - '0']++;
        else cnt[10]++;
    }
    cout << "digiter=";
    for (int i = 0; i < 10; ++i) cout << " " << cnt[i];
    cout << endl;
    cout << "other=" << cnt[10];
    return 0;
}

