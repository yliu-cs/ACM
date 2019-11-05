#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {    
    vector<int> Length(3);
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &Length[i]);
    }
    sort(Length.begin(), Length.end());
    printf("%d\n", max(0, Length[2] - (Length[0] + Length[1]) + 1));
    return 0;
}
