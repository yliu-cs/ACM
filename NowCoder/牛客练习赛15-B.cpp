#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
 
struct ac {
    string name;
    string grade;
    int len;
    bool operator < (const ac &a) const {
        if (a.grade[0] != grade[0]) {
            return a.grade[0] > grade[0];
        }
        int sma = a.len < len ? a.len : len, cnt = 2;
        while (cnt < sma) {
            if (a.grade[cnt] != grade[cnt]) {
                return a.grade[cnt] > grade[cnt];
            }
            cnt++;
        }
        if (a.len != len) {
            return a.len > len;
        }
        return a.name < name;
    }
}people[maxn];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<ac> que;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> people[i].name >> people[i].grade;
        people[i].len = people[i].grade.length();
        for (int j = people[i].len - 1; j >= 0; --j) {
            if (people[i].grade[j] == '0') {
                people[i].len--;
            }
            else {
                break;
            }
        }
        que.push(people[i]);
    }
    for (int i = 0; i < n; ++i) {
        ac output;
        output = que.top();
        que.pop();
        cout << output.name << " " << output.grade << endl;
    }
    return 0;
}
