#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a = 0, b = 0;
    cin >> n;
    string s1, s2;
    cin >> s1;
    a++;
    n--;
    while (n--) {
        string s;
        cin >> s;
        if (s1.compare(s) && s2 == "") {
            s2 = s;
            b++;
        }
        else if (s1.compare(s) == 0) {
            a++;
        }
        else {
            b++;
        }
    }
    if (a > b) {
        cout << s1;
    }
    else {
        cout << s2;
    }
    return 0;
}
