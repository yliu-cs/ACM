#include <stdio.h>
#include <iostream>
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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 33000;

// w数组代表1,2,3分硬币
int w[4] = {0,1,2,3};
int c1[maxn],c2[maxn];

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem(c2, 0);
    // int类型无法使用memset赋值为1
    for (int i = 0;i < maxn;++i) {
        c1[i] = 1;
    }
    // 模拟多项式乘法,c2作为中间变量,c1存储结果
    // c1[i]的值为x^i的系数
    for (int k = 2;k <= 3;++k) {
        for (int i = 0;i < maxn;++i) {
            for (int j = 0;(i + j) < maxn;j += w[k]) {
                c2[i + j] += c1[i];
            }
        }
        for (int i = 0;i < maxn;++i) {
            c1[i] = c2[i];
            c2[i] = 0;
        }
    }
    int n;
    while (cin >> n) {
        cout << c1[n] << endl;
    }
    return 0;
}
