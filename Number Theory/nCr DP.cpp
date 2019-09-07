ll nCr(int n,int k)
{
    ll dp[k+1];
    mem(dp,0);
    dp[0]=1;
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=min(i,k);j>0;j--)
            dp[j]+=dp[j-1];
    }
    return dp[k];
}
