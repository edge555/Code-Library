bool dp[N][N];
int countpsub(string s)
{
    int i,j,cnt=0;
    memset(dp,false,sizeof(dp));
    rep0(i,N)
        dp[i][i]=true;
    for(i=s.length()-1;i>=0;i--)
    {
        for(j=i+1;j<s.length();j++)
        {
            if(s[i]==s[j] && ((i+1>j-1) || dp[i+1][j-1]))
            {
                dp[i][j]=true;
                cnt++;
            }
        }
    }
    cnt+=s.length();
    return cnt;
}
