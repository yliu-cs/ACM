#include <bits/stdc++.h>
using namespace std;

int N, M;
string Ans;
map<string, string> pre;

bool Find(string A, string B) {
    set<string> S;
    while (!A.empty()) {
        S.insert(A);
        A = pre[A];
    }
    while (!B.empty()) {
        if (S.find(B) != S.end()) {
            Ans = B;
            return true;
        }
        else {
            B = pre[B];
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    string Father, Son;
    for (int i = 0; i < N; ++i) {
        cin >> Father >> Son;
        pre[Son] = Father;
    }
    scanf("%d", &M);
    for (int Query = 1; Query <= M; ++Query) {
        string QueryName1, QueryName2;
        cin >> QueryName1 >> QueryName2;
        if (Find(QueryName1, QueryName2)) {
            cout << Ans << endl;
        }
        else {
            printf("%d\n", -1);
        }
    }
    return 0;
}

