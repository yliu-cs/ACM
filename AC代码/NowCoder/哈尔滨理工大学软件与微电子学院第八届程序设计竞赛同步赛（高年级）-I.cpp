#include <bits/stdc++.h>
using namespace std;
 
int N, M, K;
 
int main(int argc, char *argv[]) {
    while (~scanf("%d%d%d", &N, &M, &K)) {
        if ((N % (K + 1)) ^ (M % (K + 1))) {
            printf("HAI YOU SEI!\n");
        }
        else {
            printf("LAOZI CHUI SI NI!\n");
        }
    }
    return 0;
}
