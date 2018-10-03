#include <bits/stdc++.h>

const int maxn = 26;

// 字典树节点
struct Trie {
    // 指针数组指向下一层(这里代表26个字母)
    Trie *Next[maxn];
    // 统计
    int Cnt;
    // 初始化
    Trie() {
        for (int i = 0; i < maxn; ++i) {
            Next[i] = NULL;
        }
        Cnt = 0;
    }
};

// 根节点
Trie *Root;

// 插入字符串Str
void InsertTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - 'a';
        if (P -> Next[ID] == NULL) {
            P -> Next[ID] = new Trie;
        }
        P = P -> Next[ID];
        P -> Cnt++;
    }
}

// 查找以Str字符串为前缀的字符串数量
int FindTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - 'a';
        if (P -> Next[ID] == NULL) {
            return 0;
        }
        P = P -> Next[ID];
    }
    return P -> Cnt;
}

// 释放字典树
void DeleteTrie(Trie *Node) {
    if (Node == NULL) {
        return;
    }
    for (int i = 0; i < maxn; ++i) {
        if (Node -> Next[i] != NULL) {
            DeleteTrie(Node -> Next[i]);
        }
    }
    free(Node);
}

