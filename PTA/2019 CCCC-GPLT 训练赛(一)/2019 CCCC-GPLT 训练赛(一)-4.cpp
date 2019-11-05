#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    queue<char> a; stack<char> b; map<char, int> pos;
    string s; cin >> s;
    vector<pair<int, int>> ans;
    for (auto &it : s) {
        a.push(it);
        pos[it] = 1;
    }
    cin >> s;
    bool flag = true;
    for (auto &i : s) {
        if (pos[i] == 1) {
            while (a.front() != i) {
                b.push(a.front());
                pos[a.front()] = 3;
                a.pop();
                ans.push_back(make_pair(1, 3));
            }
            ans.push_back(make_pair(1, 2));
            a.pop();
        }
        else if (pos[i] == 3) {
            if (b.top() != i) {
                flag = false;
                break;
            }
            b.pop();
            ans.push_back(make_pair(3, 2));
        }
    }
    if (flag) for (auto &it : ans) cout << it.first << "->" << it.second << endl;
    else cout << "Are you kidding me?" << endl;
    return 0;
}

