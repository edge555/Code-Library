int dp[2010][2010];
int min3(int a,int b,int c)
{
    return min(min(a,b),c);
}
int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.size(),n=b.size();
    rep0(i,m)
        dp[i][0]=i;
    rep0(j,n)
        dp[0][j]=j;
    rep(i,m)
    {
        rep(j,n)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    cout<<dp[m][n];
}
