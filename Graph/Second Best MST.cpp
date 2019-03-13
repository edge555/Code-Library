void secondmst()
{
    int i,j;
    rep0(i,vec.size())
    {
        if(vec[i].taken==true)
        {
            setpar();
            int temp=vec[i].w,cost=0,cnt=0;
            vec[i].w=INT_MAX;
            rep0(j,vec.size())
            {
                int u=findpar(vec[j].u);
                int v=findpar(vec[j].v);
                if(u!=v && vec[j].w!=INT_MAX)
                {
                    par[u]=v;
                    cost+=vec[j].w;
                    cnt++;
                }
            }
            if(cnt==n-1)
                ans.pb(cost);
            vec[i].w=temp;
        }
    }
    sort(all(ans));
    cout<<ans[0];
}
