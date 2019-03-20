const int INF=1234567;
int n,k,mx;
int dp[303],ar[55],ans[303];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t,c=0,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<303;i++)
            dp[i]=INF;
        mem(ans,-1);
        dp[0]=0;
        for(i=0;i<n;i++)
            cin>>ar[i];
        for(i=0;i<n;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(j-ar[i]>=0)
                {
                    int temp=dp[j-ar[i]]+1;
                    if(temp<dp[j])
                    {
                        dp[j]=temp;
                        ans[j]=i;
                    }
                    else if(temp==dp[j])
                    {
                        if(ar[ans[j]]<ar[i])
                            ans[j]=i;
                    }
                }
            }
        }
        printf("Case %d: ",++c);
        if(dp[k]==INF)
            puts("impossible");
        else
        {
            printf("[%d]",dp[k]);
            vector<int>v;
            int d=dp[k];
            while(d--)
            {
                v.push_back(ar[ans[k]]);
                k-=ar[ans[k]];
            }
            sort(v.begin(),v.end(),cmp);
            for(i=0;i<v.size();i++)
                printf("% d",v[i]);
            printf("\n");
        }
    }
}
