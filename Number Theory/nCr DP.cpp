ll dp[N][N];
ll nCr(int n,int r)
{
    if(r==1)
        return n;
    if(r==n)
        return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    else
    {
        dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
        return dp[n][r];
    }
}
main:
    mem(dp,-1);
    cout<<nCr(n,r);
