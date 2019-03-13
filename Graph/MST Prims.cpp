int vis[N];
vector<int>edge[N],cost[N];
struct data
{
    int v,w;
    bool operator<(data p)const{
        return w>p.w;
    }
};
int mstPrims(int src,int n)
{
    mem(vis,0);
    priority_queue<data>pq;
    int i,j,u,v,p,sum=0;
    rep0(i,n-1)
    {
        u=src;
        vis[src]=1;
        rep0(j,edge[u].size())
        {
            v=edge[u][j];
            if(vis[v]==0)
            {
                data D;
                D.v=v;
                D.w=cost[u][j];
                pq.push(D);
            }
        }
        while(vis[src])
        {
            data T=pq.top();
            pq.pop();
            src=T.v;
            p=T.w;
        }
        sum+=p;
    }
    return sum;
}
int main()
{
    int i,n,e,u,v,w;
    cin>>n>>e;
    rep0(i,e)
    {
        cin>>u>>v>>w;
        edge[u].pb(v); edge[v].pb(u);
        cost[u].pb(w); cost[v].pb(w);
    }
    cout<<mstPrims(1,n);
}
