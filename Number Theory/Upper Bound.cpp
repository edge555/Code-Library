int upper_bound(int n, int x)
{
    int low=0,high=n;
    while (low<high)
    {
        int mid=(low+high)/2;
        if (x>=a[mid])
            low=mid+1;
        else
            high=mid;
    }
    return low;
}
