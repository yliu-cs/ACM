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
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
 
int main() {
    int cnt[27];
    mem(cnt, 0);
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; str[i] != '\0'; ++i) {
        cnt[str[i] - 'a' + 1]++;
        for (int j = 0; j < (str[i] - 'a' + 1); ++j) {
            cnt[j] = 0;
        }
    }
    for (int i = 27; i >= 1; --i) {
        if (cnt[i]) {
            while (cnt[i]--) {
                cout << (char)('a' + i - 1);
            }
        }
    }
    return 0;
}
