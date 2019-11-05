#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	cout << 0 << " " << 1 << endl;
	string Basic;
	cin >> Basic;
	int Left = 0, Right = 1e9;
	for (int i = 1; i < N; ++i) {
		int Mid = (Left + Right) / 2;
		cout << Mid << " " << 1 << endl;
		string Color;
		cin >> Color;
		if (Color == Basic) {
			Left = Mid;
		}
		else {
			Right = Mid;
		}
	}
	cout << Left << " " << 2 << " " << Right << " " << 0 << endl;
    return 0;
}
