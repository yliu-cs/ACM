#include <iostream>
#include <string>
using namespace std;
int main()
{
    char a[26];
    for (int i = 0;i < 26;i++)
    {
        a[i] = i;
    }
    string s;
    cin >> s;
    int n;
    cin >> n;
    char s1,s2;
    for (int i = 0;i < n;++i)
    {
        cin >> s1 >> s2;
        int x = s1 - 'a',y = s2 - 'a';
        int l = a[x],r = a[y];
        a[y] = l;
        a[x] = r;
    }
    for (int i = 0;s[i];++i)
    {
        cout << (char)(a[s[i] - 'a'] + 'a');
    }
    return 0;
}
