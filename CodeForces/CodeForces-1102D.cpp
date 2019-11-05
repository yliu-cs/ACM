#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    string s; cin >> s;
    map<int, int> cnt;
    for (auto it : s) cnt[it - '0']++;
    for (int i = 0; i < n && cnt[2] > n / 3; ++i) {
        if (s[i] == '2') {
            if (cnt[0] < n / 3) {
                s[i] = '0';
                cnt[0]++;
                cnt[2]--;
            }
            else if (cnt[1] < n / 3) {
                s[i] = '1';
                cnt[1]++;
                cnt[2]--;
            }
        }
    }
    for (int i = n - 1; i >= 0 && cnt[0] > n / 3; --i) {
        if (s[i] == '0') {
            if (cnt[2] < n / 3) {
                s[i] = '2';
                cnt[2]++;
                cnt[0]--;
            }
            else if (cnt[1] < n / 3) {
                s[i] = '1';
                cnt[1]++;
                cnt[0]--;
            }
        }
    }
    for (int l = 0, r = n - 1; l < n && r >= 0 && cnt[1] > n / 3; ++l, --r) {
        if (s[l] == '1' && cnt[0] < n /3) {
            s[l] = '0';
            cnt[0]++;
            cnt[1]--;
        }
        if (s[r] == '1' && cnt[2] < n / 3) {
            s[r] = '2';
            cnt[2]++;
            cnt[1]--;
        }
    }
    cout << s << endl;
    return 0;
}

