#include <bits/stdc++.h>

void GetNext(std::string str, std::vector<int> &Next) {
    int i = 0, j = -1;
    Next[0] = -1;
    int len = int(str.length());
    while (i != len) {
        if (j == -1 || str[i] == str[j]) {
            Next[++i] = ++j;
        }
        else {
            j = Next[j];
        }
    }
}

int main(int argc, char *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::string str;
    std::cin >> str;
    int len = int(str.length());
    std::vector<int> Next(len + 1, 0);
    GetNext(str, Next);
    for (int i = 0; i < Next[len]; ++i) {
        std::cout << str[i];
    }
    for (int i = 1; i <= k; ++i) {
        for (int i = Next[len]; i < len; ++i) {
            std::cout << str[i];
        }
    }
    return 0;
}

