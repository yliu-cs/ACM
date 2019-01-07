#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
 
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
 
int res[10010];
int n;
 
void Solve() {
    int Book = 1;
    int BaoFour = 0;
    res[Book] = 1;
    for (int i = 1;i <= n;++i) {
        BaoFour = 0;
        for (int j = 1;j <= Book;++j) {
            res[j] = res[j] * i + BaoFour;
            BaoFour = res[j] / 10000;
            res[j] = res[j] % 10000;
        }
        if (BaoFour > 0) {
            res[++Book] += BaoFour;
        }
    }
    cout << res[Book];
    for (int i = Book - 1;i > 0;--i) {
        if (res[i] >= 1000) {
            cout << res[i];
        }
        else if (res[i] >= 100) {
            printf("0%d",res[i]);
        }
        else if (res[i] >= 10) {
            printf("00%d",res[i]);
        }
        else {
            printf("000%d",res[i]);
        }
    }
    cout << endl;
}
 
int main() {
    while (cin >> n) {
        mem(res, 0);
        Solve();
    }
    return 0;
}
