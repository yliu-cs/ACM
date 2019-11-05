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
const int maxn = 21;

// a数组存储连接情况,flag数组标记经过位置,ans存储路径
int a[maxn][4],flag[maxn],ans[maxn];
// m为起点位置,step为一条路径步数,book为路径数
int m,step = 0,book = 1;

// 深度优先搜索
void dfs(int st,int step) {
    // 第19步为递归出口
    if (step == 19 && flag[st] == 0) {
        // 当最后一步和起点相连时路径可用，输出
        if (a[st][1] == m || a[st][2] == m || a[st][3] == m) {
            ans[19] = st;
            cout << book++ << ":  ";
            // 依次输出路径
            for (int i = 0;i < 20;++i) {
                cout << ans[i] << " ";
            }
            cout << m << endl;
        }
    }
    // 在相连的三个位置中搜索可走位置
    for (int i = 1;i <= 3;++i) {
        if (flag[st] == 0) {
            // 标记搜索到的位置
            flag[st] = 1;
            ans[step] = st;
            dfs(a[st][i], step + 1);
            // 释放标记
            flag[st] = 0;
        }
    }
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 输入连接情况
    for (int i = 1;i <= 20;++i) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    // 输入起点
    while (cin >> m,m) {
        // 初始化信息
        mem(flag, 0);
        step = 0;
        book = 1;
        dfs(m, 0);
    }
    return 0;
}
