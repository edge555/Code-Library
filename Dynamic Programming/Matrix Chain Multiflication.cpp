int row[N],col[N];
int dp[N][N];
bool vis[N][N];
int func(int beg,int end)
{
    if(beg>=end)
        return 0;
    if(vis[beg][end])
        return dp[beg][end];
    int ans=1<<30,mid;
    for(mid=beg;mid<end;mid++)
    {
        int opr_left=f(beg,mid);
        int opr_right=f(mid+1,end);
        int opr_to_multify_left_and_right=row[beg]*col[mid]*col[end];
        int total=opr_left+opr_right+opr_to_multify_left_and_right;
        ans=min(ans,total);
    }
    vis[beg][end]=1;
    dp[beg][end]=ans;
    return dp[beg][end];
}
int main()
{
    int i,n;
    cin>>n;
    rep0(i,n)
        cin>>row[i]>>col[i];
    cout<<func(0,n-1);
}
