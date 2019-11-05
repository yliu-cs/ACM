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
    string s;
    while (cin >> s) {
        int sum = 0;
        int len = s.length();
        bool *Judge;
        Judge = new bool[len];
        for (int i = 0; i < len ; ++i) {
            Judge[i] = 1;
        }
        for (int i = len - 1; i >= 0; --i) {
            bool flag = 0;
            if (Judge[i]) {
                for (int j = 0; j < i; ++j) {
                    if (s[j] == s[i]) {
                        flag = 1;
                        Judge[i] = 0;
                        Judge[j] = 0;
                    }
                }
            }
            if (flag) {
                sum++;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (Judge[i]) {
                sum++;
            }
        }
        if (sum % 2 == 0) {
            cout << "CHAT WITH HER!" << endl;
        }
        else {
            cout << "IGNORE HIM!" << endl;
        }
    }
    return 0;
}
