LL PowMod(LL a,LL b,LL MOD){ 
    LL ret=1; 
    while(b){ 
        if(b&1) ret=(ret*a)%MOD; 
        a=(a*a)%MOD; 
        b>>=1; 
    } 
    return ret; 
} 
LL fac[100005]; 
LL Get_Fact(LL p){ 
    fac[0]=1; 
    for(LL i=1;i<=p;i++) 
        fac[i]=(fac[i-1]*i)%p;  //预处理阶乘
} 
LL Lucas(LL n,LL m,LL p){ 
    LL ret=1; 
    while(n&&m){ 
        LL a=n%p,b=m%p; 
        if(a<b) return 0; 
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p; 
        n/=p; 
        m/=p; 
    } 
    return ret; 
} 
