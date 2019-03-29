int lower_bound(int n, int x)
{
    int low=0,high=n;
    while (low<high)
    {
        int mid=(low+high)/2;
        if (x<=a[mid])
            high=mid;
        else
            low=mid+1;
    }
    return low;
}
