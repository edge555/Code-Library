int search(int a[],int i,int j,int key)
{
    int mid=(i+j)/2;
    if(j<i)
        return j;
    else
        if(a[mid]>key)
            search(a,i,mid-1,key);
        else
            search(a,mid+1,j,key);
}
int LIS_len(int a[],int size)
{
    int i,j,len[size];
    rep0(i,size)
        len[i] = 1;
    for(i=1;i<size;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j] && len[i]<len[j]+1)
                len[i]=len[j]+1;
        }
    }
    cout<<"Length: "<<len[size-1];
}
void LIS_printAndlen(int a[],intsize)
{
    int s[size],p,k;
    int i,j=-1;
    rep0(i,size+1)
        s[i]=0;
    rep0(i,size+1)
    {
        if(j==-1)
            s[++j]=a[i];
        else
        {
            if(s[j]<a[i])
                s[++j]=a[i];
            else
            {
                p=search(s,0,j,a[i]);
                s[p+1]=a[i];
            }
        }
    }
    cout<<"Subsequence: \n";
    for(i=0;i<=j;i++)
        cout<<s[i]<<" ";
    cout<<"\nLength: "<<j+1;
}
int main()
{
	LIS_len(a,size); //n^2
    LIS_printAndlen(a,size-1) //nLogn
}
