int shop[20],d[N];
vector<pii>g[N];
int dist[20][20];
int dp[20][(1<<18)+10];
int n,m,s,strt,nd;
void reset()
{
    int i,j;
    rep0(i,s+1)
    {
        rep0(j,s+1)
            dist[i][j]=inf;
    }
    rep0(i,n+1)
        g[i].clear();
}
void dijkstra(int st,int ith)
{
    int i;
    set<pii>heap;
    heap.insert(pii(0,st));
    for(i=0;i<=n;i++)
        d[i]=inf;
    d[st]=0;
    while(!heap.empty()){
        pii data=*heap.begin(); heap.erase(data);
        int u=data.sc;
        for(i=0;i<g[u].size();i++)
        {
            int v=g[u][i].fs;
            int w=g[u][i].sc+d[u];
            if(w<d[v])
            {
                if(d[v]!=inf)
                    heap.erase(pii(d[v],v));
                d[v]=w;
                heap.insert(pii(d[v],v));
            }
        }
    }
    for(i=0;i<=nd;i++)
        dist[ith][i]=d[shop[i]];
}
void DP()
{
    int i,j;
    rep0(i,s)
    {
        for(j=0;j<(1<<s);j++)
            dp[i][j]=inf;
        dp[i][(1<<i)]=dist[strt][i];
    }

    int mask,u,v,cnt=0,ans=dist[strt][nd];
    for(mask=0;mask<(1<<s);mask++)
    {
        rep0(u,s)
        {
            if(dp[u][mask]!=inf)
            {
                rep0(v,s)
                {
                    if(shop[u]!=shop[v] && dist[u][v]!=inf)
                    {
                        int nxt=Set(mask,v);
                        dp[v][nxt]=min(dp[v][nxt],dp[u][mask]+dist[u][v]);
                    }
                }
                int x=__builtin_popcount(mask);
                if(dist[u][nd]!=inf && x>=cnt)
                {
                    if(cnt==x)
                        ans=min(ans, dp[u][mask]+dist[u][nd]);
                    else
                        ans=dp[u][mask]+dist[u][nd];
                    cnt=x;
                }
            }
        }
    }
    printf("%d %d\n",cnt,ans);
}
int main()
{
    int t,tc;
    cin>>tc;
    rep(t,tc)
    {
        cin>>n>>m>>s;
        reset();
        for(int i=0;i<s;i++)
            cin>>shop[i];
        strt=s,nd=strt+1;
        shop[strt]=0,shop[nd]=n-1;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].pb(pii(v,w));
        }
        rep0(i,nd+1)
            dijkstra(shop[i],i);
        printf("Case %d: ",t);
        if(dist[strt][nd]==inf)
            puts("Impossible");
        else
            DP();
    }
}
