#include <bits/stdc++.h>
using namespace std;

string S, T;

bool Check(char X) {
    if (X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u')
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    cin >> S >> T;
    if ((int)S.size() != (int)T.size()) {
        printf("No\n");
        return 0;
    }
    for (int i = 0; i < (int)S.size(); ++i) {
        if ((Check(S[i]) && !Check(T[i])) || (!Check(S[i]) && Check(T[i]))) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

