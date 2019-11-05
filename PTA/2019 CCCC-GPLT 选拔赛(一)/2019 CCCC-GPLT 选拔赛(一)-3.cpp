#include <bits/stdc++.h>
using namespace std;

string Str;
string Status;
int Ans;
bool XFlag; int XPos;
bool TFlag; int TPos;
bool CFlag; int CPos;

int main(int argc, char *argv[]) {
    cin >> Str;
    if (Str[0] == 'X') {
        XFlag = true;
        XPos = 0;
        Status += 'U';
    }
    else if (Str[0] == 'T') {
        Ans += 7;
        TFlag = true;
        TPos = 0;
        Status += 'D';
    }
    else {
        CFlag = true;
        CPos = 0;
        Ans -= 3;
        Status += '!';
    }
    for (int i = 1; Str[i] != '$'; ++i) {
        if (XFlag && i > XPos + 1) XFlag = false;
        if (TFlag && i > TPos + 2) TFlag = false;
        if (CFlag && i > CPos + 2) CFlag = false;
        if (!CFlag) {
            if ((XFlag && i <= XPos + 1) || (TFlag && i <= TPos + 2)) {
                Status += '-';
                continue;
            }
        }
        if (Str[i] == 'X') {
            XFlag = true;
            XPos = i;
            Status += 'U';
        }
        else if (Str[i] == 'T') {
            Ans += 7;
            TFlag = true;
            TPos = i;
            Status += 'D';
        }
        else if (Str[i] == 'C') {
            Ans -= 3;
            CFlag = true;
            CPos = i;
            Status += '!';
        }
    }
    cout << Status << endl << Ans << endl;
    return 0;
}

