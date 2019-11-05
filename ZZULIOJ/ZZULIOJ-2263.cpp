include <iostream>
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
const int maxn = 1e3+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
 
int n, m;
int front_view[maxn];
int left_view[maxn];
int sum;
int min_ans, max_ans;
set<int> mh;
 
int main() {
    sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &front_view[i]);
        sum += front_view[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &left_view[i]);
        sum += left_view[i];
    }
    min_ans = sum, max_ans = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = 0;
        for (int j = 0; j < m; ++j) {
            max_ans += front_view[i] < left_view[j] ? front_view[i] : left_view[j];
            if (front_view[i] == left_view[j] && !flag && !mh.count(j)) {
                min_ans -= left_view[j];
                mh.insert(j);
                flag = 1;
            }
        }
    }
    printf("%d %d\n", min_ans, max_ans);
    return 0;
}
