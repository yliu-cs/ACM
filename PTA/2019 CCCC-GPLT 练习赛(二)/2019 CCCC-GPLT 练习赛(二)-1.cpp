#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> array = {1, 2, 4, 6, 8, 9, 12, 15, 149, 156};
    int x; scanf("%d", &x);
    array.push_back(x);
    sort(array.begin(), array.end());
    for (auto &it : array) printf("%5d", it);
    return 0;
}

