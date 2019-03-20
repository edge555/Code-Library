struct Item
{
    int value,weight;
};
bool cmp(struct Item a, struct Item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fracknap(int W,struct Item ara[],int n)
{
    sort(ara,ara+n,cmp);
    int cur=0,i;
    double sum=0.0;
    for(i=0;i<n;i++)
    {
        if (cur+ara[i].weight<=W)
        {
            cur+=ara[i].weight;
            sum+=ara[i].value;
        }
        else
        {
            int rem=W-cur;
            sum+=ara[i].value*((double)rem/ara[i].weight);
            break;
        }
    }
    return sum;
}
