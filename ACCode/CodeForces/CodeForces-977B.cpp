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
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

string str[100];
int n;
int cnt;
string s;
int _count[100];
int ans;
int book;

int main() {
    //fre();
    cnt = 0;
    for (int i = 0; i < 100; ++i) {
        str[i].clear();
    }
    mem(_count, 0);
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        string temp;
        temp += s[i]; temp += s[i + 1];
        bool flag = 0;
        for (int i = 0; i < cnt; ++i) {
            if (str[i] == temp) {
                _count[i]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            str[cnt] = temp;
            _count[cnt++]++;
        }
    }
    ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (_count[i] > ans) {
            ans = _count[i];
            book = i;
        }
    }
    cout << str[book];
    return 0;
}
