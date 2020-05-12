int a[N],c[N],d[N];
int bs(int *a,int len,int n)
{
    int right=len,left=0,mid=(left+right)/2;
    while(left<=right)
    {
        if(n>a[mid])
            left=mid+1;
        else if(n<a[mid])
            right=mid-1;
        else
            return mid;
        mid=(left+right)/2;
    }
    return left;
}
int main()
{
    int n,m,i,j,mid,len;
    sff(n,m);
    for(i=1;i<=n;i++)
    {
        sf(a[i]);
        c[a[i]]=i;
    }
    for(i=1;i<=m;i++)
    {
        sf(a[i]);
        a[i]=c[a[i]];
    }
    d[1]=a[1];
    d[0]=-1;
    len=1;
    for(i=1;i<=m;i++)
    {
        j=bs(d,len,a[i]);
        d[j]=a[i];
        if(j>len)
            len=j;
    }
    pf("%d",len);
}