#include<bits/stdc++.h>
using namespace std;

int Data[3] = {'a', 'A', '1'};

int Ans;

void Solve(int Target, string &Str, vector<int> Change[], vector<int> Pos[]) {
    if (Pos[Target].empty()) {
        if (!Change[(Target + 1) % 3].empty()) {
            Str[Change[(Target + 1) % 3].back()] = Data[Target];
            Pos[Target].push_back(Change[(Target + 1) % 3].back());
            Change[(Target + 1) % 3].pop_back();
        }
        else if (!Change[(Target + 2) % 3].empty()) {
            Str[Change[(Target + 2) % 3].back()] = Data[Target];
            Pos[Target].push_back(Change[(Target + 2) % 3].back());
            Change[(Target + 2) % 3].pop_back();
        }
        else if ((int)Pos[(Target + 1) % 3].size() > 2) {
            Str[Pos[(Target + 1) % 3].back()] = Data[Target];
            Pos[Target].push_back(Pos[(Target + 1) % 3].back());
            Pos[(Target + 1) % 3].pop_back();
        }
        else if ((int)Pos[(Target + 2) % 3].size() > 2) {
            Str[Pos[(Target + 2) % 3].back()] = Data[Target];
            Pos[Target].push_back(Pos[(Target + 2) % 3].back());
            Pos[(Target + 2) % 3].pop_back();
        }
        else if ((int)Str.length() < 6) {
            Pos[Target].push_back((int)Str.length());
            Str += 'a';
        }
        Ans++;
    }
}

int main(int argc, char *argv[]) {
    string Str;
    cin >> Str;
    vector<bool> Vis((int)Str.length(), false);
    vector<int> Change[3], Pos[3];
    for (int i = 0; i < (int)Str.length(); ++i) {
        int Flag;
        if (Str[i] >= 'a' && Str[i] <= 'z') {
            Flag = 0;
        }
        else if (Str[i] >= 'A' && Str[i] <= 'Z') {
            Flag = 1;
        }
        else if (Str[i] >= '0' && Str[i] <= '9') {
            Flag = 2;
        }
        Pos[Flag].push_back(i);
        if (i + 2< (int)Str.length()) {
            if (Str[i] == Str[i + 1] && Str[i + 1] == Str[i + 2] && !Vis[i] && !Vis[i + 1] && !Vis[i + 2]) {
                Vis[i] = Vis[i + 1] = Vis[i + 2] = true;
                Change[Flag].push_back(i + 2);
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        Solve(i, Str, Change, Pos);
    }
    for (int i = 0; i < 3; ++i) {
        while (!Change[i].empty()) {
            if ((int)Str.length() > 20) {
                Str.erase(Str.begin() + Change[i].back());
            }
            else {
                Str[Change[i].back()] = '#';
            }
            Change[i].pop_back();
            Ans++;
        }
    }
    if ((int)Str.length() < 6) {
        Ans += 6 - (int)Str.length();
    }
    cout << Ans << endl;
    return 0;
}

