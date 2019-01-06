#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string n;
    cin >> n;
    if (int(n[int(n.length()) - 1] - '0') & 1) {
        printf("-1\n");
    }
    else {
        printf("1");
    }
    return 0;
}

