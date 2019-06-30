unordered_map<ll,bool>mp;
ll gethash(string ar)
{
    ll p=10003193;
    ll now=1,hsh=0;
    for(int i=0;i<ar.size();i++)
    {
        hsh=now*hsh+ar[i]-'a';
        now*=p;
    }
    return hsh;
}
int main()
{
    FAST;
    int n,m,i;
    cin>>n;
    ll p=10003193;
    for(i=0;i<n;i++)
    {
        string a;
        cin>>a;
        ll now=gethash(a);
        mp[now]=true;
    }
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        ll now=gethash(s);
        if(mp[now]) -> Yes
    }
}
