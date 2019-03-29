bool vis[N][N];
double dp[N][N],ar[N][N];
if(x<n&&y<m)
    //valid
double f(int i,int j)
{
    if(i==n-1&&j==m-1)
        return ar[i][j];
    if(vis[i][j]true)
        return dp[i][j];
    vis[i][j]=true;
    double value=ar[i][j],cnt = 0;
    if(valid(i+1,j))
        cnt++;
    if(valid(i,j+1))
        cnt++;
    if(valid(i+1,j+1))
        cnt++;
    if(valid(i+1,j))
        value+=f(i+1,j)/cnt;
    if(valid(i,j+1))
        value+=f(i,j+1)/cnt;
    if(valid(i+1,j+1))
        value+=f(i+1,j+1)/cnt;
    return dp[i][j]=value;
}
//mem(vis,false) every testcase
