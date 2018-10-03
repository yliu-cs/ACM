#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 26;

struct Trie {
    Trie *Next[maxn];
    int Cnt;
    Trie() {
        for (int i = 0; i < maxn; ++i) {
            Next[i] = NULL;
        }
        Cnt = 0;
    }
};

Trie *Root;

void InsertTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - '0';
        if (P -> Next[ID] == NULL) {
            P -> Next[ID] = new Trie;
        }
        P = P -> Next[ID];
        P -> Cnt++;
    }
}

int FindTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - '0';
        if (P -> Next[ID] == NULL) {
            return 0;
        }
        P = P -> Next[ID];
    }
    return P -> Cnt;
}

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

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        DeleteTrie(Root);
        Root = new Trie;
        char Str[maxn];
        bool Flag = 1;
        for (int i = 0; i < N; ++i) {
            scanf("%s", Str);
            if (FindTrie(Str) > 0) {
                Flag = 0;
            }
            if (!Flag) {
                continue;
            }
            InsertTrie(Str);
        }
        if (Flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

