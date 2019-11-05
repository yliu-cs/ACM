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
const int maxn = 1010;
const double eps = 1e-5;
const double e = 2.718281828459;

ll Case_num, Bone_num, Bag_Volume;
ll Bone_value[maxn], Bone_volume[maxn];
ll dp[maxn][maxn];

// 01背包动态规划
void Dynamic_programming_from_front() {
    for (ll i = 1; i <= Bone_num; ++i) {
        for (ll j = 0; j <= Bag_Volume; ++j) {
            if (j < Bone_volume[i]) {
                dp[i + 1][j] = dp[i][j];
            }
            else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - Bone_volume[i]] + Bone_value[i]);
            }
        }
    }
}

// 信息读取，数据处理
void Solve() {
    cin >> Case_num;
    while (Case_num--) {
        mem(Bone_value, 0);
        mem(Bone_volume, 0);
        cin >> Bone_num >> Bag_Volume;
        for (int i = 1; i <= Bone_num; ++i) {
            cin >> Bone_value[i];
        }
        for (int i = 1; i <= Bone_num; ++i) {
            cin >> Bone_volume[i];
        }
        mem(dp, 0);
        Dynamic_programming_from_front();
        cout << dp[Bone_num + 1][Bag_Volume] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	Solve();
    return 0;
}
