int ara[N],dp[N];
int main()
{
    int i,n,k;
    cin>>n>>k;
    rep(i,n)
        cin>>ara[i];
    deque<pair<int,int> >deq;
    rep(i,n)
    {
        if(!deq.empty() && deq.front().se<=i-K)
            deq.pop_front();
        while(!deq.empty() && deq.back().fi>=ara[i])
            deq.pop_back();
            // Change '>=' to '<=' for maximum value .
        deq.pb(make_pair(ara[i],i));
        if(i-k>=0)
            dp[i-k]=deq.front().fi ;
    }
    for(i=0;i<=N-K;i++)
        printf("%d ",dp[i]);
}
