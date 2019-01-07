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
const int maxn = 1e2+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

struct word {
    string _word;
    ll like;
};

int t;
int n, m;
ll sum;
word a[maxn];

bool cmp(word a, word b) {
    if (a.like == b.like) {
        return a._word < b._word;
    }
    return a.like > b.like;
}

int main() {
    //fropen("in.txt", "r", stdin);
    //scanf("%d", &t);
    cin >> t;
    while (t--) {
        //scanf("%d %d", &n, &m);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i]._word >> a[i].like;
        }
        sort(a, a + n, cmp);
        sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += (m - i) * (a[i].like);
        }
        cout << sum;
        for (int i = 0; i < m; ++i) {
            cout << " " << a[i]._word;
        }
        cout << endl;
    }
    return 0;
}

