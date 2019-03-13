vector<int>grid[N];
vector<pi>bridge;
int vis[N],seen[N],par[N];
int cnt,root,ap[N];
void dfs(int x)
{
    if(vis[x]!=-1)
        return;
    vis[x]=seen[x]=cnt++;
    int adj=0;
    rep0(i,grid[x].size())
    {
        int v=grid[x][i];
        if(par[x]==v)
            continue;
        if(vis[v]==-1)
        {
            adj++;
            par[v]=x;
            dfs(v);
            seen[x]=min(seen[x],seen[v]);
            if(seen[v]>=vis[x] && x!=root)
                ap[x]=1;
            if(seen[v]==vis[v])
                bridge.push_back(make_pair(v,x));
        }
        else
        {
            seen[x]=min(seen[x],vis[v]);
            seen[v]=min(seen[x],seen[v]);
        }
    }
    if(x==root)
        ap[x]=(adj>1);
}
void bridges()
{
    int i;
    bridge.clear();
    rep0(i,N)
    {
        vis[i]=seen[i]=par[i]=-1;
        ap[i]=0;
    }
    cnt=0;
    rep0(i,N)
    {
        if(vis[i]==-1)
        {
            root=i;
            dfs(i);
        }
    }
}
//ap -1 if cut vertex,0 otherwise
