#include <bits/stdc++.h>

// 最长不下降子序列(LIS)，Num:序列
int LIS(std::vector<int> &Num) {
    int Ans = 1;
    // Last[i]为长度为i的不下降子序列末尾元素的最小值
    std::vector<int> Last(int(Num.size()) + 1, 0);
    Last[1] = Num[1];
    for (int i = 2; i <= int(Num.size()); ++i) {
        if (Num[i] >= Last[Ans]) {
            Last[++Ans] = Num[i];
        }
        else {
            int Index = std::upper_bound(Last.begin() + 1, Last.end(), Num[i]) - Last.begin();
            Last[Index] = Num[i];
        }
    }
    // 返回结果
    return Ans;
}
