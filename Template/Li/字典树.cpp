// 字典树
void insert(char *s)
{
    int data,i;
    int u=0;
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        data=s[i]-'0';
        if(!trie[u][data])
            trie[u][data]=zz++;
        u=trie[u][data];
        val[u]++;
        
        
      
    }
}
int find(string s)
{
    int u=0,data;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        data=s[i]-'0';
        if(!trie[u][data])
            return 0;
        u=trie[u][data];
    }
    return val[u];
}