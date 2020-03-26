int lps(string str)
{
    int i,k,n=str.size();
    int L[n][n];
    rep0(i,n)
        L[i][i]=1;
    for(int k=2;k<=n;k++)
    {
        for(i=0;i<n-k+1;i++)
        {
            int j=i+k-1;
            if(str[i]== str[j] && k==2)
                L[i][j]=2;
            else if(str[i]==str[j])
                L[i][j]=L[i+1][j-1]+2;
            else
                L[i][j]=max(L[i][j-1],L[i+1][j]);
        }
    }
    return L[0][n-1];
}