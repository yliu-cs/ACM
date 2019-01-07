#include<bits/stdc++.h>
using namespace std;

string Str;
int Len;
int Left, Right;
stack<char> S;

int main(int argc, char *argv[]) {
    cin >> Str;
    Len = (int)Str.length();
    Left = 0, Right = Len - 1;
    if (Len & 1) {
        S.push(Str[Left++]);
    }
    while (Left < Right) {
        S.push(Str[Right--]);
        if (Right < Left) {
            break;
        }
        S.push(Str[Left++]);
    }
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    cout << endl;
    return 0;
}

