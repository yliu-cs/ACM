#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = (int)(1e3 + 5);
const db eps = 1e-8;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);};
struct Point {db X, Y;};
typedef Point Vector;
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};};
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};};
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;};
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;};

bool Check(Vector Key1, Vector Key2, Vector Key3) {
    if (Sgn(Key1 ^ Key2) >= 0 && Sgn(Key2 ^ Key3) >= 0) return false;
    if (Sgn(Key1 ^ Key2) <= 0 && Sgn(Key2 ^ Key3) <= 0) return false;
    return true;
}

struct Interval {int Left, Right, Id;};
bool operator < (Interval &Key1, Interval &Key2) {return Key1.Left == Key2.Left ? Key1.Right > Key2.Right : Key1.Left < Key2.Left;}

int T;
int N, M;
Point Polygon[maxn];
Point Light[maxn];
int Tot;
Interval Section[maxn];
vector<int> Ans, Buffer;

void Divide() {
    Tot = 0;
    for (int i = 0; i < M; ++i) {
        int Left = 0;
        for (int j = 0; j < N; ++j)
            if (Sgn((Polygon[(j + 1) % N] - Polygon[j]) ^ (Polygon[j] - Light[i])) > 0 && Sgn((Polygon[j] - Polygon[(j - 1 + N) % N]) ^ (Polygon[(j - 1 + N) % N] - Light[i])) <= 0) Left = j;
        int Right = Left;
        while (Right <= N + Left) {
            if (Sgn((Polygon[(Right + 1) % N] - Polygon[Right % N]) ^ (Polygon[Right % N] - Light[i])) <= 0) break;
            Right++;
        }
        Section[Tot++] = (Interval){Left, Right, i};
    }
    sort(Section, Section + Tot);
}

void Select() {
    Ans.clear();
    for (int Start = 0; Start < Tot; ++Start) {
        Buffer.clear();
        int Cur = Start;
        Buffer.push_back(Section[Cur].Id);
        while (Section[Cur].Right < Section[Start].Left + N) {
            int Last = Section[Cur].Right;
            for (int j = Start + 1; j < Tot && Section[j].Left <= Last; ++j) {
                if (Section[j].Right > Section[Cur].Right) Cur = j;
            }
            if (Section[Cur].Right == Last) break;
            Buffer.push_back(Section[Cur].Id);
        }
        if (Section[Cur].Right >= Section[Start].Left + N && ((int)Ans.empty() || (int)Buffer.size() < (int)Ans.size())) Ans.assign(Buffer.begin(), Buffer.end());
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i) scanf("%lf%lf", &Polygon[i].X, &Polygon[i].Y);
        for (int i = 0; i < M; ++i) scanf("%lf%lf", &Light[i].X, &Light[i].Y);
        Divide();
        Select();
        if (Ans.empty()) printf("-1\n");
        else {
            printf("%d\n%d", (int)Ans.size(), Ans[0] + 1);
            for (int i = 1; i < (int)Ans.size(); ++i) {
                printf(" %d", Ans[i] + 1);
            }
            printf("\n");
        }
    }
    return 0;
}
