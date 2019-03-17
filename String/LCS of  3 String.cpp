int lcsOf3(string X,string Y,string Z,int m,
int n,int o)
{
    int L[m+1][n+1][o+1];
    int i,j,k;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=o;k++)
            {
                if (i==0 || j==0||k==0)
                    L[i][j][k]=0;
                else if (X[i-1]==Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k]=L[i-1][j-1][k-1]+1;
                else
                    L[i][j][k]=max(max(L[i-1][j][k],
                            L[i][j-1][k]),L[i][j][k-1]);
            }
        }
    }
    return L[m][n][o];
}
