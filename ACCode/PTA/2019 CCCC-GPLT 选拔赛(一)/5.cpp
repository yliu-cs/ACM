#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; ++i) a.push_back(i);
    do {
        for (auto &it : a) cout << it;
        cout << endl;
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}

