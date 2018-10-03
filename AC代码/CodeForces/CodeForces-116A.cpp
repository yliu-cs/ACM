#include <iostream>
using namespace std;
int main() {
    int n, res = 0, temp = 0;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        temp -= a;
        if (temp > res) {
            res = temp;
        }
        temp += b;
        if (temp > res) {
            res = temp;
        }
    }
    cout << res;
    return 0;
}