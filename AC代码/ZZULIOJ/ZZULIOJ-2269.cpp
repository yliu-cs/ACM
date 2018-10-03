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
 
int n;
int a[maxn], b[maxn];
priority_queue<int> que;
 
void Output_res() {
    if (que.empty()) {
        return;
    }
    else {
        int output_temp = que.top();
        que.pop();
        Output_res();
        printf("%d ", output_temp);
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        que.push(a[1] + b[i]);
    }
    sort(b + 1, b + n + 1);
    for (int i = 2; i <= n; ++i) {
        if (a[i] + b[1] > que.top()) {
            break;
        }
        for (int j = 1; j <= n; ++j) {
            if (a[i] + b[j] > que.top()) {
                break;
            }
            que.push(a[i] + b[j]);
            que.pop();
        }
    }
    Output_res();
    return 0;
}
