#include<bits/stdc++.h>
using namespace std;

int T;
int Cnt;
string Str;
string Ans;

int main(int argc, char *argv[]) {
    cin >> T >> Str;
    Cnt = 1;
    for (int i = 1; Cnt <= T; ++i) {
        Ans += Str[Cnt - 1];
        Cnt += i;
    }
    cout << Ans << endl;
    return 0;
}

