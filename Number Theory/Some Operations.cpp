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

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
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