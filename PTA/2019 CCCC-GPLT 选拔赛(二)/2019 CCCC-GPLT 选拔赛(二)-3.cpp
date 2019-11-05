#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-4;

int Sgn(db Key) {return fabs(Key) < eps ? 0 : (Key < 0 ? -1 : 1);}
int Cmp(db Key1, db Key2) {return Sgn(Key1 - Key2);}

db A3, A2, A1, A0;
db Function(db X) {return A3 * X * X * X + A2 * X * X + A1 * X + A0;}

db Left, Right;
bool Flag;

int main(int argc, char *argv[]) {
    scanf("%lf%lf%lf%lf", &A3, &A2, &A1, &A0);
    scanf("%lf%lf", &Left, &Right);
    if (Cmp(Function(Left), (db)0.0) > 0) Flag = true;
    else Flag = false;
    while (Cmp(Left, Right)) {
        db Mid = (Left + Right) / 2.0;
        db Res = Function(Mid);
        if (Flag) {
            if (Cmp(Res, (db)0.0) > 0) Left = Mid;
            else Right = Mid;
        }
        else {
            if (Cmp(Res, (db)0.0) > 0) Right = Mid;
            else Left = Mid;
        }
    }
    printf("%.2lf\n", Left);
    return 0;
}

