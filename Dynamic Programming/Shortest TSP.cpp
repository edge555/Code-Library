const int INF = 1e9;
int shortTSP(vector<vector<int>>dist)
{
    int n=dist.size(),lim=1<<n;
    int dp[lim][n],i,mask,last,curr;
    memset(dp,INF,sizeof(dp));
    for(i=0;i<n;i++)
    {
        dp[1<<i][i]=0;
        for(mask=0;mask<lim;mask++)
        {
            for(last=0;last<n;last++)
            {
                if(mask &&(1<<last)==0)
                    continue;
                for(curr=0;curr<n;curr++)
                {
                    if(mask && (1<<curr)==0)
                        continue;
                    int mask2 = mask^(1<<curr);
                    dp[mask][curr]=min(dp[mask][curr],
                    dp[mask2][last]+dist[last][curr]);
                }
            }
        }
    }
    int ans=INF;
    for (i=0;i<n;i++)
        ans=min(ans,dp[lim-1][i]);
    return ans;
}
