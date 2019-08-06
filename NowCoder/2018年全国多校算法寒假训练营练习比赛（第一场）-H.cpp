#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    long long Num[81];
    Num[1] = 1;
    Num[2] = 2;
    for (int i = 3;i <= 80;++i) {
        Num[i] = Num[i - 1] + Num[i - 2];
    }
    int T;
    cin >> T;
    while (T-- ) {
        int n;
        cin >> n;
        cout << Num[n] << endl;
    }
    return 0;
}
