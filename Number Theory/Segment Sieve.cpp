#define N 50000
vector<int>prime;
bool flag[100005],check[N];
void sieve()
{
     int i,j;
     prime.pb(2);
     for(i=3;i*i<=N;i+=2)
     {
          if(check[i]==0)
          {
              prime.pb(i);
	for(j=(i*i);j<=N;j+=(2*i))
	     check[j]=1;
          }
     }
     for(;i<=N;i+=2)
     {
        if(check[i]==0)
             prime.pb(i);
     }
}
int seg(ll a,ll b)
{
    int i,ans=0;
    for(i=0;i<(b-a+1);i++)
        flag[i]=0;
    if(a<2)
        a=2;
    for(i=0;(ll)(prime[i]* prime[i])<=b && i<prime.size();i++)
    {
        ll j=(prime[i]*(a/prime[i]));
        if(j<a)
            j+=prime[i];
        if(j<(ll)(prime[i]+prime[i]))
            j=prime[i]+prime[i];
        for(;j<=b;j+=prime[i])
            flag[j-a]=1;
    }
    for(i=0;i<(b-a+1);i++)
    {
        if(flag[i]==0)
             ans++;
    }
    return ans;
}
main:
    sieve()
    seg(a,b)
