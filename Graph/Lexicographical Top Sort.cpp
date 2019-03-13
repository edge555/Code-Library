vector<int>grid[N];
map<int,int>indeg;
queue<int>q;
priority_queue<int,vector<int>,greater<int> >pq;
void topsort(int n)
{
    int i;
    rep(i,n)
    {
        if(!indeg[i])
            pq.push(i);
    }
    while(!pq.empty())
    {
        int k=pq.top();
        pq.pop();
        q.push(k);
        rep0(i,grid[k].size())
        {
            int p=grid[k][i];
            indeg[p]--;
            if(!indeg[p])
                pq.push(p);
        }
    }
}
int main()
{
    int n,m, i,a,k,b;
    sff(n,m);
    rep0(i,m)
    {
        sff(a,k);
        while(k--)
        {
            sf(b);
            grid[b].pb(a);
            indeg[a]++;
        }
    }
    topsort(n);
    pf("%d",q.front());
    q.pop();
    while(!q.empty())
    {
        pf(" %d",q.front());
        q.pop();
    }
