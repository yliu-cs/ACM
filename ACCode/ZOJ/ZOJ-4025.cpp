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

int t;
int n;
int a[maxn], b[maxn];
int cnt;

int main() {
    //fropen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        map<int, int> mp;
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            int temp = b[i] - a[i];
            mp[temp]++;
            if (mp[temp] > cnt) {
                cnt = mp[temp];
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

