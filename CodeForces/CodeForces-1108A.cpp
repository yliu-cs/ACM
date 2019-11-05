#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int q; cin >> q;
    while (q--) {
        vector<int> pos(4);
        for (auto &it : pos) cin >> it;
        if (pos[0] == pos[3]) {
            cout << pos[1] << " " << pos[0] << endl;
            continue;
        }
        cout << pos[0] << " " << pos[3] << endl;
    }
    return 0;
}

