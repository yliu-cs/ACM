#include <bits/stdc++.h>
using namespace std;
typedef double db;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    const int maxn = 1e2 + 5;
    set<string> article[maxn];
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        while (getline(cin, s) && s[0] != '#') {
            string temp;
            for (auto &it : s) {
                it = tolower(it);
                if (isalpha(it)) temp += it;
                else {
                    if (temp.size() >= 3) {
                        if (temp.size() > 10) article[i].insert(temp.substr(0, 10));
                        else article[i].insert(temp);
                    }
                    temp.clear();
                }
            }
            if (temp.size() >= 3) {
                if (temp.size() > 10) article[i].insert(temp.substr(0, 10));
                else article[i].insert(temp);
            }
        }
    }
    int m; cin >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        int ans = 0;
        for (auto &it : article[v])
            if (article[u].find(it) != article[u].end()) ans++;
        cout << fixed << setprecision(1) << (db)((db)ans / (db)(article[u].size() + article[v].size() - ans)) * 100.0 << "%" << endl;
    }
    return 0;
}

