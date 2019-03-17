#include <bits/stdc++.h>
using namespace std;

int main() {
	string hex; char c;
	bool flag = false; int sgn = 1;
	while (cin >> c && c != '#') {
		c = tolower(c);
		if (flag) {
			if (isdigit(c) || (c >= 'a' && c <= 'f')) hex += c;
		}
		else {
			if (c == '-') sgn = -1;
			else if (isdigit(c) || (c >= 'a' && c <= 'f')) {
				flag = true;
				hex += c;
			}
		}
	}
	long long ans = 0;
	reverse(hex.begin(), hex.end());
	for (int i = 0; i < hex.size(); ++i) {
		if (isdigit(hex[i])) ans += 1ll * (hex[i] - '0') * pow(1ll * 16, i);
		else ans += 1ll * (hex[i] - 'a' + 10) * pow(1ll * 16, i);
	}
	cout << 1ll * ans * sgn << endl;
  return 0;
}

