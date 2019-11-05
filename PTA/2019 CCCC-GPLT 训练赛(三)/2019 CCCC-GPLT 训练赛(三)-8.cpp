#include <bits/stdc++.h>
using namespace std;

int main() {
	char c; int n;
	cin >> c >> n;
	vector<vector<char>> matrix(n);
	int l = n / 2, r = n / 2, len = n / 2 + 1;
	for (int i = 0; i < n / 2; ++i) {
		matrix[i].assign(len++, ' ');
		matrix[i][l] = matrix[i][r] = c;
		c++; l--; r++;
	}
	for (int i = n / 2; i < n; ++i) {
		matrix[i].assign(len--, ' ');
		matrix[i][l] = matrix[i][r] = c;
		c--; l++; r--;
	}
	for (auto &i : matrix) {
		for (auto &j : i) {
			cout << j;
		}
		cout << endl;
	}
  return 0;
}

