#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("C_IN.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

string str;

int check(char a, char b) {
    int Findex = -1, Sindex = -1;
    string Judge = str;
    int ans = 0;
    int ZeroCnt = 0;
    for (int i = Judge.size() - 1; i >= 0; --i) {
        if (Judge[i] == b && Sindex == -1) {
            Sindex = i + 1;
        }
        else if (Judge[i] == a &&Findex == -1) {
            Findex = i + 1;
        }
        if (Findex != -1 && Sindex != -1) {
            break;
        }
    }
    if (Findex == -1 || Sindex == -1) {
        return INF;
    }
    if (Findex > Sindex) {
        swap(Sindex, Findex);
        for (int i = Sindex - 1; i < Judge.size() - 1; ++i) {
            swap(Judge[i], Judge[i + 1]);
            ans++;
        }
        for (int i = Findex - 1; i < Judge.size() - 2; ++i) {
            swap(Judge[i], Judge[i + 1]);
            ans++;
        }
        swap(Judge[Judge.size() - 1], Judge[Judge.size() - 2]);
        ans++;
    }
    else {
        for (int i = Sindex - 1; i < Judge.size() - 1; ++i) {
            swap(Judge[i], Judge[i + 1]);
            ans++;
        }
        for (int i = Findex - 1; i < Judge.size() - 2; ++i) {
            swap(Judge[i], Judge[i + 1]);
            ans++;
        }
    }
    for (int i = 0; Judge[i] != '\0'; ++i) {
        if (Judge[i] == '0') {
            ZeroCnt++;
        }
        else {
            break;
        }
    }
    ans += ZeroCnt;
    return ans;
}

int main(){
    //fre();
    cin >> str;
    int ans = INF;
    ans = min(check('0', '0'), check('2', '5'));
    ans = min(ans, check('5', '0'));
    ans = min(ans, check('7', '5'));
    ans = ans == INF ? -1 : ans;
    printf("%d", ans);
    return 0;
}
