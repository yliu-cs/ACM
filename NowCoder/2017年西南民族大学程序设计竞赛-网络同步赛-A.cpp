#include<cstdio>
#include<cstring>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define ll long long
using namespace std;
char s[1010][1010];
int hm[1010][3];
int rm[1010][3];
int main()
{
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<n;i++)
        {
                scanf("%s",s[i]);
        }
        for(int i=0;i<n;i++)
        {
                int l=1010;
                int r=-100;
                for(int j=0;j<m;j++)
                {
                        if(s[i][j]=='#')
                                {
                                        l=min(l,j);
                                        r=max(r,j);
                                }
                }
                hm[i][1]=l;
                hm[i][2]=r;
        }
        for(int j=0;j<m;j++)
        {
                int l=1010,r=-10;
                for(int i=0;i<n;i++)
                {
                        if(s[i][j]=='#')
                                {
                                        l=min(l,i);
                                        r=max(r,i);
                                }
                }
                rm[j][1]=l;
                rm[j][2]=r;
        }
        int w,e;
        char t;
  
        for(int i=0;i<q;i++)
        {
               scanf("%d%d %c",&w,&e,&t);
            w--;e--;
               bool flag=false;
               if(t=='D')
               {
                       if(w<rm[e][2])
                        flag=true;
  
               }
               else if(t=='U')
               {
                       if(w>rm[e][1])
                        flag=true;
               }
               else if(t=='L')
               {
                       if(e>hm[w][1])
                        flag=true;
               }
               else if(t=='R')
               {
                       if(e<hm[w][2])
                        flag=true;
               }
               if(flag) printf("NO\n");
               else printf("YES\n");
        }
        return 0;
}
