#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 5;

int N, K;
int Tot;
int A[maxn], Ans[maxn];
map<int, int> Index;
int Book;
vector<int> Pos[maxn];

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &K);
    Tot = 1;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if (!Index[A[i]]) {
            Index[A[i]] = Tot++;
        }
        Pos[Index[A[i]]].push_back(i);
    }
    for (int i = 1; i < Tot; ++i) {
        if ((int)Pos[i].size() > K) {
            printf("NO\n");
            return 0;
        }
        for (int j = 0; j < (int)Pos[i].size(); ++j) {
            Ans[Pos[i][j]] = Book;
            Book = (Book + 1) % K;
        }
    }
    printf("YES\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", Ans[i] + 1);
    }
    return 0;
}
