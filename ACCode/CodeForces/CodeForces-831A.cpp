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

int n;
int a[maxn];
bool up_flag, flag, down_flag;
bool ans_flag;

bool judge() {
    if (n == 1) {
        return 1;
    }
    if (!ans_flag) {
        return 0;
    }
    return 1;
}

int main() {
    //fropen("in.txt", "r", stdin);
    up_flag = 0;
    flag = 0;
    down_flag = 0;
    ans_flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (!ans_flag) {
            continue;
        }
        if (i != 0) {
            if (a[i] == a[i - 1]) {
                if (down_flag) {
                    ans_flag = 0;
                }
                else if (!flag) {
                    flag = 1;
                }
            }
            else {
                if (a[i] > a[i - 1]) {
                    if (flag || down_flag) {
                        ans_flag = 0;
                    }
                    else if (!up_flag) {
                        up_flag = 1;
                    }
                }
                else {
                    if (!down_flag) {
                        down_flag = 1;
                    }
                }
            }
        }
    }
    if (judge()) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
