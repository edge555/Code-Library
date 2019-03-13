int n,m,st,en,i,j;
vector<pi>grid[501];
vector<int>path[501];
int dis[501];
priority_queue<pi,vector<pi>,greater<pi>>pq;
void setvalue()
{
    rep0(i,n)
    {
        grid[i].clear();
        dis[i]=1e9;
    }
}
void deletepath()
{
    queue<int>q;
    q.push(en);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        rep0(i,path[u].size())
        {
            int v=path[u][i];
            if(v!=st)
                q.push(v);
            rep0(j,grid[v].size())
            {
                if(grid[v][j].fi==u)
                {
                    grid[v].erase(grid[v].begin()+j);
                    break;
                }
            }
        }
    }
    rep0(i,n)
    {
        dis[i]=1e9;
        path[i].clear();
    }
}
void dijkstra(int src)
{
    dis[src]=0;
    pq.push(mpp(0,src));
    while(!pq.empty())
    {
        pi p=pq.top();
        pq.pop();
        int u=p.se,w=p.fi;
        if(w>dis[u])
            continue;
        rep0(i,grid[u].size())
        {
            pi pr=grid[u][i];
            int v=pr.fi,c=pr.se;
            if(dis[v]>dis[u]+c)
            {
                path[v].clear();
                path[v].pb(u);
                dis[v]=dis[u]+c;
                pq.push(mpp(dis[v],v));
            }
            else if(dis[v]==dis[u]+c)
                path[v].pb(u);
        }
    }
}
int main()
{
    while(1)
    {
        sff(n,m);
        sff(st,en);
        setvalue();
        int a,b,w;
        while(m--)
        {
            sfff(a,b,w);
            grid[a].pb(mpp(b,w));
        }
        dijkstra(st);
        deletepath();
        dijkstra(st);
        if(dis[en]==1e9)
            pf("-1\n");
        else
            pf("%d\n",dis[en]);
    }
