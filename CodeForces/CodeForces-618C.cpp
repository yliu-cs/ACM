#include <bits/stdc++.h>
using namespace std;

typedef long double db;
const int maxn = 1e5 + 5;
const db eps = 1e-8;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
struct Point {db X, Y;};
typedef Point Vector;
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}
db operator ^ (Vector Key1, Vector Key2) {return Key1.X * Key2.Y - Key1.Y * Key2.X;}

int N;
pair<Point, int> Star[maxn];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%Lf%Lf", &Star[i].first.X, &Star[i].first.Y);
        Star[i].second = i;
    }
    sort(Star + 1, Star + N + 1, [&](pair<Point, int> Key1, pair<Point, int> Key2) {
        if (Sgn(Key1.first.X - Key2.first.X) == 0) return Sgn(Key1.first.Y - Key2.first.Y) < 0;
        return Sgn(Key1.first.X - Key2.first.X) < 0;
    });
    for (int i = 3; i <= N; ++i) {
        if (Sgn((Star[2].first - Star[1].first) ^ (Star[i].first - Star[2].first)) != 0) {
            printf("%d %d %d\n", Star[1].second, Star[2].second, Star[i].second);
            break;
        }
    }
    return 0;
}

