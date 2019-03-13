int n;
struct Node
{
    vector<int>adj;
};
Node grid[N];
bool mark[N];
bool dfs(int start)
{
    stack<int>s,prev;
    s.push(start);
    prev.push(-1);
    while(!s.empty())
    {
        int i,xt=s.top(),pt=prev.top();
        s.pop();
        prev.pop();
        mark[xt]=true;
        rep0(i,grid[xt].size())
        {
            if(!mark[grid[xt].adj[i]])
            {
                s.push(grid[xt].adj[i]);
                prev.push(xt);
                mark[grid[xt].adj[i]]=true;
            }
            else if(grid[xt].adj[i]!=pt)
                return true;
        }
    }
    return false;
}
bool hasCycle(int n)
{
    rep0(i,n)
    {
        if(!mark[i])
        {
            if(dfs(i))
                return true;
        }
    }
    return false;
}
//if(hasCycle(n))puts("Yes"):puts("No")
