#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

struct Point {
    long long X, Y;
};

Point operator - (Point Key1, Point Key2) {
    return (Point){Key1.X - Key2.X, Key1.Y - Key2.Y};
}

long long operator ^ (Point Key1, Point Key2) {
    return Key1.X * Key2.Y - Key1.Y * Key2.X;
}

struct Interval {
    int Left, Right, Id;
};

int T;
int N, M;
Point Polygon[maxn];
Point Light[maxn];
int Tot;
Interval Section[maxn];
vector<int> Ans, Buffer;

bool Check(Point Key1, Point Key2, Point Key3) {
    if ((Key1 ^ Key2) >= 0 && (Key2 ^ Key3) >= 0) {
        return false;
    }
    if ((Key1 ^ Key2) <= 0 && (Key2 ^ Key3) <= 0) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i) {
            scanf("%lld%lld", &Polygon[i].X, &Polygon[i].Y);
        }
        for (int i = 0; i < M; ++i) {
            scanf("%lld%lld", &Light[i].X, &Light[i].Y);
        }
        Tot = 0;
        for (int i = 0; i < M; ++i) {
            int Low = 0;
            for (int j = 0; j < N; ++j) {
                if (((Polygon[j] - Light[i]) ^ (Polygon[Low] - Light[i])) >= 0) {
                    Low = j;
                }
            }
            if (Check(Polygon[(Low - 1 + N) % N] - Polygon[Low], Polygon[(Low + 1) % N] - Polygon[Low], Light[i] - Polygon[Low])) {
                for (int j = (Low - 2 + N) % N; ; j = (j - 1 + N) % N) {
                    if (Check(Polygon[j] - Light[i], Polygon[(j + 1) % N] - Light[i], Polygon[(j + 2) % N] - Light[i])) {
                        if ((j + 1) % N <= Low) {
                            Section[Tot++] = (Interval){(j + 1) % N, Low, i};
                        }
                        else {
                            Section[Tot++] = (Interval){(j + 1) % N, Low + N, i};
                        }
                        break;
                    }
                }
            }
            else {
                for (int j = (Low + 2) % N; ; j = (j + 1) % N) {
                    if (Check(Polygon[j] - Light[i], Polygon[(j - 1 + N) % N] - Light[i], Polygon[(j - 2 + N) % N] - Light[i])) {
                        if ((j - 1 + N) % N <= Low) {
                            Section[Tot++] = (Interval){(j - 1 + N) % N, Low, i};
                        }
                        else {
                            Section[Tot++] = (Interval){Low, (j - 1 + N) % N, i};
                        }
                        break;
                    }
                }
            }
        }
        sort(Section, Section + Tot, [&](Interval Key1, Interval Key2) {
            if (Key1.Left == Key2.Left) {
                return Key1.Right > Key2.Right;
            }
            return Key1.Left < Key2.Left;
        });
        Ans.clear();
        for (int i = 0; i < Tot; ++i) {
            Buffer.clear();
            int Cur = i;
            Buffer.push_back(Section[i].Id);
            while (Section[Cur].Right < Section[i].Left + N) {
                int R = Section[Cur].Right;
                for (int j = i + 1; j < Tot && Section[j].Left <= R; ++j) {
                    if (Section[j].Right > Section[Cur].Right) {
                        Cur = j;
                    }
                }
                if (Section[Cur].Right == R) {
                    break;
                }
                Buffer.push_back(Section[Cur].Id);
            }
            if (Section[Cur].Right >= Section[i].Left + N && ((int)Ans.size() == 0 || (int)Buffer.size() < (int)Ans.size())) {
                Ans.assign(Buffer.begin(), Buffer.end());
            }
        }
        if (Ans.empty()) {
            printf("-1");
        }
        else {
            printf("%d\n%d", (int)Ans.size(), Ans[0] + 1);
            for (int i = 1; i < (int)Ans.size(); ++i) {
                printf(" %d", Ans[i] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}

