int phi[N], prime[N];
void sievephi(int n)
{
    int i,j;
    rep(i,n)
        phi[i]=i;
    phi[1]=1;
    prime[1]=1;
    for(i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(j=i;j<=n; j+=i)
            {
                prime[j+i]=1;
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
}
