vector<int>grid[N];
int ara[N],d[N],low[N];
int n,m,dt,cnt;
stack<int>s;
void reset()
{
    int i;
    rep0(i,n)
        grid[i].clear();
    while(!s.empty())
        s.pop();
}
void dfs(int u)
{
    dt++;
    d[u]=dt;
    low[u]=dt;
    s.push(u);
    int i;
    rep0(i,grid[u].size())
    {
        int v=grid[u][i];
        if(!d[v])
        {
	        dfs(v);
	        low[u]=min(low[u],low[v]);
        }
        else if(!ara[v])
            low[u]=min(low[u],d[v]);
    }
    if(low[u]==d[u])
    {
        cnt++;
        int v;
        do
        {
            v=s.top();
            s.pop();
            ara[v]=cnt;
        }while(v!=u);
    }
}
void scc(int n)
{
    mem(ara,0);
    mem(d,0);
    int i;
    rep0(i,n)
    {
        if(!d[i])
            dfs(i);
    }
}
int main()
{
    int t,tc;
    sf(tc);
    rep(t,tc)
    {
        int i,a,b;
        sff(n,m);
        reset();
        rep0(i,m)
        {
            sff(a,b);
            grid[a].pb(b);
            //grid[b].pb(a);
        }
        dt=0;cnt=0;
        scc(n);
        printf("%d\n",cnt);
    }
}
