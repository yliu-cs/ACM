#include<bits/stdc++.h>
using namespace std;

int A;
int X, Y;
int Level;
int Judge;
int Cnt;

int main(int argc, char *argv[]) {
    scanf("%d%d%d", &A, &X, &Y);
    if (Y % A == 0) {
        printf("-1\n");
    }
    else if (Y < A) {
        if (abs(X) < A * 0.5) {
            printf("1\n");
        }
        else {
            printf("-1\n");
        }
    }
    else {
        Level = (Y - A) / (2 * A) + 1;
        Judge = (Y - A) % (2 * A);
        Cnt = 2 + (Level - 1) * 3;
        if (Judge < A) {
            if (abs(X) < A * 0.5) {
                printf("%d\n", Cnt);
            }
            else {
                printf("-1\n");
            }
        }
        else {
            if (abs(X) < A) {
                if (X == 0) {
                    printf("-1\n");
                }
                else if (X > 0) {
                    printf("%d\n", Cnt + 2);
                }
                else {
                    printf("%d\n", Cnt + 1);
                }
            }
            else {
                printf("-1\n");
            }
        }
    }
    return 0;
}

