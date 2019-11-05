#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int N;
    char a[13][13];
    while (cin >> N)
    {
        int *b;
        b = new int[N];
        for (int i = 0;i < N;++i)
        {
            b[i] = 0;
        }
        int x = 0;
        if (N == 0)
        {
            break;
        }
        for (int j = 0;j < 13;++j)
        {
            for (int i = 0;i < 13;++i)
            {
                cin >> a[j][i];
                if (a[j][i] == '#')
                {
                    if (j == 0||i == 0||j == 12||i == 12)
                    {
                        b[x]++;
                        x++;
                    }else if((j == 1&&i != 0&&i != 12)||(j == 2&&i != 0&&i != 12)||(j == 10&&i != 0&&i != 12)||(j == 11&&i != 0&&i != 12)||(i == 1&&j != 0&&j != 12)||(i == 2&&j != 0&&j != 12)||(i == 10&&j != 0&&j != 12)||(i == 11&&j != 0&&j != 12))
                    {
                        b[x] += 2;
                        x++;
                    }else if(j >= 5&&j <= 7&&i >= 5&&i <=7)
                    {
                        b[x] += 4;
                        x++;
                    }else
                    {
                        b[x] += 3;
                        x++;
                    }
                }
            }
        }
        double sum = 0;
        for (int i = 0;i < N;++i)
        {
            sum += b[i];
        }
        double result = sum/(double)N;
        cout << setiosflags(ios::fixed) << setprecision(2) << result << endl;
    }
    return 0;
}
