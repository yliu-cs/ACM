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
	string str;
	cin >> n >> k >> str;
	vector<int> cnt(26);
	for (auto s : str) {
		++cnt[s - 'a'];
	}
	int times = k;
	bool flag = 0;
	for (int i = 0; i < 26; ++i) {
		if (flag) {
			cnt[i] = 0;
			continue;
		}
		if (cnt[i] > times){
			cnt[i] = times;
			flag = 1;
		}
		else {
			times -= cnt[i];
		}
	}
	for (auto s : str) {
		if (cnt[s - 'a'] > 0) {
			--cnt[s - 'a'];
			continue;
		}
		else {
			cout << s;
		}
	}
	cout << endl;
    return 0;
}
