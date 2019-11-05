#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int N;
pair<int, int> A[maxn];
ll Ans;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= 2 * N; ++i) {
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    sort(A + 1, A + 2 * N + 1, [&](pair<int, int> Key1, pair<int, int> Key2) {return Key1.first < Key2.first;});
    Ans += A[1].second + A[2].second - 2;
    for (int i = 3; i <= 2 * N; i += 2) Ans += min(abs(A[i].second - A[i - 1].second) + abs(A[i + 1].second - A[i - 2].second), abs(A[i].second - A[i - 2].second) + abs(A[i + 1].second - A[i - 1].second));
    printf("%lld\n", Ans);
    return 0;
}

