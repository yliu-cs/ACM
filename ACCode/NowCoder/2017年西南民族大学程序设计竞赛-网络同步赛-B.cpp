#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int len;
    len = a.size();
    int x = 0;
    for (int i = 0;i < (len - 1);++i)
    {
        if (a[i] == a[i + 1])
        {
            x++;
        }else
        {
            cout << "NO";
            break;
        }
    }
    if (x == (len - 1))
    {
        cout << "YES";
    }
    return 0;
 }
