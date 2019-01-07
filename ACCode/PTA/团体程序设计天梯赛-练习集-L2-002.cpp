#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

struct point {
    int address;
    int num;
};

int head_point_address;
int n;
int address[maxn][2];
set<int> vis;
vector<point> del;

int main() {
    mem(address, -1);
    cin >> head_point_address >> n;
    for (int i = 0; i < n; ++i) {
        int input_address, input_num, input_next_address;
        cin >> input_address >> input_num >> input_next_address;
        address[input_address][0] = input_num;
        address[input_address][1] = input_next_address;
    }
    int add_temp = head_point_address;
    printf("%05d %d ", add_temp, address[add_temp][0]);
    vis.insert(abs(address[add_temp][0]));
    add_temp = address[add_temp][1];
    while (add_temp != -1) {
        int judge_temp = abs(address[add_temp][0]);
        if (vis.count(judge_temp) != 0) {
            point add;
            add.address = add_temp;
            add.num = address[add_temp][0];
            del.push_back(add);
        }
        else {
            printf("%05d\n%05d %d ", add_temp, add_temp, address[add_temp][0]);
            vis.insert(judge_temp);
        }
        add_temp = address[add_temp][1];
    }
    cout << -1 << endl;
    if (del.size() != 0) {
        vector<point>::iterator it = del.begin();
        point show_start = *it;
        printf("%05d %d ", show_start.address, show_start.num);
        it++;
        for (; it != del.end(); ++it) {
            point show = *it;
            printf("%05d\n%05d %d ", show.address, show.address, show.num);
        }
        cout << -1;
    }
    return 0;
}

