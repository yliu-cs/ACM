#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point {
    int X, Y;

    void Input() {
        scanf("%d%d", &X, &Y);
    }

    Point operator - (const Point &B) const {
        return Point {X - B.X, Y - B.Y};
    }
};

int N;
Point Gun;
Point Vector, X;
bool Flag;
set<pair<int, int> > Judge;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    Gun.Input();
    Flag = false;
    for (int i = 1; i <= N; ++i) {
        X.Input();
        Vector = Gun - X;
        int Gcd = __gcd(Vector.X, Vector.Y);
        Judge.insert(make_pair(Vector.X / Gcd, Vector.Y / Gcd));
    }
    printf("%d\n", (int)Judge.size());
    return 0;
}

