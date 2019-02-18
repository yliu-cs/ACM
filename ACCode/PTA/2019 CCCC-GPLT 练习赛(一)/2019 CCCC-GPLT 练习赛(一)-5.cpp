#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    vector<int> m = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    vector<int> r = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};
    int n; cin >> n;
    string id;
    vector<ll> num;
    auto div = [&](string key) {
        num.clear();
        for (int i = 0; i < 17; ++i)
            num.push_back(key[i] - '0');
    };
    auto cal = [&]() {
        ll sum = 0;
        for (int i = 0; i < 17; ++i)
            sum += num[i] * m[i];
        return r[sum % 11];
    };
    auto check = [&](string key) {
        for (int i = 0; i < 17; ++i)
            if (!isdigit(key[i]))
                return false;
        div(key);
        ll ans = cal();
        if (ans == -1) {
            if (id.back() == 'X') return true;
            return false;
        }
        return ans == id.back() - '0';
    };
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        cin >> id;
        if (check(id)) continue;
        flag = false;
        cout << id << endl;
    }
    if (flag) cout << "All passed" << endl;
    return 0;
}

