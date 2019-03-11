int calc(int arr[], int n)
{
    int minend=INT_MAX;
    int minfar=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(minend>0)
            minend=arr[i];
        else
            minend+=arr[i];
        minfar=min(minfar,minend);
    }
    return minfar;
}
int main()
{
    int i,n;
    cin>>n;
    int ara[n+1];
    for(i=0;i<n;i++)
        cin>>ara[i];
    cout<<"Smallest sum: "<<calc(ara,n);
}
