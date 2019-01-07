#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        if (ch == EOF) {
            return;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    Finish_read = 1;
};

// 模拟
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, BlackGY, BlackGX;
    // while (~scanf("%d %d %d", &n, &BlackGY, &BlackGX) && n + BlackGY + BlackGX) {
    while (cin >> n >> BlackGY >> BlackGX) {
        if (!n && !BlackGY && !BlackGX) {
            break;
        }
        bool move[11][10];
        mem(move, 1);
        char pieces[11][10];
        mem(pieces, ' ');
        bool flag = 0;
        for (int i = 0; i < n; ++i) {
            char piece;
            int y, x;
            // scanf("%c %d %d", &piece, &y, &x);
            cin >> piece >> y >> x;
            pieces[y][x] = piece;
        }
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 9; ++j) {
                if (pieces[i][j] != ' ') {
                    // printf("pieces[%d][%d]=%c\n", i, j, pieces[i][j]);
                    if (pieces[i][j] == 'G' || pieces[i][j] == 'R') {
                        for (int k = i - 1; k > 0; --k) {
                            if (pieces[k][j] == ' ') {
                                move[k][j] = 0;
                            }
                            else {
                                move[k][j] = 0;
                                break;
                            }
                        }
                        for (int k = i + 1; k <= 10; ++k) {
                            if (pieces[k][j] == ' ') {
                                move[k][j] = 0;
                            }
                            else {
                                move[k][j] = 0;
                                break;
                            }
                        }
                        for (int k = j - 1; k > 0; --k) {
                            if (pieces[i][k] == ' ') {
                                move[i][k] = 0;
                            }
                            else {
                                move[i][k] = 0;
                                break;
                            }
                        }
                        for (int k = j + 1; k <= 9; ++k) {
                            if (pieces[i][k] == ' ') {
                                move[i][k] = 0;
                            }
                            else {
                                move[i][k] = 0;
                                break;
                            }
                        }
                    }
                    else if (pieces[i][j] == 'C') {
                        int cnt = 0;
                        for (int k = i - 1; k > 0; --k) {
                            if (pieces[k][j] == ' ') {
                                if (cnt) {
                                    move[k][j] = 0;
                                }
                            }
                            else {
                                if (!cnt) {
                                    cnt++;
                                }
                                else {
                                    move[k][j] = 0;
                                    break;
                                }
                            }
                        }
                        cnt = 0;
                        for (int k = i + 1; k <= 10; ++k) {
                            if (pieces[k][j] == ' ') {
                                if (cnt) {
                                    move[k][j] = 0;
                                }
                            }
                            else {
                                if (!cnt) {
                                    cnt++;
                                }
                                else {
                                    move[k][j] = 0;
                                    break;
                                }
                            }
                        }
                        cnt = 0;
                        for (int k = j - 1; k > 0; --k) {
                            if (pieces[i][k] == ' ') {
                                if (cnt) {
                                    move[i][k] = 0;
                                }
                            }
                            else {
                                if (!cnt) {
                                    cnt++;
                                }
                                else {
                                    move[i][k] = 0;
                                    break;
                                }
                            }
                        }
                        cnt = 0;
                        for (int k = j + 1; k <= 9; ++k) {
                            if (pieces[i][k] == ' ') {
                                if (cnt) {
                                    move[i][k] = 0;
                                }
                            }
                            else {
                                if (!cnt) {
                                    cnt++;
                                }
                                else {
                                    move[i][k] = 0;
                                    break;
                                }
                            }
                        }
                    }
                    else if (pieces[i][j] == 'H') {
                        if (i >= 3) {
                            if (pieces[i - 1][j] == ' ') {
                                if (j >= 2) {
                                    move[i - 2][j - 1] = 0;
                                }
                                if (j <= 8) {
                                    move[i - 2][j + 1] = 0;
                                }
                            }
                        }
                        if (j >= 3) {
                            if (pieces[i][j - 1] == ' ') {
                                if (i >= 2) {
                                    move[i - 1][j - 2] = 0;
                                }
                                if (i <= 9) {
                                    move[i + 1][j - 2] = 0;
                                }
                            }
                        }
                        if (i <= 8) {
                            if (pieces[i + 1][j] == ' ') {
                                if (j >= 2) {
                                    move[i + 2][j - 1] = 0;
                                }
                                if (j <= 8) {
                                    move[i + 2][j + 1] = 0;
                                }
                            }
                        }
                        if (j <= 7) {
                            if(pieces[i][j + 1] == ' ') {
                                if (i >= 2) {
                                    move[i - 1][j + 2] = 0;
                                }
                                if (i <= 9) {
                                    move[i + 1][j + 2] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (BlackGY == 1) {
            if (BlackGX == 4) {
                if (move[1][5] || move[2][4]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 5) {
                if (move[1][4] || move[1][6] || move[2][5]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 6) {
                if (move[1][5] || move[2][6]) {
                    flag = 1;
                }
            }
        }
        else if (BlackGY == 2) {
            if (BlackGX == 4) {
                if (move[1][4] || move[2][5] || move[3][4]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 5) {
                if (move[1][5] || move[2][4] || move[2][6] || move[3][5]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 6) {
                if (move[1][6] || move[2][5] || move[3][6]) {
                    flag = 1;
                }
            }
        }
        else if (BlackGY == 3) {
            if (BlackGX == 4) {
                if (move[2][4] || move[3][5]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 5) {
                if (move[3][4] || move[2][5] || move[3][6]) {
                    flag = 1;
                }
            }
            else if (BlackGX == 6) {
                if (move[3][5] || move[2][6]) {
                    flag = 1;
                }
            }
        }
        bool ok = 1;
        for (int i = BlackGY + 1; i <= 10; ++i) {
            if (pieces[i][BlackGX] != ' ') {
                if (pieces[i][BlackGX] == 'G' && ok) {
                    flag = 1;
                }
                break;
            }
        }
        if (flag) {
            // printf("NO\n");
            cout << "NO" << endl;
        }
        else {
            // printf("YES\n");
            cout << "YES" << endl;
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
