// Exkmp
void getextNext()
{
    int p , a;
    int tlen = strlen(T);
    Next[0] = tlen;
    for (int i = 1, j = - 1; i < tlen; i++, j--)
    {
        if (-1 == j || i + Next[i - a] >= p)
        {
            if (j == -1) p = i, j = 0;

            while (p < tlen && T[p] == T[j]) p++, j++;
            Next[i] = j;
            a = i;
        }
        else Next[i] = Next[i - a];

    }
}
void getext()
{
    int p , a;
    getextNext();
    int slen = strlen(S);
    int tlen = strlen(T);
    for (int i = 0, j = - 1; i < slen; i++, j--)
    {
        if (-1 == j || i + Next[i - a] >= p)
        {
            if (j == -1) p = i, j = 0;

            while (p < slen && j < tlen && S[p] == T[j] ) p++, j++;
            ext[i] = j;
            a = i;
        }
        else ext[i] = Next[i - a];

    }
}