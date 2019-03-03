#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    set<ll> id_data; map<ll, string> password_data;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        char op; ll id; string password; cin >> op >> id >> password;
        if (op == 'N') {
            if (id_data.find(id) == id_data.end()) {
                cout << "New: OK" << endl;
                id_data.insert(id); password_data[id] = password;
            }
            else cout << "ERROR: Exist" << endl;
        }
        else if (op == 'L') {
            if (id_data.find(id) == id_data.end()) cout << "ERROR: Not Exist" << endl;
            else {
                if (password_data[id] == password) cout << "Login: OK" << endl;
                else cout << "ERROR: Wrong PW" << endl;
            }
        }
    }
    return 0;
}

