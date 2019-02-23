#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn = 1e2 + 5;
const db inf = 1e20;
const db eps = 1e-9;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}
struct Point {db X, Y, Z;};
typedef Point Vector;
struct Ray {Point Origin; Vector Dir;};
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y, Key1.Z - Key2.Z};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y, Key1.Z + Key2.Z};}
db operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y + Key1.Z * Key2.Z;}
db GetLen(Vector Key) {return sqrt(Key * Key);}
db GetLen2(Vector Key) {return Key * Key;}
db operator ^ (Vector Key1, Vector Key2) {return GetLen((Vector){Key1.Y * Key2.Z - Key1.Z * Key2.Y, Key1.Z * Key2.X - Key1.X * Key2.Z, Key1.X * Key2.Y - Key1.Y * Key2.X});}
Vector operator * (Vector Key1, db Key2) {return (Vector){Key1.X * Key2, Key1.Y * Key2, Key1.Z * Key2};}
Vector operator / (Vector Key1, db Key2) {return (Vector){Key1.X / Key2, Key1.Y / Key2, Key1.Z / Key2};}
db DisPointToPoiont(Point Key1, Point Key2) {return GetLen(Key2 - Key1);}
struct Sphere {Point Center; db Radius;};

bool IsRayInterSphere(Ray Key1, Sphere Key2, db &Dis) {
    db A = Key1.Dir * Key1.Dir;
    db B = (Key1.Origin - Key2.Center) * Key1.Dir * 2.0;
    db C = ((Key1.Origin - Key2.Center) * (Key1.Origin - Key2.Center)) - (Key2.Radius * Key2.Radius);
    db Delta = B * B - 4.0 * A * C;
    if (Sgn(Delta) < 0) return false;
    db X1 = (-B - sqrt(Delta)) / (2.0 * A), X2 = (-B + sqrt(Delta)) / (2.0 * A);
    if (Cmp(X1, X2) > 0) swap(X1, X2);
    if (Sgn(X1) <= 0) return false;
    Dis = X1;
    return true;
}

void Reflect(Ray &Key1, Sphere Key2, db Dis) {
    Point Pos = Key1.Origin + (Key1.Dir * Dis);
    Vector Temp = Key2.Center + (((Pos - Key2.Center) * ((Pos - Key2.Center) * (Key1.Origin - Key2.Center))) / GetLen2(Pos - Key2.Center));
    Key1.Dir = Temp * 2.0 - Key1.Origin - Pos; Key1.Origin = Pos;
}

int N;
Sphere spheres[maxn];
Ray Cur;
int Last;

int Solve() {
    db MinDis = inf; int Ans = -1;
    for (int i = 1; i <= N; ++i) {
        db Dis = inf;
        if (i == Last) continue;
        if (!IsRayInterSphere(Cur, spheres[i], Dis)) continue;
        if (Cmp(Dis, MinDis) < 0) {
            Ans = i;
            MinDis = Dis;
        }
    }
    if (Ans == -1) return -1;
    Last = Ans;
    Reflect(Cur, spheres[Ans], MinDis);
    return Ans;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%lf%lf%lf%lf", &spheres[i].Center.X, &spheres[i].Center.Y, &spheres[i].Center.Z, &spheres[i].Radius);
    scanf("%lf%lf%lf", &Cur.Origin.X, &Cur.Origin.Y, &Cur.Origin.Z);
    scanf("%lf%lf%lf", &Cur.Dir.X, &Cur.Dir.Y, &Cur.Dir.Z);
    Cur.Dir = Cur.Dir - Cur.Origin;
    for (int i = 0, Ans; i < 11; ++i) {
        Ans = Solve();
        if (Ans == -1) break;
        else if (i == 10) printf("etc.");
        else printf("%d ", Ans);
    }
    printf("\n");
    return 0;
}