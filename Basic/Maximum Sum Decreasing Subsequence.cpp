int maxSumDS(int ara[], int n)
{
    int i,j,mx=0,MSDS[n];
    for(i=0;i<n;i++)
        MSDS[i]=ara[i];
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(ara[i]<ara[j] && MSDS[i]<MSDS[j]+ara[i])
                MSDS[i]=MSDS[j]+ara[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(mx<MSDS[i])
            mx=MSDS[i];
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    int ara[n+1],i;
    for(i=0;i<n;i++)
        cin>>ara[i];
    cout<<maxSumDS(ara,n);
}
