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
	int a, b, x;
	scanf("%d%d%d", &a, &b, &x);
	if (x % 2) {
		if (a > b) {
			for (int i = 0; i < x / 2; ++i) {
				cout << "01";
			}
			cout << string(a - x / 2, '0');
			cout << string(b - x / 2, '1');
		}
		else {
			for (int i = 0; i < x / 2; ++i) {
				cout << "10";
			}
			cout << string(b - x / 2, '1');
			cout << string(a - x / 2, '0');
		}
	}
	else {
		if (a > b) {
			for (int i = 0; i < x / 2; ++i) {
				cout << "01";
			}
			cout << string(b - x / 2, '1');
			cout << string(a - x / 2, '0');
		}
		else {
			for (int i = 0; i < x / 2; ++i) {
				cout << "10";
			}
			cout << string(a - x / 2, '0');
			cout << string(b - x / 2, '1');
		}
	}
	puts("\n");
    return 0;
}
