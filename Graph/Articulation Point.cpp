int par[N],disc[N],low[N];
bool vis[N],AP[N];
vector<int>grid[N];
void reset()
{
    int i;
    rep(i,n)
    {
        vis[i]=false;
        par[i]=-1;
        grid[i].clear();
        AP[i]=false;
    }
    dt=0;
}
void dfs(int u)
{
    vis[u]=true;
    disc[u]=++dt;
    low[u]=disc[u];
    int i,child=0;
    rep0(i,grid[u].size())
    {
        int v=grid[u][i];
        if(!vis[v])
        {
            par[v]=u;
            child++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(par[u]==-1 && child>1)
                AP[u]=true;
            else if(par[u]!=-1 && disc[u]<=low[v])
                AP[u]=true;
        }
        else if(par[u]!=v)
            low[u]=min(low[u],disc[v]);
    }
}
void tarjan()
{
    int i;
    rep(i,n)
    {
        if(!vis[i])
            dfs(i);
    }
}
int main()
{
    int t,tc;
    sf(tc);
    rep(t,tc)
    {
        int i,m,a,b;
        sff(n,m);
        reset();
        rep0(i,m)
        {
            sff(a,b);
            grid[a].pb(b);
           grid[b].pb(a);
        }
        tarjan();
        int cnt=0;
        rep(i,n)
        {
            if(AP[i])
                cnt++;
        }
        pf("Case %d: %d\n",t,cnt);
    }
}
