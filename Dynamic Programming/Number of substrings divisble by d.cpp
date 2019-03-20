int solve(string const& num,int d)
{
    int i,j,ans=0,n=num.length();
    vector<vector<int>>dp(n,vector<int>(d,0));
    rep0(i,n)
    {
        int digit=num[i]-'0';
        dp[i][digit%d]++;
        if(i>0)
        {
            rep0(j,d)
            {
                int r=(j*10+digit)% d;
                dp[i][r]+=dp[i-1][j];
            }
        }
        ans+=dp[i][0];
        /* if numbers with preceeding 0 aren't allowed except '0' itself
        if(digit == 0)
            dp[i][digit % d]--;
        */
    }
    return ans;
}
