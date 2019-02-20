#include <bits/stdc++.h>
using namespace std;

typedef double db;
const int maxn = 1e5 + 5;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);};
struct Point {db X, Y;};
typedef Point Vector;
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}
db GetLen(Vector Key) {return sqrt(Key * Key);}
db DisPointToPoint(Point Key1, Point Key2) {return sqrt((Key2 - Key1) * (Key2 - Key1));}

int N;
db X, Y;
Point Basic;
int M;
set<Point> S;
Point City[maxn];
bool Vis[maxn];
int Q;
vector<pair<int, int>> Query;
vector<db> Ans;
db Len;
int Op, K;

bool operator < (Point Key1, Point Key2) {
    Key1 = Key1 - Basic; Key2 = Key2 - Basic;
    db Ang1 = atan2(Key1.Y, Key1.X), Ang2 = atan2(Key2.Y, Key2.X);
    db Len1 = GetLen(Key1), Len2 = GetLen(Key2);
    if (Cmp(Ang1, Ang2) != 0) return Cmp(Ang1, Ang2) < 0;
    return Cmp(Len1, Len2) < 0;
}

set<Point>::iterator Prev(set<Point>::iterator Key) {
    if (Key == S.begin()) Key = S.end();
    return --Key;
}

set<Point>::iterator Next(set<Point>::iterator Key) {
    ++Key;
    return Key == S.end() ? S.begin() : Key;
}

bool Check(Point Key) {
    set<Point>::iterator it = S.lower_bound(Key);
    if (it == S.end()) it = S.begin();
    return Sgn((Key) - *(Prev(it)) ^ (*(it) - *(Prev(it)))) <= 0;
}

void Insert(Point Key) {
    if (Check(Key)) return;
    S.insert(Key);
    Len -= DisPointToPoint(*(Next(S.find(Key))), *(Prev(S.find(Key))));
    Len += DisPointToPoint(*(S.find(Key)), *(Next(S.find(Key)))) + DisPointToPoint(*(S.find(Key)), *(Prev(S.find(Key))));
    set<Point>::iterator Cur = Next(S.find(Key));
    while (S.size() > 3 && Sgn((Key - *(Next(Cur)) ^ (*(Cur) - *(Next(Cur))))) <= 0) {
        Len -= DisPointToPoint(*(Cur), *(Next(Cur))) + DisPointToPoint(*(Cur), *(Prev(Cur)));
        Len += DisPointToPoint(*(Next(Cur)), *(Prev(Cur)));
        S.erase(Cur);
        Cur = Next(S.find(Key));
    }
    Cur = Prev(S.find(Key));
    while (S.size() > 3 && Sgn((Key - *(Cur)) ^ (*(Cur) - *(Prev(Cur)))) >= 0) {
        Len -= DisPointToPoint(*(Cur), *(Next(Cur))) + DisPointToPoint(*(Cur), *(Prev(Cur)));
        Len += DisPointToPoint(*(Next(Cur)), *(Prev(Cur)));
        S.erase(Cur);
        Cur = Prev(S.find(Key));
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%lf%lf", &N, &X, &Y);
    Basic.X = ((db)N + X) / 3.0; Basic.Y = Y / 3.0;
    S.insert((Point){0.0, 0.0}); S.insert((Point){(db)N, 0.0}); S.insert((Point){X, Y});
    Len = GetLen((Vector){X, Y}) + DisPointToPoint((Point){(db)N, 0.0}, (Point){X, Y});
    scanf("%d", &M);
    for (int i = 1; i <= M; ++i) scanf("%lf%lf", &City[i].X, &City[i].Y);
    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i) {
        scanf("%d", &Op);
        if (Op == 1) {
            scanf("%d", &K);
            Query.push_back(make_pair(Op, K));
            Vis[K] = true;
        }
        Query.push_back(make_pair(Op, 0));
    }
    for (int i = 1; i <= M; ++i)
        if (!Vis[i])
            Insert(City[i]);
    reverse(Query.begin(), Query.end());
    for (auto &q : Query) {
        if (q.first == 1) Insert(City[q.second]);
        else if (q.first == 2) Ans.push_back(Len);
    }
    reverse(Ans.begin(), Ans.end());
    for (auto &it : Ans) printf("%.2lf\n", it);
    return 0;
}

