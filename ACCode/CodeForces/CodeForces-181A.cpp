#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 5;

int N, M;
char Maze[maxn][maxn];
set<int> X, Y;

int main(int argc, char *argv[]) {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> Maze[i];
        for (int j = 0; j < M; ++j) {
            if (Maze[i][j] == '*') {
                if (X.find(i) != X.end()) {
                    X.erase(i);
                }
                else {
                    X.insert(i);
                }
                if (Y.find(j) != Y.end()) {
                    Y.erase(j);
                }
                else {
                    Y.insert(j);
                }
            }
        }
    }
    cout << *X.begin() + 1 << " " << *Y.begin() + 1 << endl;
    return 0;
}

