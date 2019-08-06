#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    sort(a.begin(), a.end());
    deque<int> Deq;
    bool Flag = true;
    for (auto &it : a) {
        if (Flag) Deq.push_back(it);
        else Deq.push_front(it);
        Flag = !Flag;
    }
    for (auto &it : Deq) cout << it << " ";
    return 0;
}

