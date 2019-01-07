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

int t;
int n, b;
int a;
bool flag;

int main() {
    //fropen("in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        flag = 0;
        scanf("%d %d", &n, &b);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (flag) {
                continue;
            }
            else {
                if ((a + b) % 7 == 0) {
                    flag = 1;
                }
            }
        }
        if (!flag) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}

