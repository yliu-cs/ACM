#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 20;
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
	scanf("%d", &n);
	string t;
	cin >> t;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			reverse(t.begin(), t.begin() + i);
		}
	}
	cout << t << endl;
    return 0;
}
