#include <bits/stdc++.h>
using namespace std;

string S;
vector<char> M[10];

int main(int argc, char *argv[]) {
    M[0].push_back('0'); M[0].push_back(' ');
    M[1].push_back('1'); M[1].push_back(','); M[1].push_back('.'); M[1].push_back('?'); M[1].push_back('!');
    M[2].push_back('2'); M[2].push_back('A'); M[2].push_back('B'); M[2].push_back('C');
    M[3].push_back('3'); M[3].push_back('D'); M[3].push_back('E'); M[3].push_back('F');
    M[4].push_back('4'); M[4].push_back('G'); M[4].push_back('H'); M[4].push_back('I');
    M[5].push_back('5'); M[5].push_back('J'); M[5].push_back('K'); M[5].push_back('L');
    M[6].push_back('6'); M[6].push_back('M'); M[6].push_back('N'); M[6].push_back('O');
    M[7].push_back('7'); M[7].push_back('P'); M[7].push_back('Q'); M[7].push_back('R'); M[7].push_back('S');
    M[8].push_back('8'); M[8].push_back('T'); M[8].push_back('U'); M[8].push_back('V');
    M[9].push_back('9'); M[9].push_back('W'); M[9].push_back('X'); M[9].push_back('Y'); M[9].push_back('Z');
    while (cin >> S) {
        int Pos = S[0] - '0', Cnt = S.size() % M[Pos].size() == 0 ? (M[Pos].size() - 1) : (S.size() % M[Pos].size() - 1);
        cout << Pos << " " << Cnt << endl;
        cout << M[Pos][Cnt];
    }
    return 0;
}

