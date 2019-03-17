int LCIS(int arr1[],int n,int arr2[],int m)
{
    int table[m],parent[m],i,j;
    for(j=0;j<m;j++)
        table[j]=0;
    for(i=0;i<n;i++)
    {
        int current=0,last=-1;
        for(j=0;j<m;j++)
        {
            if (arr1[i]==arr2[j])
            {
                if (current+1>table[j])
                {
                    table[j]=current + 1;
                    parent[j]=last;
                }
            }
            if(arr1[i]>arr2[j])
            {
                if(table[j]>current)
                {
                    current=table[j]; last=j;
                }
            }
        }
}
 int result=0,index=-1;
 for(i=0;i<m;i++)
 {
       if(table[i]>result)
       {
           result=table[i];
           index=i;
        }
 }
 int lcis[result];
 for(i=0;index!=-1;i++)
{
        lcis[i]=arr2[index];
        index=parent[index];
}
cout<<"The LCIS is : ";
for(i=result-1;i>=0;i--)
        printf ("%d ",lcis[i]);
    return result;
    //result = LCIS
}
