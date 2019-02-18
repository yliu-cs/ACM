#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    char c; cin >> c;
    for (int i = 0; i < (int)n / 2.0; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

