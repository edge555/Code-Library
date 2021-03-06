string a,b,s;
int dp[N][N];
int calLcs(int i,int j)
{
    if(i==a.size() || j==b.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(a[i]==b[j])
        ans=1+calLcs(i+1,j+1);
    else
        ans=max(calLcs(i,j+1),calLcs(i+1,j));
    return dp[i][j]=ans;
}
void print(int i,int j)
{
    if(i==a.size() || j==b.size())
    {
        cout<<s<<endl;
        return;
    }
    if(a[i]==b[j])
    {
        s+=a[i];
        print(i+1,j+1);
    }
    else
    {
        if(dp[i][j+1]>dp[i+1][j])
            print(i,j+1);
        else
            print(i+1,j);
    }
}
int main()
{
    int t;
    sf(t);
    getchar();
    while(t--)
    {
        mem(dp,-1);
        cin>>a>>b;
        int ans=calLcs(0,0);
        s="";
        print(0,0);
    }
}