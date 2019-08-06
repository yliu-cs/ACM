#include<bits/stdc++.h>
using namespace std;

int Length[4];

int main(int argc, char *argv[]) {
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &Length[i]);
    }
    sort(Length, Length + 4);
    if (Length[0] + Length[1] > Length[2] || Length[1] + Length[2] > Length[3]) {
        printf("TRIANGLE\n");
    }
    else if (Length[0] + Length[1] == Length[2] || Length[1] + Length[2] == Length[3]) {
        printf("SEGMENT\n");
    }
    else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}

