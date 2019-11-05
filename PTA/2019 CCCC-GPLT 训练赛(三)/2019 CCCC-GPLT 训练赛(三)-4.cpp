#include <bits/stdc++.h>
using namespace std;

int main() {
	struct student {
		int id;
		string name;
		int h, w;
	};
	int n; cin >> n;
	vector<student> s(n);
	for (auto &it : s) cin >> it.id >> it.name >> it.h >> it.w;
	sort(s.begin(), s.end(), [&](student k1, student k2) {
		if (k1.id == k2.id) return k1.h > k2.h;
		return k1.id < k2.id;
	});
	auto print = [](int k) {
		int cnt = 0, r = k;
		while (r) {
			cnt++;
			r /= 10;
		}
		for (int i = 0; i < 6 - cnt; ++i) cout << "0";
		cout << k;
	};
	int last = 0;
	print(s[0].id); cout << " " << s[0].name << " " << s[0].h << " " << s[0].w << endl;
	for (int i = 0; i < n; ++i) {
		if (s[i].id != s[last].id) {
			print(s[i].id); cout << " " << s[i].name << " " << s[i].h << " " << s[i].w << endl;
			last = i;
		}
	}
  return 0;
}

