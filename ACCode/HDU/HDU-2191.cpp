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
const int maxn = 200;
const double eps = 1e-5;
const double e = 2.718281828459;

int Case_num, Funding_num, Rice_kind_num;
int Rice_value[maxn], Rice_weight[maxn], Rice_num[maxn];
int dp[maxn][maxn];

// 完全背包
/*
 * 利用数组dp[i+1][j]记录从前i种物品中挑选总价值不超过j时总重量的最大值。
 * 递推关系:
 * dp[0][j]=0
 * dp[i+1][j]=max{dp[i][j-kRice_value[i]]+kRice_weight[i]|0≤k}
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Case_num;
    while (Case_num--) {
        mem(Rice_value, 0);
        mem(Rice_weight, 0);
        mem(Rice_num, 0);
        cin >> Funding_num >> Rice_kind_num;
        for (int i = 0; i < Rice_kind_num; ++i) {
            cin >> Rice_value[i] >> Rice_weight[i] >> Rice_num[i];
        }
        for (int i = 0; i < Rice_kind_num; ++i) {
            for (int j = 0; j <= Funding_num; ++j) {
                dp[i + 1][j]=dp[i][j];
                for (int k = 0; k * Rice_value[i] <= j && k <= Rice_num[i]; ++k) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * Rice_value[i]] + k * Rice_weight[i]);
                }
            }
        }
        cout << dp[Rice_kind_num][Funding_num] << endl;
    }
    return 0;
}
