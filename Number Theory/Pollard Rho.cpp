/**
    Dependencies:
        1. MillerRabin
    Use:
        1. Call pollardRho.clear();
        2. Call pollardRho.primefact(n);
    See sample main() function below
*/
class PollardRho
{
    private:
    MillerRabin millerRabin;
    int prime[50000],status[50000],primeSize;
    void sieve()
    {
        primeSize=0;
        memset(status,0);
        status[0]=status[1]=1;
        int n=46340,i,j;
        for(i=4;i<=n;i+=2)
            status[i]=1;
        int sqrtn=sqrt(n);
        for(i=3;i<=sqrtn;i+=2)
        {
            for(j=i*i;j<=n;j+=2*i)
                status[j]=1;
        }
        prime[primeSize++]=2;
        for(i=3;i<=n;i+=2)
        {
            if(status[i]==0)
                prime[primeSize++]=i;
        }
    }
    void factsieve(int n)
    {
        int sqrtn=sqrt(n);
        for(i=0;i<primeSize && prime[i]<=sqrtn;i++)
        {
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    factors.push_back(prime[i]);
                    n/=prime[i];
                }
                sqrtn=sqrt(n);
            }
        }
        if(n!=1)
            factors.push_back(n);
    }
    ll pollard_rho(ll n,ll c)
    {
        ll y=2,i=1,k=2,d;
        __int128 x=2;
        while (true)
        {
            x=x*x%n+c;
            if(x>=n)
            	x-=n;
            d=__gcd((ll)x-y,n);
            if(d>1)
                return d;
            if(++i==k)
            {
                y=x;
                k<<=1;
            }
        }
        return n;
    }
    void factorize(ll n)
    {
        if(n==1)
            return ;
        if(n<1e+9)
        {
            factsieve(n);
            return ;
        }
        if(millerRabin.isPrime(n))
        {
            factors.push_back(n);
            return ;
        }
        ll d=n;
        for(i=2;d==n;i++)
            d=pollard_rho(n,i);
        factorize(d);
        factorize(n/d);
    }
    public:
    vector<ll>factors;
    PollardRho()
        sieve();

    void clear()
        factors.clear();
    vector<pair<ll,int>> primefact(ll n)
    {
        factorize(n);
        sort(factors.begin(), factors.end());
        vector<pair<ll,int>> res;
        rep0(i,factors.size())
        {
            ll p=factors[i];
            int cnt=1;
            while(i+1<factors.size() && factors[i+1]==p)
            {
                i++;
                cnt++;
            }
            res.push_back({p,cnt});
        }
        return res;
    }
}pollardRho;

int main()
{
    int n = 1e16+8;
    pollardRho.clear();
    /// Don't forget to clear. Important for multi case.
    prime<pair<ll,int>>factors=pollardRho.primefact(n);
    rep0(i,factors.size())
    {
        int p=factors[i].fi, a=factors[i].se;
        /// p^a is factor of n
        /// Do your work here
    }
}
