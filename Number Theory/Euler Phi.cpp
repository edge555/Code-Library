ll phi(ll n)
{
    ll i,ret=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            ret-=ret/i;
        }
    }
    if(n>1)
        ret-=ret/n;
    return ret;
}

int phi[N];
void genphi()
{
    int i,j;
    rep(i,N-1)
        phi[i]=i;
    rep(i,N-1)
    {
        for(j=2*i;j<=N-1;j+=i)
            phi[j]-=phi[i];
    }
}