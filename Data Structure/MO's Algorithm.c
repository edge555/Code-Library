int a[N],b[N],s;
int incElement(int index,int delta)
{
	a[index]+=delta;
	b[index/s]+=delta;
}
int decElement(int index,int delta)
{
	a[index]-=delta;
	b[index/s]=min(b[index/s],a[index]);
}

void querySum(int l,int r)
    {
	int sum=0,i;
    int nl=l/s,nr=r/s;
    if (nl==nr)
	for(i=l;i<=r;i++)
		sum+=a[i];
    else
    {
        for(i=l,end=(nl+1)*s-1;i<=end;i++)
            sum+=a[i];
        for(i=nl+1;i<=nr-1;i++)
            sum+=b[i];
        for(i=nr*s;i<=r;i++)
            sum+=a[i];
    }
    cout<<sum<<endl;
}
int main()
{
    int n,q,i;
    cin>>n>>q;
    s = sqrt(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i/s] += a[i];
    }
    while(q--)
    {
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int i,j;
            cin>>i>>j;
            querySum(i,j);
        }
        else if(choice==2)
        {
            int i,value;
            cin>>i>>value;
            incElement(i,value);
        }
        else
        {
            int i,value;
            cin>>i>>value;
            decElement(i,value);
        }
    }
}
