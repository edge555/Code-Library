vector<int>grid[N];
int dp[N][2];
bool visit[N];
int solve(int u,int f,int isTake)
{
    visit[u]=true;
    if(grid[u].size()==0)
        return 0;
    int i,&ret=dp[u][isTake];
    if(ret!=-1)
        return ret;
    ret=0;
    rep0(i,grid[u].size())
    {
        intv=grid[u][i] ;
        if(v==f)
            continue ;
        if(isTake)
            ret+=min(solve(v,u,0),solve(v,u,1));
        else
            ret+=solve(v,u,1);
    }
    return ret+=isTake ;
}
int main()
{
    int i,n,m;
    cin>>n>>m;
    rep0(i,n)
    {
        int u,v;
        cin>>u>>v;
        grid[u].pb(v);
        grid[v].pb(u);
    }
    mem(dp,-1);
    memb(visit);
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(!visit[i])
            ans+=min(solve(i,i,0),solve(i,i,1));
    }
    printf("%d\n",ans);
}
