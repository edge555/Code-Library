ll p[N],r[N];
int n;
void extgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
        d=a,x=1,y=0;
    else
    {
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll chinese_remainder()
{
    ll M=1;
    for(int i=0; i<n; i++)
        M*=p[i];
    ll ans=0;
    ll m;
    ll d,x,y;
    for(int i=0; i<n; i++)
    {
        m=M/p[i];
        extgcd(m,p[i],d,x,y);
        ans=(ans+r[i]*m*x)%M;
    }
    return (ans+M)%M;
}
