int unbknap(int W, int n)
{
    int dp[W+1];
    memset(dp,0,sizeof dp);
    int i,j,ans=0;
    for(i=0;i<=W;i++)
    {
        for(j=0;j<n;j++)
        {
            if (wt[j]<=i)
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }
    return dp[W];
}
