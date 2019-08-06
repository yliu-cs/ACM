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
typedef pair<int,int> p;
const int inf = 0x3f3f3f3f;
const int maxn = 2e3+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main() {
    //fre();
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    char path_path = str[0], path = str[1];
    int cnt = 0;
    for (int i = 2; str[i] != '\0'; ++i) {
        char now = str[i];
        if (now == 'x') {
            if (path == 'x' && path_path == 'x') {
                cnt++;
                continue;
            }
            else {
                path_path = path;
                path = now;
            }
        }
        else {
            path_path = path;
            path = now;
        }
    }
    printf("%d", cnt);
    return 0;
}
