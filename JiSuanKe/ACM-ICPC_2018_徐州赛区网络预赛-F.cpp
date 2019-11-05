#include <bits/stdc++.h>
using namespace std;

struct Vector {
    long long X, Y;
    bool operator == (const Vector &A) const {
        return A.X == X && A.Y == Y;
    }
};

struct Hash {
    size_t operator() (const Vector &A) const {
        return hash<long long>()(A.X) + hash<long long>()(A.Y);
    }
};

unordered_map<Vector, long long, Hash> mp[3];

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for (int Case = 1, N; Case <= T; ++Case) {
        scanf("%d", &N);
        long long Ans = -1;
        for (long long i = 0, K; i < N; ++i) {
            scanf("%lld", &K);
            if (i == 0) {
                mp[1].clear();
                for (long long j = 0, X, Y; j < K; ++j) {
                    scanf("%lld%lld", &X, &Y);
                    mp[1].emplace(Vector{X, Y}, 1);
                }
                Ans = 1;
            }
            else if (i & 1) {
                mp[2].clear();
                for (long long j = 0, X, Y; j < K; ++j) {
                    scanf("%lld%lld", &X, &Y);
                    if (mp[1].find(Vector{X, Y}) != mp[1].end()) {
                        long long Temp = mp[1][Vector{X, Y}] + 1;
                        mp[2].emplace(Vector{X, Y}, Temp);
                        Ans = max(Ans, Temp);
                    }
                    else {
                        mp[2].emplace(Vector{X, Y}, 1);
                    }
                }
            }
            else {
                mp[1].clear();
                for (long long j = 0, X, Y; j < K; ++j) {
                    scanf("%lld%lld", &X, &Y);
                    if (mp[2].find(Vector{X, Y}) != mp[2].end()) {
                        long long Temp = mp[2][Vector{X, Y}] + 1;
                        mp[1].emplace(Vector{X, Y}, Temp);
                        Ans = max(Ans, Temp);
                    }
                    else {
                        mp[1].emplace(Vector{X, Y}, 1);
                    }
                }
            }
        }
        printf("%lld\n", Ans);
    }
    return 0;
}

