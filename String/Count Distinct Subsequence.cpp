long long dp[N],last[200];
char str[N];
int main()
{
    int i,t,n;
    cin>>t;
    while(t--)
    {
        scanf("%s",str+1);
        mem(dp,0)
        mem(last,0)
        dp[0]=1;
        n=strlen(str+1);
        rep(i,n)
        {
            dp[i]=(dp[i-1]*2)%mod;
            if(last[str[i]])
                dp[i]=(dp[i]-dp[last[str[i]]-1]+mod)%mod;
            last[str[i]]=i;
         }
         cout<<dp[n]<<endl;
    }
}
