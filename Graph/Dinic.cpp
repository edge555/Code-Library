#define maxn 500 , maxe 10000
//finds maxflow from "st" to "endd"
//V - throughput of edges
//reverse edge has num "edge_num^1"
int Head[maxn],Next[2*maxe];
int Dest[2*maxe],e,mfl;
int V[2*maxe],B[maxn];
int u[maxn],uit,Lv[maxn],endd,st,
long long flow;
int Q[maxn],bq,eq;
void add(int v1,int v2,int v)
{
    Dest[e]=v2, Next[e]=Head[v1];
    Head[v1]=e, V[e]=v, e++;
    //assert(e<=2*maxe);
}
int dfs(int v,int fl)
{
    int nfl,nv,ne;
    u[v]=uit;
    if(v==endd)
    {
        flow+=fl;
        return fl;
    }
    for(;B[v]!=-1;B[v]=Next[B[v]])
    {
        ne=B[v];
        nv=Dest[ne];/*BOXNEXT*/
        if(u[nv]!=uit && V[ne]>=mfl && Lv[nv]==Lv[v]+1)
        {
            nfl=dfs(nv,min(V[ne],fl));
            if(nfl)
            {
                V[ne]-=nfl;
                V[ne^1]+=nfl;
                return nfl;
            }
        }
    }
    return 0;
}
long long dinic(int n,int _st,int _endd)
{
    int v,r,i;
    flow=0;
    st=_st;
    endd=_endd;
    mfl=(1<<29);
    while(mfl)
    {
        while(true)
        {
            rep0(i,n)
            {
                Lv[i]=inf;
                B[i]=Head[i];
            }
            Lv[st]=0,Q[0]=st;
            bq=0,eq=1;
            while(bq<eq)
            {
                v=Q[bq++];
                for(r=Head[v];r!=-1;r=Next[r])
                {
                    if (V[r]>=mfl && Lv[Dest[r]]==inf)
                    {
                        Lv[Dest[r]]=Lv[v]+1;
                        Q[eq++]=Dest[r];
                    }
                }
            }
            if(Lv[endd]==inf)
                break;
            uit++;
            while(dfs(st,inf))
                uit++;
        }
        mfl>>=1;
    }
    return flow;
}
int main()
{
    int i,v1,v2,v,n,m;
    mem(Head,-1);
    cin>>n>>m;
    //assert(1<=n && n<=500);
    //assert(1<=m && m<=10000);
    rep0(i,m)
    {
        cin>>v1>>v2>>v;
        v1--;
        v2--;
        add(v1,v2,v);
        add(v2,v1,0);
    }
    cout<<dinic(n,0,n-1);
}
