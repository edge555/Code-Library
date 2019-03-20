bool isSubsetSum(vector<int>& vec,int sum)
{
    int i,n=(int)vec.size();
    vector<vector<bool>>dp(sum+1 vector<bool>(n));
    rep0(i,n)
        dp[0][i]=true;
    rep(i,sum)
        dp[i][0]=false;
    rep(i,sum)
    {
        rep0(j,n)
        {
            dp[i][j]=dp[i][j-1];
            if (i-vec[j]>=0)
                dp[i][j]=dp[i][j] | dp[i-vec[j]][j-1];
        }
    }
    return dp[sum][n];
}
