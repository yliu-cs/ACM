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
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0;
	vector<int> a(n);
	int _left = -1, _right = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > k) {
			if (_left == -1) {
				_left = i;
			}
			else {
				_right = n - 1 - i;
			}
		}
	}
	if (_left == -1 && _right == -1) {
		ans = n;
	}
	else if(_left != -1 && _right == -1) {
		ans = n - 1;
	}
	else {
		ans += _left + _right;
	}
	printf("%d\n", ans);
    return 0;
}
