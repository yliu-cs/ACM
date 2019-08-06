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
#include <functional>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e+5;
const double eps = 1e-5;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    getline(cin, str);
    int len = str.length();
    bool change = 0;
    int num1 = 0, num2 = 0;
    bool flag1 = 1, flag2 = 1;
    bool flag = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ' && !change) {
            if (i == 0) {
                flag = 1;
            }
            change = 1;
            continue;
        }
        else if (str[i] == ' ' && change) {
            continue;
        }
        if (!change) {
            if (str[i] >= '0' && str[i] <= '9') {
                num1 = num1 * 10 + str[i] - '0';
            }
            else {
                flag1 = 0;
            }
        }
        else {
            if (str[i] >= '0' && str[i] <= '9') {
                num2 = num2 * 10 + str[i] - '0';
            }
            else {
                flag2 = 0;
            }
        }
    }
    if (num1 < 1 || num1 > 1000) {
        flag1 = 0;
    }
    if (num2 < 1 || num2 > 1000) {
        flag2 = 0;
    }
    if (flag1 && !flag) {
        cout << num1;
    }
    else {
        cout << "?";
    }
    cout << " + ";
    if (flag2) {
        cout << num2;
    }
    else {
        cout << "?";
    }
    cout << " = ";
    if (flag1 && flag2 && !flag) {
        cout << num1 + num2;
    }
    else {
        cout << "?";
    }
    return 0;
}

