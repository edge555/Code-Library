#define INF (1<<30)
bool vis[N][1<<N];
int dp[N][1<<N];
int weight[N][N];
//2D grid input
int target=(1<<N)-1;
int origin;
pair<int,int>trace[N][(1<<N)+1];
bool Check(int N,int pos)
    return (bool)(N & (1<<pos));
int Set(int N,int pos)
    return N | (1<<pos);
int tspBitmask(int node,int mask)
{
    if (mask==target)
    {
        vis[node][mask]=true;
        trace[node][mask]=make_pair(origin,weight[node][origin]);
        return dp [node][mask]=weight[node][origin];
    }
    if(vis[node][mask])
        return dp[node][mask];
    vis[node][mask]=true;
    int i,ans=INF,v,cost;
    rep0(i,N)
    {
        if(!Check(mask,i))
        {
            int ret=tspBitmask(i,Set(mask,i));
            if(ret+weight[node][i]<ans)
            {
                ans=ret+weight[node][i];
                v=i;
                cost=weight[node][i];
            }
        }
    }
    trace[node][mask]=make_pair(v,cost);
    return dp[node][mask]=ans;
}
void printPath()
{
    memset(vis);
    origin=0;
    printf ("%d\n",tspBitmask(origin,(1<<origin)));
    int i,mask=0;
    mask |= (1<<origin);
    int u=origin,v,cost;
    rep0(i,N)
    {
        v=trace[u][mask].first;
        cost=trace[u][mask].second;
        printf("%d %d %d\n",u,v,cost);
        mask |= (1<<v);
        u=v;
    }
}
