int pfn; //number of distinct prime factors
int pf[N]; //prime factor powers
int rem[N]; //corresponding remainder
int pm[N],prime[N];
void sieve()
{ }
int inverse(int x,int p)
{
    int q,tmp,a=x,b=p;
    int a0=1,a1=0,b0=0,b1=1;
    while(b)
    {
        q=a/b; tmp=b; b=a-b*q; a=tmp;
        tmp=b0; b0=a0-b0*q; a0=tmp;
        tmp=b1; b1=a1-b1*q; a1=tmp;
    }
    return a0;
}
void decompose_mod()
{
    int i,p,t=mod;
    pfn=0;
    for(i=0;i<pnum && prime[i]<=t;i++)
    {
        p=prime[i];
        if(t%p==0)
        {
            pf[pfn]=1;
            while(t%p==0)
            {
                t/=p;
	            pf[pfn]*=p;
            }
            pfn++;
        }
    }
    if(t>1)
        pf[pfn++]=t;
}
int chinese_remainder()
{
    int i,m,s=0;
    rep0(i,pfn)
    {
        m=mod/pf[i];
        pm[i]=(long long)m*inverse(m,pf[i])%mod;
        s=(s+(long long)pm[i]*rem[i])%mod;
    }
    return s;
}
