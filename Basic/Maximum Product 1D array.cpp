int maxpro(int ara[],int n)
{
    int minVal=ara[0],maxVal=ara[0];
    int maxpro=ara[0];

    for (int i=1;i<n;i++)
    {
        if (ara[i]<0)
            swap(maxVal, minVal);
        maxVal=max(ara[i],maxVal*ara[i]);
        minVal=min(ara[i],minVal*ara[i]);
        maxpro=max(maxpro,maxVal);
    }
    return maxpro;
}

int main()
{
    int n,i;
    cin>>n;
    int ara[n+1];
    for (i=0;i<n;i++)
        cin>>ara[i];
    cout<<maxpro(ara,n)<<endl;
}
