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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

/*
 * 循环小数化分数的规则为：
 * 分子：小数点后数字减(-)非循环体数字
 * 分母：循环体位数个9加非循环体位数个0
 * 最后化简
 */

// 利用gcd求最大公约数化简分数
int gcd(int x, int y) {
    return y ? gcd(y,x % y) : x;
}

void Solve(char *s) {
    int len = strlen(s);    // 计算数据长度
    int Up1 = 0,Up2 = 0;
    int NumOfZero = 0,NumOfNine = 0;
    int flag = 0;
    // 计算分母中0的个数
    for (int i = 2;i < len;++i) {
        if (s[i] == '(') {
            break;
        }
        Up1 = Up1 * 10 + s[i] - '0';
        NumOfZero++;
    }
    // 计算分母中9的个数
    for (int i = 2;i < len;++i) {
        if (s[i] == '(' || s[i] == ')') {
            // 标记为循环小数
            flag = 1;
            continue;
        }
        Up2 = Up2 * 10 + s[i] - '0';
        NumOfNine++;
    }
    NumOfNine -= NumOfZero;
    // 计算分子
    int Up = Up2 - Up1;
    int Down = 0;
    // 不是循环小数
    if (!flag) {
        Up = Up1;
        Up = Up2;
        Down = 1;
        NumOfNine = 0;
    }
    // 计算分母
    for (int i = 0;i < NumOfNine;++i) {
        Down = Down * 10 + 9;
    }
    for (int i = 0;i < NumOfZero;++i) {
        Down *= 10;
    }
    // 化简分数
    int Gcd = gcd(Up, Down);
    Down /= Gcd;
    Up /= Gcd;
    cout << Up << "/" << Down << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    while (N--) {
        char s[15];
        cin >> s;
        Solve(s);
    }
    return 0;
}
