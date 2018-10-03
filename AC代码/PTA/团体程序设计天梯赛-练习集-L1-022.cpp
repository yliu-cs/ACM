#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long num1 = 0, num2 = 0;
    while (n--) {
        long long a;
        cin >> a;
        if (a % 2 == 0) {
            num2++;
        }
        else {
            num1++;
        }
    }
    cout << num1 << " " << num2;
    return 0;
}
