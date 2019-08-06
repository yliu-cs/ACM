#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> d(n);
    for (auto &it : d) cin >> it;
    map<int, int> cnt;
    for (auto it : d) cnt[it]++;
    vector<int> array;
    auto lcm = [&] (int x, int y) {return x == 0 ? y : x * y / __gcd(x, y);};
    int low(0);
    for (auto it : cnt) {
        if (it.second == 2) low = lcm(low, it.first);
        else array.push_back(it.first);
    }
    sort(array.begin(), array.end());
    int x(low), y(low);
    if (!array.empty()) {
        x = lcm(x, array.back());
        for (auto &it : array) {
            if (array.back() % it == 0) continue;
            y = lcm(y, it);
        }
    }
    cout << x << " " << y << endl;
    return 0;
}

