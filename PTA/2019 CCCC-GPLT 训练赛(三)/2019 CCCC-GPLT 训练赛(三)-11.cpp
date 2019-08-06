#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; getline(cin, s);
	set<char> vis; string ans;
	for (auto &it : s) {
		if (vis.find(it) == vis.end()) {
			ans += it;
			vis.insert(it);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans << endl;
  return 0;
}

