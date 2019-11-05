#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int Q; cin >> Q;
    for (int Query = 1; Query <= Q; ++Query) {
        int N; string Str; cin >> N >> Str;
        if (N == 2 && Str[0] >= Str[1]) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl << "2" << endl;
        cout << Str[0] << " " << Str.substr(1, N - 1) << endl;
    }
    return 0;
}

