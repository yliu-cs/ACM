#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

struct inf {
    int Rank;
    string TeamName;
    int Problem;
    string Statu;
    bool Flag;
    int During;
}Submit[maxn];

int t;

// 结构体排序，模拟

int main(){
    //fre();
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        Submit[i].Flag = 0;
        cin >> Submit[i].Rank >> Submit[i].TeamName >> Submit[i].Problem >> Submit[i].Statu;
        if (Submit[i].Statu == "Running") {
            Submit[i].Flag = 1;
            cin >> Submit[i].During;
            Submit[i].Statu.clear();
            for (int j = 0; j < Submit[i].During; ++j) {
                Submit[i].Statu += "X";
            }
        }
        else if (Submit[i].Statu == "FB") {
            Submit[i].Statu = "AC*";
        }
        if (Submit[i].Rank < 100) {
            cout << " ";
            if (Submit[i].Rank < 10) {
                cout << " ";
            }
        }
        cout << Submit[i].Rank << "|";
        cout << Submit[i].TeamName;
        for (int j = 0; Submit[i].TeamName.length() + j < 16; ++j) {
            cout << " ";
        }
        cout << "|" << Submit[i].Problem << "|[";
        if (Submit[i].Flag) {
            cout << Submit[i].Statu;
            for (int j = 0; Submit[i].Statu.length() + j < 10; ++j) {
                cout << " ";
            }
        }
        else {
            for (int j = 0; j < 4; ++j) {
                cout << " ";
            }
            cout << Submit[i].Statu;
            for (int j = 0; 4 + Submit[i].Statu.length() + j < 10; ++j) {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
