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
#define maxn 20050

bool IsPrime[maxn];

// 素数打表
void Work() {
    mem(IsPrime, 1);
    for (int i = 2;i < maxn;++i) {
        if (IsPrime[i]) {
            for (int j = i * i;j < maxn;j += i) {
                IsPrime[j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    Work();
    int N;
    while (cin >> N) {
        int *Num,*Big;
        Num = new int[N];
        Big = new int[N];
        for (int k = 0;k < N;++k) {
            cin >> Num[k];
            if (IsPrime[Num[k]]) {
                Big[k] = Num[k];
            }
            else {
                for (int i = Num[k] - 1;i >= 1;--i) {
                    if (Num[k] % i == 0 && IsPrime[i] == 1) {
                        Big[k] = i;
                        break;
                    }
                }
            }
        }
        int res,Bigest = -1;
        for (int i = 0;i < N;++i) {
            if (Big[i] > Bigest) {
                Bigest = Big[i];
                res = Num[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}
