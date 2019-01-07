// 字符串最大最小表示法
int minstr()
{
    int i = 0, j = 1, k = 0;
    while (i < tlen && j < tlen && k < tlen)
    {
        int tem = t[(i + k) % tlen] - t[(j + k) % tlen];
        if (!tem) k++;
        else
        {
            if (tem > 0) i = i + k + 1;
            else j = j + k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}
int maxstr()
{
    int i = 0, j = 1, k = 0;
    while (i < tlen && j < tlen && k < tlen)
    {
        int tem = t[(i + k) % tlen] - t[(j + k) % tlen];
        if (!tem) k++;
        else
        {
            if (tem > 0) j = j + k + 1;
            else i = i + k + 1;

            if (i == j) j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}