#include <bits/stdc++.h>
using namespace std;

const int maxn = 26;

struct Trie {
    Trie *Next[maxn];
    int V;
};

Trie *Root;

void CreatTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root, *Q;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - '0';
        if (P -> Next[ID] == NULL) {
            Q = new Trie;
            Q -> V = 1;
            for (int j = 0; j < maxn; ++j) {
                Q -> Next[j] = NULL;
            }
            P -> Next[ID] = Q;
            P = P -> Next[ID];
        }
        else {
            P -> Next[ID] -> V++;
            P = P -> Next[ID];
        }
    }
    P -> V = -1;
}

bool FindTrie(char *Str) {
    int Len = strlen(Str);
    Trie *P = Root;
    for (int i = 0; i < Len; ++i) {
        int ID = Str[i] - '0';
        P = P -> Next[ID];
        if (P == NULL) {
            return true;
        }
        if (P -> V == -1) {
            return false;
        }
    }
    return false;
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
        bool Flag = 0;
        DeleteTrie(Root);
        Root = new Trie;
        for (int i = 0; i < maxn; ++i) {
            Root -> Next[i] = NULL;
        }
        scanf("%d", &N);
        char Str[maxn];
        for (int i = 0; i < N; ++i) {
            scanf("%s", Str);
            if (!FindTrie(Str)) {
                Flag = 1;
            }
            if (Flag) {
                continue;
            }
            CreatTrie(Str);
        }
        if (Flag) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    return 0;
}

