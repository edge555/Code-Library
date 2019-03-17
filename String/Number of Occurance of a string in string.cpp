int res(string a,string b)
{
    int m=b.size();
    int n=a.size();
    if (m>n)
        return 0;
    int mat[m+1][n+1];
    int i,j;
    for (i=1;i<=m;i++)
        mat[i][0]=0;
    for (j=0;j<=n;j++)
        mat[0][j]=1;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (b[i-1]!=a[j-1])
                mat[i][j]=mat[i][j-1];
            else
                mat[i][j]=mat[i][j-1]+mat[i-1][j-1];
        }
    }
    return mat[m][n];
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
      string a,b; //searching a in b
      cin>>a>>b;
      cout<<res(b,a)<<endl;
    }
}
