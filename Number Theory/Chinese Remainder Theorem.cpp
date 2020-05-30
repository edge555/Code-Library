inline ll LCM(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
inline ll normalize(ll x, ll mod)
{
    x%=mod;
    if(x<0)
        x+=mod;
    return x;
}
struct GCD_type
{
    ll x,y,d;
};
GCD_type ex_GCD(ll a,ll b)
{
    if(b==0)
        return {1,0,a};
    GCD_type pom = ex_GCD(b,a%b);
    return {pom.y, pom.x - a / b * pom.y , pom.d};
}
ll a[N],b[N],r[N],n[N],p[N],ans,lcm;
int main()
{
    int i,t;
    cin>>t;
    rep(i,t)
        cin>>r[i]; /// Reminder
    rep(i,t)
        cin>>p[i]; /// Prime
    rep(i,t)
    {
        a[i]=r[i];
        n[i]=p[i];
        //normalize(a[i], n[i]);
    }
    ans=a[1];
    lcm=n[1];
    for(i=2;i<=t;i++)
    {
        auto pom=ex_GCD(lcm,n[i]);
        ll x1=pom.x;
        ll d=pom.d;
        if((a[i]-ans)%d!=0)
        {
            cout<<"Not Possible";
            return 0;
        }
        ans=normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
        lcm=LCM(lcm, n[i]);
    }
    cout<<ans;
}
