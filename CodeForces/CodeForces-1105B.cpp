#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<pair<int, int>> seg;
    for (int l = 0, r = 0; l < n; l = r) {
        while (s[l] == s[r] && r < n) r++;
        seg.push_back(make_pair(l, r));
    }
    vector<int> ans(26, 0);
    for (auto &it : seg) ans[s[it.first] - 'a'] += (it.second - it.first) / k;
    sort(ans.begin(), ans.end());
    cout << ans.back() << endl;
    return 0;
}

