#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e1 + 5;

struct Point {int X, Y, Z;};

Point Cube;
Point Eye;
int Array[maxn];
int Ans;

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &Eye.X, &Eye.Y, &Eye.Z);
    scanf("%d%d%d", &Cube.X, &Cube.Y, &Cube.Z);
    for (int i = 1; i <= 6; ++i) scanf("%d", &Array[i]);
    if (Eye.X > Cube.X) Ans += Array[6];
    else if (Eye.X < 0) Ans += Array[5];
    if (Eye.Y > Cube.Y) Ans += Array[2];
    else if (Eye.Y < 0) Ans += Array[1];
    if (Eye.Z > Cube.Z) Ans += Array[4];
    else if (Eye.Z < 0) Ans += Array[3];
    printf("%d\n", Ans);
    return 0;
}

