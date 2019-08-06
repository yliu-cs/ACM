#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct Team {
    string Name;
    int P1Sub;
    int P1Time;
    int P2Sub;
    int P2Time;
    int P3Sub;
    int P3Time;
    int P4Sub;
    int P4Time;
    int Solve;
    int Time;
}q[100];

void GetInformation(int x) {
    for (int i = 0 ; i < x ; ++i) {
        cin >> q[i].Name >> q[i].P1Sub >> q[i].P1Time >> q[i].P2Sub >> q[i].P2Time >> q[i].P3Sub >> q[i].P3Time >> q[i].P4Sub >> q[i].P4Time;
        q[i].Solve = 0;
        q[i].Time = 0;
        if (q[i].P1Time != 0) {
            q[i].Solve++;
            q[i].Time += q[i].P1Time + (q[i].P1Sub - 1) * 20;
        }
        if (q[i].P2Time != 0) {
            q[i].Solve++;
            q[i].Time += q[i].P2Time + (q[i].P2Sub - 1) * 20;
        }
        if (q[i].P3Time != 0) {
            q[i].Solve++;
            q[i].Time += q[i].P3Time + (q[i].P3Sub - 1) * 20;
        }
        if (q[i].P4Time != 0) {
            q[i].Solve++;
            q[i].Time += q[i].P4Time + (q[i].P4Sub - 1) * 20;
        }
    }
}

bool cmp(Team A,Team B) {
    if (A.Solve == B.Solve) {
        return A.Time < B.Time;
    }
    return A.Solve > B.Solve;
}

int main() {
    int N;
    cin >> N;
    GetInformation(N);
    sort(q,q+N,cmp);
    cout << q[0].Name << " " << q[0].Solve << " " << q[0].Time;
    return 0;
}
