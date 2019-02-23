#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int up, down; char c; cin >> up >> c >> down;
    int gcd = __gcd(up, down);
    up /= gcd; down /= gcd;
    cout << up << "/" << down << endl;
    return 0;
}

