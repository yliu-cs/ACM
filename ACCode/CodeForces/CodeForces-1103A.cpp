#include<bits/stdc++.h>
using namespace std;

char Shape;
bool Flag;
int Cnt;

int main(int argc, char *argv[]) {
    while (cin >> Shape) {
        if (Shape == '1') {
            if (Flag) {
                cout << "3 3" << endl;
                Flag ^= 1;
            }
            else {
                cout << "3 1" << endl;
                Flag ^= 1;
            }
        }
        else {
            cout << "1 " <<(Cnt++) % 4 + 1 << endl;
        }
    }
    return 0;
}

