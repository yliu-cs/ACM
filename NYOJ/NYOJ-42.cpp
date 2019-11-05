#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;

int T;
int P, Q;
int Pre[maxn];
int Degree[maxn];

void Init() {
    for (int i = 1; i <= P; ++i) {
        Pre[i] = -1;
        Degree[i] = 0;
    }
}

int Find(int X) {
    int R = X;
    while (Pre[R] != -1) {
        R = Pre[R];
    }
    return R;
}

void Join(int U, int V) {
    int UU = Find(U), VV = Find(V);
    if (UU != VV) {
        Pre[UU] = VV;
    }
}

bool Check() {
    bool Flag = false;
    int Cnt = 0;
    for (int i = 1; i <= P; ++i) {
        if (Pre[i] == -1) {
            if (Flag) {
                return false;
            }
            else {
                Flag = true;
            }
        }
        if (Degree[i] & 1) {
            Cnt++;
        }
    }
    if (Cnt != 0 && Cnt != 2) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &P, &Q);
        Init();
        for (int i = 1, U, V; i <= Q; ++i) {
            scanf("%d%d", &U, &V);
            Degree[U]++; Degree[V]++;
            Join(U, V);
        }
        if (!Check()) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}

