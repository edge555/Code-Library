ll mulmod(ll a,ll b,ll c)
{
    ll x=0,y=a%c;
    while(b)
    {
        if(b&1)
            x=(x+y)%c;
        y=(y<<1)%c;
        b>>=1;
    }
    return x%c;
}
ll fastpow(ll x,ll n,ll MOD)
{
    ll ret=1;
    while(n)
    {
        if(n&1)
            ret=mulmod(ret,x,MOD);
        x=mulmod(x,x,MOD);
        n>>=1;
    }
    return ret;
}
bool isPrime(ll n)
{
    ll d=n-1;
    int i,j,s=0;
    while(d%2==0)
    {
        s++;
        d>>=1;
    }
    int ara[9]={2,3,5,7,11,13,17,19,23};
    rep0(i,9)
    {
        bool comp=fastpow(ara[i],d,n)!=1;
        if(comp)
        {
            rep0(j,s)
            {
                ll fp=fastpow(ara[i],(1LL<<(ll)j)*d,n);
                if(fp==n-1)
                {
                    comp=false;
                    break;
                }
            }
            if(comp)
                return false;
        }
    }
    return false;
}
ll egcd(ll a,ll b, ll*x,ll *y)
{
    ll x,y,x1,y1,x2,y2,r1,r2,q,r;
    x2=1;y2=0;
    x1=0;y1=1;
    for(r2=a,r1=b;r1!=0;r2=r1,r1=r,x2=x1,y2=y1,x1=x,y1=y)
    {
        q=r2/r1;
        r=r2%r1;
        x=x2-(q*x1);
        y=y2-(q*y1);
    }
    *x=x2;*y=y2;
    return r2;
}
ll modinv(ll a,ll m)
{
    ll x,y;
    egcd(a,m,&x,&y);
    x%=m;
    if(x<0)
        x+=m;
    return x;
}
ll power(ll a,ll p)
{
    ll res=1,x=a;
    while(p)
    {
        if(p&1)
            res=(res*x);
        x=(x*x);
        p>>=1;
    }
    return res;
}
ll bigmod(ll a,ll p,ll m)
{
    ll res=1%m,x=a%m;
    while(p)
    {
        if(p&1)
            res=(res*x)%m;
        x=(x*x)%m;
        p>>=1;
    }
    return res;
}
