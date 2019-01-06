#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        if (str[0] != 'l' && str[0] != 'L') {
            cout << "no" << endl;
            continue;
        }
        if (str[1] != 'o' && str[1] != 'O') {
            cout << "no" << endl;
            continue;
        }
        if (str[2] != 'v' && str[2] != 'V') {
            cout << "no" << endl;
            continue;
        }
        if (str[3] != 'e' && str[3] != 'E') {
            cout << "no" << endl;
            continue;
        }
        if (str[4] != 'l' && str[4] != 'L') {
            cout << "no" << endl;
            continue;
        }
        if (str[5] != 'i' && str[5] != 'I') {
            cout << "no" << endl;
            continue;
        }
        if (str[6] != 'v' && str[6] != 'V') {
            cout << "no" << endl;
            continue;
        }
        if (str[7] != 'e' && str[7] != 'E') {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }
    return 0;
}
