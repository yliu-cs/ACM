#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string Str[6];
    for (int i = 0; i < 6; ++i) {
        cin >> Str[i];
        if (i > 0) {
            if (Str[i][0] == Str[0][0] || Str[i][1] == Str[0][1]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}