#include<bits/stdc++.h>
using namespace std;

long long N, K;

long long Data[31];
vector<long long> Ans;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 31; ++i) {
        Data[i] = (1 << i);
    }
    scanf("%lld%lld", &N, &K);
    if (K > N) {
        printf("NO\n");
        return 0;
    }
    else if (K == N) {
        printf("YES\n");
        for (int i = 1; i <= N; ++i) {
            printf("1 ");
        }
        printf("\n");
        return 0;
    }
    int Index = lower_bound(Data, Data + 31, N) - Data;
    Ans.clear();
    for (int i = Index; i >= 0; --i) {
        while (N - Data[i] >= K - 1 && K >= 1 && N > 0) {
            Ans.push_back(Data[i]);
            N -= Data[i];
            K--;
        }
        if (N == 0 || N < K || K == 0) {
            break;
        }
    }
    if (N == 0 && K == 0) {
        printf("YES\n");
        sort(Ans.begin(), Ans.end());
        for (auto i : Ans) {
            printf("%lld ", i);
        }
    }
    else {
        printf("NO");
    }
    printf("\n");
    return 0;
}

