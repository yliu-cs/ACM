#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
#define maxn 16010

// 素数打表
bool Isprime[maxn];

void Prime() {
    Isprime[1] = 0;
    for (int i = 2;i <= maxn;i++) {
        if (Isprime[i]) {
            for (int j = i * i;j <= maxn;j += i) {
                if (Isprime[j]) {
                    Isprime[j] = 0;
                }
            }
        }
    }
    Isprime[2] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    mem(Isprime, 1);
    Prime();
    int n;
    int Book = 1;
    while (cin >> n) {
        if (n > 0) {
            cout << Book << ": ";
            Book++;
            if (Isprime[n]) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else {
            break;
        }
    }
    return 0;
}
