int CutRod(int cost[],int n)
{
    int val[n+1],i,j;
    val[0]=0;
    rep(i,n)
    {
        int ans=INT_MIN;
        for(j=0;j<i;j++)
        	ans=max(ans,cost[j]+val[i-j-1]);
        val[i]=ans;
    }
    return val[n];
}
