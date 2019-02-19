#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) array[i] = i + 1;
    do {
        for (auto &it : array) cout << it;
        cout << endl;
    } while (next_permutation(array.begin(), array.end()));
    return 0;
}

