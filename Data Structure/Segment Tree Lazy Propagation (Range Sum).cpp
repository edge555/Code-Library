ll arr[N];
struct node
{
    ll sum,prop;
}tree[4*N];
void build(ll cur,ll st,ll en)
{
    if(st>en)
        return;
    if(st==en)
    {
        tree[cur].sum=arr[st];
        tree[cur].prop=0;
        return;
    }
    ll mid=(st+en)/2;
    ll left=2*cur,right=left+1;
    build(left,st,mid);
    build(right,1+mid,en);
    tree[cur].sum=tree[left].sum+tree[right].sum;
    tree[cur].prop=0;
}
void update(ll cur,ll st,ll en,ll l,ll r,ll val)
{
    if(tree[cur].prop)
    {
        tree[cur].sum+=(en-st+1)*tree[cur].prop;
        if(st!=en)
        {
            tree[2*cur].prop+=tree[cur].prop;
            tree[2*cur+1].prop+=tree[cur].prop;
        }
        tree[cur].prop=0;
    }
    if(st>en || st>r || en<l)
        return;
    if(st>=l && en<=r)
    {
        tree[cur].sum+=(en-st+1)*val;
        if(st!=en)
        {
            tree[2*cur].prop+=val;
            tree[2*cur+1].prop+=val;
        }
        return;
    }
    ll mid=(st+en)/2;
    ll left=2*cur,right=left+1;
    update(left,st,mid,l,r,val);
    update(right,mid+1,en,l,r,val);
    tree[cur].sum=tree[left].sum+tree[right].sum;
}
ll query(ll cur,ll st,ll en,ll l,ll r)
{
    if(st>en || st>r || en<l)
        return 0;
    if(tree[cur].prop!=0)
    {
        tree[cur].sum+=(en-st+1)*tree[cur].prop;
        if(st!=en)
        {
            tree[2*cur].prop+=tree[cur].prop;
            tree[2*cur+1].prop+=tree[cur].prop;
        }
        tree[cur].prop=0;
    }
    if(st>=l && en<=r)
        return tree[cur].sum;
    ll mid=(st+en)/2;
    ll left=2*cur,right=left+1;
    ll ans1=query(left,st,mid,l,r);
    ll ans2=query(right,mid+1,en,l,r);
    return ans1+ans2;
}
/*
    0 - Indexed
    query(1,0,n-1,a,b)
    update(1,0,n-1,a,b,v)
*/
