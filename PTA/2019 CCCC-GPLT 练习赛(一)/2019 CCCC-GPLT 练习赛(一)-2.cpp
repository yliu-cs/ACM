#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s; cin >> s;
    if (s[0] == '1') cout << "Hunan Agricultural University" << endl;
    else if (s[0] == '2') cout << "Jishou University" << endl;
    else if (s[0] == '3') cout << "Huaihua University" << endl;
    else if (s[0] == '4') cout << "Aerospace University" << endl;
    else if (s[0] == '5') cout << "Ocean University" << endl;
    else cout << "Other University" << endl;
    return 0;
}

