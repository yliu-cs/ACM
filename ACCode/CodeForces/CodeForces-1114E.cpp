#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    int query = 60, last;
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = (left + right) >> 1;
        cout << "> " << mid << endl;
        cout << flush;
        query--;
        int x; cin >> x;
        if (x) left = mid + 1;
        else {
            last = mid;
            right = mid - 1;
        }
    }
    mt19937 mt(time(NULL));
    int d = 0;
    while (query--) {
        cout << "? " << mt() % n + 1 << endl;
        cout << flush;
        int x; cin >> x;
        d = __gcd(d, last - x);
    }
    cout << "! " << last - (n - 1) * d << " " << d << endl;
    cout << flush;
    return 0;
}

