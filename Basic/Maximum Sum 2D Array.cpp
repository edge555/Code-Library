int ara[100][100];
int temp[100];
int st,fin;
int kadane1D(int a[],int n)
{
    int maxfar=0,maxend=0,i,s=0;
    for(i=0;i<n;i++)
    {
        maxend+=a[i];
        if(maxend<0)
        {
            maxend=0;
            s=i+1;
        }
        else if(maxend>maxfar)
        {
            maxfar=maxend;
            st=s;
            fin=i;
        }
    }
    return maxfar;
}
int kadane2D(int m,int n)
{
    int left,right,sum=0,maxsum=0,i,j;
    int l,r,ub,lb;
    for(left=0;left<n;left++)
    {
        mem(temp,0);
        for(right=left;right<n;right++)
        {
            for(i=0;i<n;i++)
                temp[i]+=ara[i][right];
            sum=kadane1D(temp,m);
            if(sum>maxsum)
            {
                maxsum=sum;
                l=left;
                r=right;
                ub=st;
                lb=fin;
            }
        }
    }
     printf("\nMaximum sum of contiguous submatrix = %d\n",maxsum);
     printf("\nLeftTopIndex = (%d,%d)\tRightBottomIndex = (%d,%d)\n\n",ub,l,lb,r);
     for(i=ub;i<=lb;i++,printf("\n"))
     {
        for(j=l;j<=r;j++)
            printf("%d ",ara[i][j]);
     }
}
int kadaneNeg(int m,int n)
{
    int i,j,l=INT_MIN,x,y;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if (ara[i][j]>l)
            {
          	   l=ara[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("\nMaximum sum of contiguous submatrix = %d at index (%d,%d)\n",l,x,y);
}
int main()
{
    int m,n,i,j,p=0,k;
    cin>>m>>n;
    cout<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ara[i][j];
            if(ara[i][j]>0)
                p++;
        }
    }
    if(p==0)
        kadaneNeg(m,n);
    else
        k=kadane2D(m,n);
}
