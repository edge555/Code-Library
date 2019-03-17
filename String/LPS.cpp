string a,b;
string lcs(string X, string Y)
{
    int m=X.length(),n=Y.length();
    int L[m+1][n+1],i,j;
    for (i=0;i<=m;i++)
    {
        for (j=0;j<=n;j++)
        {
            if (i==0 || j==0)
                L[i][j]=0;
            else if (X[i-1]==Y[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    int index=L[m][n], i=m,j=n;
    string lcs(index+1,'\0');
    while (i>0 && j>0)
    {
        if (X[i-1]==Y[j-1])
        {
            lcs[index-1]=X[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j]>L[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}
int main()
{
    cin>>a;
    b=reverse(all(a));
    cout<lcs(a,b);
}
