ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll t=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return t;
}
///Point finding
if(C%T==0)
    pf("%lld %lld\n",-x*C/T,-y*C/T);
else
    pf("-1\n");
