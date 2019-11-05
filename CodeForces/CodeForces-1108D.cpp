#include <bits/stdc++.h>
using namespace std;

int N;
char Str[200010];
int Cnt;

void Solve(int Left, int Right) {
    int Len = Right - Left + 1;
    if (Len < 2) {
        return;
    }
    if (Len & 1) {
        for (int i = Left + 1; i < Right; i += 2) {
            if (Str[i] == 'R') {
                Str[i] = 'G';
            }
            else if (Str[i] == 'G') {
                Str[i] = 'B';
            }
            else {
                Str[i] = 'R';
            }
            Cnt++;
        }
        return;
    }
    if (Left == 1) {
        for (int i = Left; i < Right; i += 2) {
            if (Str[i] == 'R') {
                Str[i] = 'G';
            }
            else if (Str[i] == 'G') {
                Str[i] = 'B';
            }
            else {
                Str[i] = 'R';
            }
            Cnt++;
        }
    }
    else if (Right == N) {
        for (int i = Right; i > Left; i -= 2) {
            if (Str[i] == 'R') {
                Str[i] = 'G';
            }
            else if (Str[i] == 'G') {
                Str[i] = 'B';
            }
            else {
                Str[i] = 'R';
            }
            Cnt++;
        }
    }
    else {
        if (Str[Left] == 'R') {
            if (Str[Left - 1] == 'G') {
                Str[Left] = 'B';
            }
            else if (Str[Left - 1] == 'B') {
                Str[Left] = 'G';
            }
        }
        else if (Str[Left] == 'G') {
            if (Str[Left - 1] == 'R') {
                Str[Left] = 'B';
            }
            else if (Str[Left - 1] == 'B') {
                Str[Left] = 'R';
            }
        }
        else {
            if (Str[Left - 1] == 'R') {
                Str[Left] = 'G';
            }
            else if (Str[Left - 1] == 'G') {
                Str[Left] = 'R';
            }
        }
        Cnt++;
        Solve(Left + 1, Right);
    }
}

int Left, Right;
vector<pair<int, int> > Interval;

int main(int argc, char *argv[]) {
    scanf("%d%s", &N, Str + 1);
    Left = 1; Right = 1;
    for (int i = 2; i <= N; ++i) {
        if (Str[i] != Str[Right]) {
            if (Right != Left) {
                Interval.push_back(make_pair(Left, Right));
            }
            Left = i; Right = i;
        }
        else {
            Right++;
        }
        if (i == N && Right != Left) {
            Interval.push_back(make_pair(Left, Right));
        }
    }
    for (auto it : Interval) {
        Solve(it.first, it.second);
    }
    printf("%d\n%s\n", Cnt, Str + 1);
    return 0;
}
