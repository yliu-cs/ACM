#include<bits/stdc++.h>
using namespace std;

char Input;
stack<char> S;
int Cnt;

int main(int argc, char *argv[]) {
    while (cin >> Input) {
        if (S.empty()) {
            S.push(Input);
        }
        else {
            if (Input == S.top()) {
                S.pop();
                Cnt++;
            }
            else {
                S.push(Input);
            }
        }
    }
    if (Cnt & 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

