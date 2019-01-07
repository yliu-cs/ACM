#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2600;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main(){
    //fre();
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string str;
        getline(cin, str);
        int a[5];
        mem(a, 0);
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == 'a') {
                a[0]++;
            }
            else if (str[i] == 'e') {
                a[1]++;
            }
            else if (str[i] == 'i') {
                a[2]++;
            }
            else if (str[i] == 'o') {
                a[3]++;
            }
            else if (str[i] == 'u') {
                a[4]++;
            }
        }
        printf("a:%d\n", a[0]);
        printf("e:%d\n", a[1]);
        printf("i:%d\n", a[2]);
        printf("o:%d\n", a[3]);
        printf("u:%d\n", a[4]);
        if (n) {
            printf("\n");
        }
    }
    return 0;
}
