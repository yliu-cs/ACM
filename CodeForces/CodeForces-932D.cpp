#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int maxn = 4e5 + 5;

int Cnt;
long long Weight[maxn];
long long Sum[maxn][25];
int Pre[maxn][25];

// 添加树边
void AddEdge(int U, int Value) {
    // 新添加节点的权值
    Weight[++Cnt] = Value;
    // 若新添加节点权值小于其父节点权值则说明在询问时此路可走，将其父节点添加至其前驱节点中
    if (Weight[Cnt] <= Weight[U]) {
        Pre[Cnt][0] = U;
    }
    else {
        // 否则继续向上遍历
        for (int i = 20; i >= 0; --i) { 
            if (Weight[Pre[U][i]] < Weight[Cnt]) {
                U = Pre[U][i];
            }
        }
        Pre[Cnt][0] = Pre[U][0];
    }
    // 若无权值比其小的前驱节点，设置从Cnt点跳1个点的权值和为正无穷
    if (Pre[Cnt][0] == 0) {
        Sum[Cnt][0] = INF;
    }
    // 否则从Cnt点跳1个点的权值和等于其前驱节点权值
    else {
        Sum[Cnt][0] = Weight[Pre[Cnt][0]];
    }
    for (int i = 1; i <= 20; ++i) {
        Pre[Cnt][i] = Pre[Pre[Cnt][i - 1]][i - 1];
        if (Pre[Cnt][i] == 0) {
            Sum[Cnt][i] = INF;
        }
        else {
            Sum[Cnt][i] = Sum[Cnt][i - 1] + Sum[Pre[Cnt][i - 1]][i - 1];
        }
    }
}

// 询问从U开始向上走权值大于其的节点的不大于Value的权值和最大的点数
long long Query(int U, long long Value) {
    // 若权值大于Value则返回
    if (Weight[U] > Value) {
        return 0;
    }
    // Value减自身节点权值
    Value -= Weight[U];
    long long Ans = 1;
    for (int i = 20; i >= 0; --i) {
        // 倍增向上走，结果计数
        if (Value >= Sum[U][i]) {
            Value -= Sum[U][i];
            Ans += (1 << i);
            U = Pre[U][i];
        }
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    Weight[0] = INF;
    Weight[1] = 0;
    long long Last = 0;
    Cnt = 1;
    memset(Sum[1], 0x3f, sizeof(Sum[1]));
    int T;
    scanf("%d", &T);
    for (long long Case = 1, Operate, P, Q; Case <= T; ++Case) {
        scanf("%lld%lld%lld", &Operate, &P, &Q);
        P ^= Last;
        Q ^= Last;
        if (Operate == 1) {
            AddEdge(P, Q);
        }
        else if (Operate == 2) {
            Last = Query(P, Q);
            printf("%lld\n", Last);
        }
    }
    return 0;
}

