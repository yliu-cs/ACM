// Manacher求回文
int init()
{
    int i;
    memset(len, 0, sizeof len);
    int slen = strlen(S);
    T[0] = '$';

    for (int i = 1; i <= 2*slen; i += 2)
    {
        T[i] = '#';
        T[i+1] = S[i/2];
    }
    T[slen*2 + 1] = '#';
    T[slen*2 + 2] = '%';
    T[slen*2 + 3] = 0;
    return slen * 2 + 1;


}
int Manncher(int l)
{
    int mx = 0, ans = 0, p = 0;
    for (int i = 1; i <= l; i++)
    {
        if (mx > i) len[i] = min(mx - i, len[2 * p - i]);
        else len[i] = 1;
        while (T[i - len[i]] == T[i + len[i]]) len[i]++;
        if (i + len[i] > mx)
        {
            mx = i + len[i];
            p = i;
        }
        ans = ans < len[i] ? len[i] : ans;
    }
    return ans - 1;
}