#include <bits/stdc++.h>

const int maxn = "Edit";

// 子节点记录数组
int Son[maxn][26];
int Val[maxn];
// 失配指针Fail数组
int Fail[maxn];
// 节点数量
int Tot;

// Trie Tree初始化
void TrieInit() {
    Tot = 0;
    memset(Son, 0, sizeof(Son));
    memset(Val, 0, sizeof(Val));
    memset(Fail, 0, sizeof(Fail));
}

// 计算字母下标
int Pos(char X) {
    return X - 'a';
}

// 向Trie Tree中插入Str模式字符串
void Insert(string Str) {
    int Cur = 0, Len = int(Str.length());
    for (int i = 0; i < Len; ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            Son[Cur][Index] = ++Tot;
        }
        Cur = Son[Cur][Index];
    }
    Val[Cur]++;
}

// Bfs求得Trie Tree上失配指针
void GetFail() {
    queue<int> Que;
    for (int i = 0; i < 26; ++i) {
        if (Son[0][i]) {
            Fail[Son[0][1]] = 0;
            Que.push(Son[0][i]);
        }
    }
    while (!Que.empty()) {
        int Cur = Que.front(); Que.pop();
        for (int i = 0; i < 26; ++i) {
            if (Son[Cur][i]) {
                Fail[Son[Cur][i]] = Son[Fail[Cur]][i];
                Que.push(Son[Cur][i]);
            }
            else {
                Son[Cur][i] = Son[Fail[Cur]][i];
            }
        }
    }
}

// 询问Str中出现的模式串数量
int Query(string Str) {
    int Len = int(Str.length());
    int Cur = 0, Ans = 0;
    for (int i = 0; i < Len; ++i) {
        Cur = Son[Cur][Pos(Str[i])];
        for (int j = Cur; j && ~Val[j]; j = Fail[j]) {
            Ans += Val[j];
            Val[j] = -1;
        }
    }
    return Ans;
}
