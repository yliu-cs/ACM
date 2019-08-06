#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a1 = 0,a2 = 0;
    char a[6],b[6];
    for (int i = 0;i < n;++i)
    {
        cin >> a >> b;
        if ((a[0] == 'J'&&b[0] == 'M')||(a[0] == 'M'&&b[0] == 'T')||(a[0] == 'T'&&b[0] == 'S')||(a[0] == 'S'&&b[0] == 'H')||(a[0] == 'H'&&b[0] == 'J'))
        {
            a1 += 3;
        }else if ((b[0] == 'J'&&a[0] == 'M')||(b[0] == 'M'&&a[0] == 'T')||(b[0] == 'T'&&a[0] == 'S')||(b[0] == 'S'&&a[0] == 'H')||(b[0] == 'H'&&a[0] == 'J'))
        {
            a2 += 3;
        }else
        {
            a1++;
            a2++;
        }
    }
    if (a1 > a2)
    {
        cout << "Alice";
    }else if (a1 < a2)
    {
        cout << "Bob";
    }else
    {
        cout << "Draw";
    }
    return 0;
}
