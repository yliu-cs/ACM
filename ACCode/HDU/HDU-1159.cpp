//#include<bits/stdc++.h>
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
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 510;
const double eps = 1e-5;
const double e = 2.718281828459;

string str1, str2;
int dp[maxn][maxn];

// LCS（最长公共子序列）
/*
 * dp[i][j]:str11~str2i和str21~str2i对应的LCS长度
 * 因此，str11~str2i和str21~str2i对应的公共子列有三种情况:
 * (1):当str1i=str2i时，在str11~str2i和str21~str2i的公共子列末尾追加上str1i(或者str2i)
 * (2):str11~str2i-1和str21~str2i的公共子列
 * (3):str11~str2i和str21~str2i-1的公共子列
 * 递推式:
 * dp[i+1][j+1]=max(dp[i][j]+1,dp[i][j+1],dp[i+1][j])(str1i+1=str2i+1)
 * dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])(其他)
 */
void LCS() {
    int lenA = str1.length(), lenB = str2.length();
    for (int i = 0; i < lenA; ++i) {
        for (int j = 0; j < lenB; ++j) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[lenA][lenB] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> str1 >> str2) {
        mem(dp, 0);
        LCS();
    }
    return 0;
}
