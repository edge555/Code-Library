**LCA without sparse table***
int lca(int u,int v)
{
    if(depth[u]>depth[v])
        swap(u,v);
    while(depth[v]>depth[u])
        v=parent[v];
    //assert(depth[v]==depth[u]);
    while(u!=v)
    {
        u=parent[u];
        v=parent[v];
    }
    //assert(u==v);
    return u;
}

***LCA using sparse table***
int depth[N];
int table[N][22];
int parent[N];
vector<int>adj[N];
void dfs(int from,int u,int dep)
{
    parent[u]=from;
    depth[u]=dep;
    int i;
    for(i=0;i<(int)adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v==from)
            continue;
        dfs(u,v,dep+1);
    }
}
void lcaInit(int N)
{
    mem(table,-1);
    int i,j;
    rep0(i,N)
        table[i][0]=parent[i];
    for(j=1;(1<<j)<N;j++)
    {
        rep0(i,N)
        {
            if(table[i][j-1]!=-1)
                table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}

int lcaQuery(int p,int q)
{
    if(depth[p]<depth[q])
        swap(p,q);
    // building log's value
    int i,log=1;
    while(true)
    {
        int next=log+1;
        if((1<<next)>depth[p])
            break;
        log++;
    }
    //uplifting p at the same level of q
    for(i=log;i>=0;i--)
    {
        if(depth[p]-(1<<i)>=depth[q])
            p=table[p][i];
    }
    if(p==q)
        return p;
    for(i=log;i>=0;i--)
    {
        if(table[p][i]!=-1 && table[p][i]!=table[q][i])
        {
            p=table[p][i];
            q=table[q][i];
        }
    }
    return parent[p];
}
int main()
{
    dfs(0,0,0);
    lcaInit(n);
    print(lcaQuery(u,v));
}
