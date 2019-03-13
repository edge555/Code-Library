#define root 0
#define LogN 14
#define segTreeSize 32768
//2*pow(2.0,floor(log((double)N)/log(2.0))+1
vector <int>adj[N],costs[N],indexx[N];
int baseArray[N],ptr,posInBase[N];
int chainNo,chainInd[N],chainHead[N];
int depth[N],table[N][LogN],otherEnd[N];
int segment_tree[segTreeSize],subTreeSize[N];
*Segment tree*
///
void buildSegTree(int node=1,int start=0,int end=ptr-1);
void update(int node,int start,int end,int index,int value);
int querySegTree(int node,int start,int end,int i,int j);
///
/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up(int u,int v)
{
    if(u==v)
        return 0;
    int uchain,vchain=chainInd[v],ans=-1,ret;
    while(true)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            if(u==v)
                break;
            ret=querySegTree(1,0,ptr-1,posInBase[v]+1,posInBase[u]);
            ans=max(ans,ret);
            break;
        }
        ret=querySegTree(1,0,ptr-1,posInBase[chainHead[uchain]],posInBase[u]);
        ans=max(ans,ret);
        u=chainHead[uchain];
        u=table[u][0];
    }
    return ans;
}
*LCA*
//
int lcaQuery(int u,int v);
void lcaInit(int n);
//
void query(int u,int v)
{
    int lca=lcaQuery(u,v);
    int ans=max(query_up(v,lca),query_up(u,lca));
    printf("%d\n",ans);
}
void change(int i,int val)
{
    int u=otherEnd[i];
    update(1,0,ptr-1,posInBase[u],val);
}
void HLD(int curNode=root,int cost=-1,int prev=-1)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=curNode;
    chainInd[curNode]=chainNo;
    posInBase[curNode]=ptr;
    baseArray[ptr++]=cost;
    int i,sc=-1,ncost;
    //Loop to find special child
    for(i=0;i<(int)adj[cur].size();i++)
    {
        int v=adj[curNode][i];
        if(v!=prev)
        {
            if(sc==-1 || subTreeSize[sc]<subTreeSize[v])
            {
                sc=v;
                ncost=costs[curNode][i];
            }
        }
    }
    if(sc!=-1)
    {   // Incase of curNode is leaf node
        // Expand the chain
        HLD(sc, ncost, curNode);
    }
    for(i=0;i<(int)adj[cur].size();i++)
    {
        int v=adj[curNode][i];
        if(v!=prev && v!=sc)
        {
            // New chains at each normal node
            chainNo++;
            HLD(v,costs[curNode][i],curNode);
        }
    }
}
void dfs(int cur=root,int prev=-1,int _depth=0)
{
    table[cur][0]=prev;
    depth[cur]=_depth;
    subTreeSize[cur]=1;
    for(i=0;i<(int)adj[cur].size();i++)
    {
        int v=adj[cur][i];
        if(v!=prev)
        {
            otherEnd[indexx[cur][i]]=v;
            dfs(v,cur,_depth+1);
            subTreeSize[cur]+=subTreeSize[v];
        }
    }
}
void reset()
{
    int i,j
    rep0(i,n)
    {
        adj[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i]=-1;
        for(j=0;i<LogN;i++)
            table[i][j]=-1;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ptr=0;
        int n;
        cin>>n;
        reset();
        rep0(i,n-1)
        {
            int u,v,cost;
            sfff(u,v,cost);
            u--,v--;
            adj[u].pb(v);
            costs[u].pb(cost);
            indexx[u].pb(i);
            adj[v].pb(u);
            costs[v].pb(cost);
            indexx[v].pb(i);
        }
        chainNo=0;
        dfs();
        HLD();
        buildSegTree();
        lcaInit(n);
        while(true)
        {
            query(a-1,b-1);
            change(a-1,b);
        }
    }
}
