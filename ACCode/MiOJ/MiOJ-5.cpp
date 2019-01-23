#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

char Str[maxn];
char Convert[maxn];
vector<int> Data;

void DealData() {
    Data.clear();
    int Len = strlen(Str);
    int Cur = 0, Pos = 0;
    while (Cur <= Len) {
        if (Str[Cur] == ',' || Cur == Len) {
            Convert[Pos] = '\0';
            int Temp;
            sscanf(Convert, "%d", &Temp);
            Data.push_back(Temp);
            Pos = 0;
            if (Cur == Len) {
                break;
            }
        }
        else {
            Convert[Pos++] = Str[Cur];
        }
        Cur++;
    }
}

int main(int argc, char *argv[]) {
    while (fgets(Str, maxn, stdin)) {
        if (Str[strlen(Str) - 1] == '\n') {
            Str[strlen(Str) - 1] = '\0';
        }
        DealData();
        sort(Data.begin(), Data.end());
        printf("%d\n", Data[(int)Data.size() / 2]);
    }
    return 0;
}