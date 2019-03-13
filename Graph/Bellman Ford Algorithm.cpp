int n,edge,src,edge_cost[N];
int d[N],edge_u[N],edge_v[N];
int main()
{
    int i.step;
    cin>>n>>m>>src;
    rep(i,n)
        d[i]=99999;
    d[src]=0;
    for(i=1;i<=m;i++)
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    bool neg_cycle=false;
    for(step=1;step<=n;step++)
    {
        bool updated=false;
        rep(i,m)
        {
            int u=edge_u[i],v=edge_v[i],w=edge_cost[i];
            if(d[u]+edge_cost[i]<d[v])
            {
                updated=true;
                if(step==n)
                    neg_cycle=true;
                d[v]=d[u]+edge_cost[i];
           }
        }
        if(!updated)
            break;
    }
    if(!neg_cycle)
    {
        printf("Distance to node from source: \n");
        rep(i,n)
            cout<<i<<"  "<<d[i]<<endl;
    }
    else
        cout<<"Negative cycle detected\n";
}
