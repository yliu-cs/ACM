#include <bits/stdc++.h>
using namespace std;

struct Point {int X, Y;};
typedef Point Vector;
bool operator == (Point Key1, Point Key2) {return Key1.X == Key2.X && Key1.Y == Key2.Y;}
Vector operator - (Vector Key1, Vector Key2) {return (Vector){Key1.X - Key2.X, Key1.Y - Key2.Y};}
Vector operator + (Vector Key1, Vector Key2) {return (Vector){Key1.X + Key2.X, Key1.Y + Key2.Y};}
int operator * (Vector Key1, Vector Key2) {return Key1.X * Key2.X + Key1.Y * Key2.Y;}

Point A, B, C;

bool Check() {
    if ((B - A) * (C - A) == 0) return true;
    if ((A - B) * (C - B) == 0) return true;
    if ((A - C) * (B - C) == 0) return true;
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d%d%d%d%d%d", &A.X, &A.Y, &B.X, &B.Y, &C.X, &C.Y);
    if (Check()) {
        printf("RIGHT\n");
        return 0;
    }
    for (int i = -1; i < 2; ++i) {
        if (!i) continue;
        A.X += i;
        if (A == B || A == C) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        A.X -= i;
        A.Y += i;
        if (A == B || A == C) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        A.Y -= i;
    }
    for (int i = -1; i < 2; ++i) {
        if (!i) continue;
        B.X += i;
        if (B == A || B == C) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        B.X -= i;
        B.Y += i;
        if (B == A || B == C) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        B.Y -= i;
    }
    for (int i = -1; i < 2; ++i) {
        if (!i) continue;
        C.X += i;
        if (C == A || C == B) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        C.X -= i;
        C.Y += i;
        if (C == A || C == B) ;
        else if (Check()) {
            printf("ALMOST\n");
            return 0;
        }
        C.Y -= i;
    }
    printf("NEITHER\n");
    return 0;
}

