#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    int N, S;
    scanf("%d%d", &N, &S);
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &H[i]);
    }
    sort(H.begin(), H.end());
    printf("%d\n", S * H[0]);
    return 0;
}
