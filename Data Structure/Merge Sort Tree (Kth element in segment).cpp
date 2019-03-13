const int LIM=263005;
int ara[N];
vector<pi>vec;
vector<int>seg[LIM];
void build(int t,int i,int j)
{
    if(i==j)
    {
        seg[t].pb(vec[i].second);
        return ;
    }
    int left=t<<1,right=left|1,mid=(i+j)/2;
	build(left,i,mid);
	build(right,mid+1, j);
	merge(seg[left].begin(),seg[left].end(),seg[right].begin(),seg[right].end(),back_inserter(seg[t]));
}
int query_kth(int t,int i,int j,int l,int r,int k)
{
    if(i==j)
        return seg[t][0];
    int left=t<<1,right=left|1,mid =(i+j)/2,total;
    auto it=upper_bound(seg[left].begin(),seg[left].end(),r);
    total=it-lower_bound(seg[left].begin(),seg[left].end(),l);
    if(total>=k)
        return query_kth(left,i,mid,l,r,k);
    else
        return query_kth(right,mid+1,j,l,r,k-total);
}
int main()
{
    int n,m,x,y,k,idx,ans;
    cin>>n>>m;
    rep0(i,n)
    {
        cin>>x;
        ara[i]=x;
        vec.pb(make_pair(x,i));
    }
    sort(all(vec));
    build(1,0,n-1);
    while (m--)
    {
        cin>>x>>y>>k;
        x--;y--;
        idx=query_kth(1,0,n-1,x,y,k);
        ans=ara[idx];
        cout<<ans<<endl;
    }
}
