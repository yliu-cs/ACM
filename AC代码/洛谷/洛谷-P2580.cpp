#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

bool Val[maxn];
int Son[maxn][26];
int Tot;

void TrieInit() {
    Tot = 0;
    memset(Son, 0, sizeof(Son));
    memset(Val, 0, sizeof(Val));
}

int Pos(char X) {
    return X - 'a';
}

void Insert(string Str) {
    int Cur = 0;
    for (int i = 0; i < int(Str.length()); ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            Son[Cur][Index] = ++Tot;
        }
        Cur = Son[Cur][Index];
    }
}

int Find(string Str) {
    int Cur = 0;
    for (int i = 0; i < int(Str.length()); ++i) {
        int Index = Pos(Str[i]);
        if (!Son[Cur][Index]) {
            return 0;
        }
        Cur = Son[Cur][Index];
    }
    if (!Val[Cur]) {
        Val[Cur] = 1;
        return 1;
    }
    else {
        return 2;
    }
}

int main(int argc, char *argv[]) {
    TrieInit();
    int N, M;
    string Name;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> Name;
        Insert(Name);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> Name;
        int Ans = Find(Name);
        if (Ans == 0) {
            cout << "WRONG" << endl;
        }
        else if (Ans == 1) {
            cout << "OK" << endl;
        }
        else if (Ans == 2) {
            cout << "REPEAT" << endl;
        }
    }
    return 0;
}
