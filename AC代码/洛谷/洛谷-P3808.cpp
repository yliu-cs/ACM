#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

struct AhoCorasickAutomaton {
    // 子节点记录数组
    int Son[maxn][26];
    int Val[maxn];
    int Fail[maxn];
    int Tot;

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
};

int main(int argc, char *argv[]) {
    AhoCorasickAutomaton AC;
    AC.TrieInit();
    int N;
    cin >> N;
    string Str;
    for (int i = 0; i < N; ++i) {
        cin >> Str;
        AC.Insert(Str);
    }
    AC.GetFail();
    cin >> Str;
    cout << AC.Query(Str) << endl;
    return 0;
}
