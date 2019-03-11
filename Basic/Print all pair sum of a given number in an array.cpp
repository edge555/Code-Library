void printPairs(int ara[],int n,int sum)
{
    unordered_map<int,int>mp;
    int i,j;
    for(i=0;i<n;i++)
    {
        int rem=sum-ara[i];
        if(mp.find(rem)!=mp.end())
        {
            int cnt=mp[rem];
            for(j=0;j<cnt;j++)
                cout<<rem<<" "<<ara[i]<<endl;
        }
        mp[ara[i]]++;
    }
}
int main()
{
    int n,i;
    cin>>n;
    int ara[n+1],sum;
    for(i=0;i<n;i++)
        cin>>ara[i];
    cin>>sum;
    printPairs(ara,n,sum);
}
