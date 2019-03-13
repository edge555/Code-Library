#define Inf (LLONG_MAX/2)
#define BUBL { \
    t = q[i]; q[i] = q[j]; q[j] = t; \
    t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }
#define Pot(u,v) (d[u] + pi[u] - pi[v])
struct MinCostMaxFlow
{
     typedef long long LL;
     int n,qs;
     vector<vector<LL>>cap,cost,fnet;
     vector<vector<int>>adj;
     vector<LL>d,pi;
     vector<int>deg,par,q,inq;
     // n=number of vertices
    MinCostMaxFlow(int n):n(n),qs(0),deg(n+1),par(n+1),d(n+1),q(n+1),inq(n+1),pi(n+1),cap(n+1,vector<LL>(n+1)),cost(cap),fnet(cap),adj(n+1,vector<int>(n+1)){}
    // call to add a directed edge. vertices are 0-based
    // ALL COSTS MUST BE NON-NEGATIVE
void AddEdge(int from,int to,LL cap_,LL cost_)
{
        cap[from][to]=cap_;
        cost[from][to]=cost_;
}
bool dijkstra(int s,int t)
{
    fill(d.begin(),d.end(),0x3f3f3f3f3f3f3f3fLL);
    fill(par.begin(),par.end(),-1);
    fill(inq.begin(),inq.end(),-1);
    d[s]=qs=0;
    inq[q[qs++]=s]=0;
    par[s]=n;
    int i,j,k;
    while(qs)
    {
        int u=q[0];inq[u]=-1;
        q[0]=q[--qs];
        if(qs)
            inq[q[0]]=0;
        for(i=0,j=2*i+1,t;j<qs;i=j,j=2*i+1)
        {
            if(j+1<qs && d[q[j+1]]<d[q[j]])
                j++;
            if(d[q[j]]>=d[q[i]])
                break;
            BUBL;
        }
        for(k=0,v=adj[u][k];k<deg[u];v=adj[u][++k])
        {
            if(fnet[v][u] && d[v]>Pot(u,v)-cost[v][u])
                d[v]=Pot(u,v)-cost[v][par[v]=u];
            if(fnet[u][v]<cap[u][v] && d[v]>Pot(u,v)+cost[u][v])
                d[v]=Pot(u,v)+cost[par[v]=u][v];
            if(par[v]==u)
            {
                if(inq[v]<0)
                {
                    inq[q[qs]=v]=qs;
                    qs++;
                }
            for(i=inq[v],j=(i-1)/2,t; d[q[i]]<d[q[j]];i=j,j=(i-1)/2)
                BUBL;
            }
        }
    }
    rep0(i,n)
    {
        if(pi[i]<Inf)
            pi[i]+=d[i];
    }
    return par[t]>=0;
}
// Returns: (flow, total cost) between source s and sink t
// Call this once only. fnet[i][j] contains the flow from i to j.
//Careful, fnet[i][j] and fnet[j][i] could both be positive.
pair<LL,LL>mcmf4(int s,int t)
{
    rep0(i,n)
    {
        rep0(j,n)
	     if(cap[i][j] || cap[j][i])
                adj[i][deg[i]++]=j;
    }
    LL flow=0;
    LL fcost=0;
    while(dijkstra(s,t))
    {
        LL bot=LLONG_MAX;
        for(int v=t,u=par[v]; v!=s; u=par[v=u])
        {
            bot=min(bot,fnet[v][u]?fnet[v][u]:(cap[ u][v]-fnet[u][v]));
        }
        for(v=t,u=par[v]; v!=s; u=par[v=u])
        {
            if(fnet[v][u])
            {
                fnet[v][u]-=bot;
                fcost-=bot*cost[v][u];
            }
            else
            {
                fnet[u][v]+=bot;
                fcost+=bot*cost[u][v];
            }
        }
        flow+=bot;
    }
    return make_pair(flow,fcost);
}
};
