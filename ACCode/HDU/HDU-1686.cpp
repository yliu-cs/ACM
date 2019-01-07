#include <iostream>
#include <vector>
#include <string>
using namespace std;

void KMPPre(string Pattern, vector<int> &Next) {
    int i = 0, j = -1;
    Next[0] = -1;
    int Len = int(Pattern.length());
    while (i != Len) {
        if (j == -1 || Pattern[i] == Pattern[j]) {
            Next[++i] = ++j;
        }
        else {
            j = Next[j];
        }
    }
}

void PreKMP(string Pattern, vector<int> &Next) {
    int i, j;
    i = 0;
    j = Next[0] = -1;
    int Len = int(Pattern.length());
    while (i < Len) {
        while (j != -1 && Pattern[i] != Pattern[j]) {
            j = Next[j];
        }
        if (Pattern[++i] == Pattern[++j]) {
            Next[i] = Next[j];
        }
        else {
            Next[i] = j;
        }
    }
}

int KMPCount(string Pattern, string Main, vector<int> &Next) {
    //PreKMP(Pattern, Next);
    KMPPre(Pattern, Next);
    int PatternLen = int(Pattern.length()), MainLen = int(Main.length());
    int i = 0, j = 0;
    int Ans = 0;
    while (i < MainLen) {
        while (j != -1 && Main[i] != Pattern[j]) {
            j = Next[j];
        }
        i++; j++;
        if (j >= PatternLen) {
            Ans++;
            j = Next[j];
        }
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        string Main, Pattern;
        cin >> Pattern >> Main;
        vector<int> Next(int(Pattern.length()) + 1, 0);
        cout << KMPCount(Pattern, Main, Next) << endl;
    }
    return 0;
}
