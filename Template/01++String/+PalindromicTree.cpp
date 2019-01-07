#include <bits/stdc++.h>

const int maxn = "Edit";

struct PalindromicTree {
    // 子节点记录数组
    long long Son[maxn][26];
    // 失配指针Fail数组
    long long Fail[maxn];
    // Len[i]:节点i表示的回文串长度(一个节点表示一个回文串)
    long long Len[maxn];
    // Cnt[i]:节点i表示的本质不同的串的个数(最后需要运行Count()函数才可求出正确结果)
    long long Cnt[maxn];
    // Num[i]:以节点i表示的最长回文串的最右端为回文串结尾的回文串个数
    long long Num[maxn];
    // 字符
    long long Str[maxn];
    // 新添加字符后最长回文串表示的节点
    long long Last;
    // 字符数量
    long long StrLen;
    // 节点数量
    long long Tot;

    // 新建节点
    long long NewNode(long long X) {
        for (long long i = 0; i < 26; ++i) {
            Son[Tot][i] = 0;
        }
        Cnt[Tot] = 0;
        Num[Tot] = 0;
        Len[Tot] = X;
        return Tot++;
    }

    // 初始化
    void Init() {
        Tot = 0;
        NewNode(0); NewNode(-1);
        Last = 0;
        StrLen = 0;
        // 开头存字符集中没有的字符，减少特判
        Str[0] = -1;
        Fail[0] = 1;
    }

    long long GetFail(long long X) {
        while (Str[StrLen - Len[X] - 1] != Str[StrLen]) {
            X = Fail[X];
        }
        return X;
    }

    void Add(long long Char) {
        Char -= 'a';
        Str[++StrLen] = Char;
        long long Cur = GetFail(Last);
        if (!Son[Cur][Char]) {
            long long New = NewNode(Len[Cur] + 2);
            Fail[New] = Son[GetFail(Fail[Cur])][Char];
            Son[Cur][Char] = New;
            Num[New] = Num[Fail[New]] + 1;
        }
        Last = Son[Cur][Char];
        Cnt[Last]++;
    }

    void Count() {
        // 若Fail[V]=U，则U一定是V回文子串，所以双亲累加孩子的Cnt
        for (long long i = Tot - 1; i >= 0; --i) {
            Cnt[Fail[i]] += Cnt[i];
        }
    }
};

