#include <bits/stdc++.h>
using namespace std;

string Str;

int main(int argc, char *argv[]) {
    cin >> Str;
    for (int i = 0; i < Str.size(); ++i) {
        if (Str[i] == '.') cout << Str[i];
        else if (isdigit(Str[i])) {
            cout << Str[i];
            if (i != Str.size() - 1 && Str[i + 1] == '.') continue;
            if (i != Str.size() - 1 && !isdigit(Str[i + 1])) cout << endl;
        }
        else if (Str[i] == '(' || Str[i] == ')' || Str[i] == '*' || Str[i] == '/') {
            cout << Str[i] << endl;
        }
        else if (Str[i] == '+' || Str[i] == '-') {
            cout << Str[i];
            if (i && (Str[i - 1] == '*' || Str[i - 1] == '/' || Str[i - 1] == '+' || Str[i - 1] == '-')) continue;
            if (i != Str.size() - 1 && Str[i + 1] == '(') cout << endl;
            else if (i && (isdigit(Str[i - 1]) || Str[i - 1] == ')')) cout << endl;
        }
    }
    return 0;
}

