#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+6e1;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int n, k;
int p[maxn];
int input;
int temp;

int main() {
    //fre();
    scanf("%d%d", &n, &k);
    mem(p, -1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input);
        if (p[input] == -1) {
            temp = (input - k + 1) < 0 ? 0 : (input - k + 1);
            for (int j = temp; j <= input; ++j) {
                if (p[j] == -1 || p[j] == j) {
                    for (int l = j; l <= input; ++l) {
                        p[l] = j;
                    }
                    break;
                }
            }
        }
        printf("%d ", p[input]);
    }
    return 0;
}
