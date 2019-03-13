int table[N][17];
int ara[N],k=17,n;
void sparse()
{
    int i,j;
    for(i=0;i<n;i++)
        table[i][0]=ara[i];
    for(j=1;j<=k;j++)
    {
        for(i=0;i<=n-(1<<j);i++)
        //table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))][j-1]);->max
        //table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);->min
    }
}
int query(int L,int R)
{
    int j,ans=-1;
    for(j=k;j>=0;j--)
    {
        if(L+(1<<j)-1<=R)
        {
            //ans=max(ans,table[L][j]);->max
            //ans=min(ans,table[L][j]);->min
            L+=1<<j;
        }
    }
    return ans;
}
int main()
{
    sparse();
    query(L,R);
}
