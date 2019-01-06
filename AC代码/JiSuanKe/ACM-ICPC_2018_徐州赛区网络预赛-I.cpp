#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int Case = 1, N; Case <= T; ++Case) {
        char Seed;
        string str;
        cin >> N >> Seed;
        if (N == 0) {
            cout << 0 << endl;
            continue;
        }
        getchar();
        getline(cin, str);
        int Ans = 0;
        bool Flag = false;
        int Cnt = 0;
        for (int i = 0; i < int(str.length()); ++i) {
            if (str[i] != Seed) {
                Flag = true;
            }
            if (Flag) {
                if (Cnt == 0) {
                    Cnt = abs(Seed - str[i]);
                    if (Cnt < 10) {
                        Ans += 1;
                    }
                    else {
                        Ans += 2;
                    }
                }
                else {
                    Ans += 2;
                }
            }
        }
        Ans = Ans == 0 ? 1 : Ans;
        cout << Ans << endl;
    }
    return 0;
}

