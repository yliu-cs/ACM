#include <bits/stdc++.h>
using namespace std;

struct Status {
    long long Num;
    int Cnt;
};

long long N;
int Digit[25];
set<long long> Vis;

int Resolve(long long X) {
    memset(Digit, -1, sizeof(Digit));
    int Len = 0;
    while (X) {
        Digit[Len++] = X % 10;
        X /= 10;
    }
    return Len;
}

long long Cal(int Site, int Len) {
    swap(Digit[Site], Digit[Site + 1]);
    long long Ans = 0;
    while (Len) {
        Ans = Ans * 10 + Digit[--Len];
    }
    swap(Digit[Site], Digit[Site + 1]);
    return Ans;
}

int Bfs() {
    Vis.clear();
    queue<Status> Que;
    Que.push(Status {N, 0});
    Vis.insert(N);
    while (!Que.empty()) {
        Status Cur = Que.front(); Que.pop();
        if (Cur.Num % 25 == 0) {
            return Cur.Cnt;
        }
        int Len = Resolve(Cur.Num);
        for (int i = 0; i < Len - 1; ++i) {
            long long Ans = Cal(i, Len);
            if (Vis.find(Ans) == Vis.end()) {
                Que.push(Status {Ans, Cur.Cnt + 1});
                Vis.insert(Ans);
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    while (~scanf("%lld", &N)) {
        printf("%d\n", Bfs());
    }
    return 0;
}

