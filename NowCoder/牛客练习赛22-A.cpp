#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 102;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}
 
int main() {
    //fre();
    int a[6];
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &a[i]);
    }
    int b[10];
    mem(b, 0);
    for (int i = 0; i < 6; ++i) {
        b[a[i]]++;
    }
    bool flag = 0;
    for (int i = 1; i <= 9; ++i) {
        if (b[i] == 4) {
            for (int j = 1; j <= 9; ++j) {
                if (j == i) {
                    continue;
                }
                if (b[j]) {
                    if (b[j] == 2) {
                        cout << "Elephant" << endl;
                    }
                    else {
                        cout << "Bear" << endl;
                    }
                    flag = 1;
                    break;
                }
            }
        }
        else if (b[i] == 5) {
            cout << "Bear" << endl;
            flag = 1;
        }
        else if (b[i] == 6) {
            cout << "Elephant" << endl;
            flag = 1;
        }
        if (flag) {
            break;
        }
    }
    if (!flag) {
        cout << "Hernia" << endl;
    }
    return 0;
}
