#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;

vector<char> DNA = {'A', 'T', 'G', 'C'};

int T;
int N;
string Ans;
string Str[maxn];

void Dfs(string Cur) {
    if (Cur.size() > Ans.size()) Ans = Cur;
    for (int i = 0; i < 4; ++i) {
        string Temp = Cur + DNA[i];
        bool Flag = true;
        for (int j = 0; j < N; ++j) {
            if (Str[j].find(Temp) == string::npos) {
                Flag = false;
                break;
            }
        }
        if (Flag) Dfs(Cur + DNA[i]);
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        Ans = "";
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> Str[i];
        Dfs("");
        if (Ans.size() < 3) cout << "no significant commonalities" << endl;
        else cout << Ans << endl;
    }
    return 0;
}

