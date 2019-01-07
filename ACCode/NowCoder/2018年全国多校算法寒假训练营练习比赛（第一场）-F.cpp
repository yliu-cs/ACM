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
    int T;
    cin >> T;
    while (T--) {
        int blood = 100;
        int a,b,c;
        cin >> a >> b >> c;
        int Die = 6 * a;
        int i = b;
        int book = 0;
        for (;i >= 0;) {
            --i;
            blood -= a;
            if (blood - a <= Die && c > 0) {
                book += 7;
                blood = 80;
                c--;
            }
            else if (blood <= a && c == 0 && i > 1) {
                cout << "NO" << endl;
                break;
            }
            else {
                book++;
            }
            if (i == 0) {
                cout << "YES" << endl;
                break;
            }
        }
    }
    return 0;
}
