int bs(int low,int high,int num)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ara[mid]==num)
            return mid;
        else if(num>ara[mid])
            low=mid+1;
        else if(num<ara[mid])
            high=mid-1;
    }
    return -1;
}
