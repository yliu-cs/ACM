#include <bits/stdc++.h>
using namespace std;


int T;
int N;
int Ans;
string Type, Buffer, Name;

int Classify() {
    int Size = 0;
    if (Type == "bool" || Type == "char") {
        Size = 1;
    }
    else if (Type == "int" || Type == "float") {
        Size = 4;
    }
    else if (Type == "longlong" || Type == "double") {
        Size = 8;
    }
    else if (Type == "__int128" || Type == "longdouble") {
        Size = 16;
    }
    return Size;
}

int Count() {
    size_t Index = Name.find('[');
    if (Index == string::npos) {
        return 1;
    }
    int Cnt = 0;
    for (int i = Index + 1; Name[i] != ']'; ++i) {
        Cnt = Cnt * 10 + (Name[i] - '0');
    }
    return Cnt;
}

int main(int argc, char *argv[]) {
    cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        cin >> N;
        Ans = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> Type;
            if (Type == "long") {
                cin >> Buffer;
                Type += Buffer;
            }
            cin >> Name;
            Ans += Classify() * Count();
        }
        cout << "Case #" << Case << ": " << (Ans + 1023) / 1024 << endl;
    }
    return 0;
}

