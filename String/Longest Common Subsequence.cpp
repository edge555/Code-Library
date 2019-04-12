int calcLCS(int a[],int b[],int i,int j)
{
	if(i==n || j==m)
        return 0;
	if(visited[i][j])
        return dp[i][j];
	int ans=0;
	if(a[i]==b[j])
        ans=1+calcLCS(a,b,i+1,j+1);
	else
	{
        int val1=calcLCS(a,b,i+1,j);
        int val2=calcLCS(a,b,i,j+1);
        ans=max(val1,val2);
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}
