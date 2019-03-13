#define inf 0x7fffffff
int arr[N],tree[4*N],lazy[4*N];
void build(int node,int a,int b)
{
    if(a>b)
        return;
    if(a==b)
    {
        tree[node]=arr[a];
        return;
    }
    int mid=(a+b)/2;
    build(node*2,a,mid);
    build(node*2+1,1+mid,b);
    //tree[node]=max(tree[node*2],tree[node*2+1]); -> max
    //tree[node]=min(tree[node*2],tree[node*2+1]); -> min
}
void update(int node,int a,int b,int i,int j,int value)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(a!= b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(a>b || a>j || b<i)
        return;
    if(a>=i && b<=j)
    {
        tree[node]+=value;
        if(a!=b)
        {
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }
    int mid=(a+b)/2;
    update(node*2,a,mid,i,j,value);
    update(1+node*2,1+mid,b,i,j,value);
    //tree[node]=max(tree[node*2],tree[node*2+1]); ->max
    //tree[node]=min(tree[node*2],tree[node*2+1]); ->min
}
int query(int node,int a,int b,int i,int j)
{
    if(a>b || a>j || b<i)
        //return -inf; -> max
        //return inf; -> min
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(a>=i && b<=j)
        return tree[node];
    int mid=(a+b)/2;
    int q1=query(node*2,a,mid,i,j);
    int q2=query(1+node*2,1+mid,b,i,j);
    //int res=max(q1,q2); -> max
    //int res=min(q1,q2); -> min
    return res;
}
int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1);
    mem(lazy,0);
    //update(1,0,n-1,a,b,v)
    //query(1,0,n-1,a,b)
}
