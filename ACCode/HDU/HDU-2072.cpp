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
#include <map>
using namespace std;
#define mam(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

string a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        if (str == "#") {
            break;
        }
        string temp;
        int cnt = 0;
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == ' ') {
                bool flag = 1;
                for (int j = 0; j < cnt; ++j) {
                    if (a[j] == temp) {
                        flag = 0;
                    }
                }
                bool ot_flag = 0;
                for (int k = 0; temp[k] != '\0'; ++k) {
                    if (temp[k] != ' ') {
                        ot_flag = 1;
                    }
                }
                if (flag && ot_flag) {
                    a[cnt++] = temp;
                }
                temp.clear();
            }
            else {
                temp += str[i];
            }
        }
        bool last_flag = 1;
        for (int j = 0; j < cnt; ++j) {
            if (a[j] == temp) {
                last_flag = 0;
            }
        }
        bool last_ot_flag = 0;
        for (int k = 0; temp[k] != '\0'; ++k) {
            if (temp[k] != ' ') {
                last_ot_flag = 1;
            }
        }
        if (last_flag && last_ot_flag) {
            a[cnt++] = temp;
        }
        temp.clear();
        cout << cnt << endl;
        for (int i = 0; i <= cnt; ++i) {
            a[i].clear();
        }
    }
    return 0;
}
