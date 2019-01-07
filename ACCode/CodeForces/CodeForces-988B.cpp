#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

bool cmp(string a, string b) {
    return a.length() < b.length();
}

int main(){
    //fre();
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    sort(str.begin(), str.end(), cmp);
    for (int i = 0; i < n - 1; ++i) {
        if (str[i + 1].find(str[i]) == string::npos) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (auto it : str) {
        cout << it << endl;
    }
    return 0;
}
