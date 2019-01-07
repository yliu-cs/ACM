#include <stdio.h>
#include <iostream>
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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string a;
    cin >> n >> a;
    cin.get();
    string s;
    getline(cin, s);
    int len = s.length();
    if (len < n) {
        int num = n - len;
        string b = a;
        for (int i = 0; i < num; ++i) {
            b += s;
            s = b;
            b = a;
        }
        cout << s << endl;
    }
    else if (len > n) {
        for (int i = len - n; i < len; ++i) {
            cout << s[i];
        }
        cout << endl;
    }
    else {
        cout << s << endl;
    }
    return 0;
}
