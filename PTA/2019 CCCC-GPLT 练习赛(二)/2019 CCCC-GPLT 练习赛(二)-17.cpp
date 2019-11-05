#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; cin >> s;
    vector<int> cnt(4);
    for (auto &it : s) {
        if (it == 'G' || it == 'g') cnt[0]++;
        else if (it == 'P' || it == 'p') cnt[1]++;
        else if (it == 'L' || it == 'l') cnt[2]++;
        else if (it == 'T' || it == 't') cnt[3]++;
    }
    vector<char> m = {'G', 'P', 'L', 'T'};
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < 4; ++i) {
            if (cnt[i]) {
                cout << m[i];
                cnt[i]--;
                flag = true;
            }
        }
    }
    cout << endl;
    return 0;
}

