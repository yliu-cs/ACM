#include <bits/stdc++.h>

const int maxn = 5e5 + 5;

// Trie Tree节点
int Son[maxn][26];
// Trie Tree节点数量
int Tot;

// 字符串数量统计数组
int Cnt[maxn];

// Trie Tree初始化
void TrieInit() {
    Tot = 0;
    memset(Cnt, 0, sizeof(Cnt));
    memset(Son, 0, sizeof(Son));
}

// 计算字母下标
int Pos(char X) {
    return X - 'a';
}

// 向Trie Tree中插入字符串Str
void Insert(string Str) {
    int Cur = 0, Len = int(Str.length());
    for (int i = 0; i < Len; ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            Son[Cur][Index] = ++Tot;
        }
        Cur = Son[Cur][Index];
        Cnt[Cur]++;
    }
}

// 查找字符串Str，存在返回true，不存在返回false
bool Find(string Str) {
    int Cur = 0, Len = int(Str.length());
    for (int i = 0; i < Len; ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            return false;
        }
        Cur = Son[Cur][Index];
    }
    return true;
}

// 查询字典树中以Str为前缀的字符串数量
int PathCnt(string Str) {
    int Cur = 0, Len = int(Str.length());
    for (int i = 0; i < Len; ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            return 0;
        }
        Cur = Son[Cur][Index];
    }
    return Cnt[Cur];
}
