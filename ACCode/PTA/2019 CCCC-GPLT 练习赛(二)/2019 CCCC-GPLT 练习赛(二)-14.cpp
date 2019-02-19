#include <bits/stdc++.h>
using namespace std;

vector<int> front(1 << 15, -1);

void Dfs(int root, vector<int> &back, vector<int> &mid) {
    if (back.empty()) return;
    else if (back.size() == 1) {
        front[root] = back[0];
        return;
    }
    front[root] = back.back();
    vector<int> midleft, midright;
    vector<int> backleft, backright;
    int cur = 0;
    for (; mid[cur] != front[root]; ++cur) midleft.push_back(mid[cur]);
    for (int i = 0; i < midleft.size(); ++i) backleft.push_back(back[i]);
    Dfs(root * 2 + 1, backleft, midleft);
    ++cur;
    for (; cur < mid.size(); ++cur) midright.push_back(mid[cur]);
    for (int i = back.size() - 2, k = 0; k < midright.size(); ++k, --i) backright.insert(backright.begin(), back[i]);
    Dfs(root * 2 + 2, backright, midright);
}

void Print(int root) {
    if (front[root] == -1) return;
    cout << " " << front[root];
    if (front[root * 2 + 1] != -1) Print(root * 2 + 1);
    if (front[root * 2 + 2] != -1) Print(root * 2 + 2);
}

int n;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<int> back(n), mid(n);
    for (auto &it : back) cin >> it;
    for (auto &it : mid) cin >> it;
    Dfs(0, back, mid);
    cout << "Preorder:";
    Print(0);
    return 0;
}
