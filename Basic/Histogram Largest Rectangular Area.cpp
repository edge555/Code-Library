int hist(int ara[],int k)
{
    stack<int>s;
    int top,i=0,maxarea=0,toparea;
    while (i<k)
    {
        if(s.empty() || ara[s.top()]<=ara[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            top=s.top();
            s.pop();
            toparea=ara[top] * (s.empty()? i:i-s.top()-1);
            maxarea=max(toparea,maxarea);
        }
    }
    while(!s.empty())
    {
        top=s.top();
        s.pop();
        toparea=ara[top]*(s.empty()?i:i-s.top()-1);
        maxarea=max(maxarea,toparea);
    }
    return maxarea;
}
int main()
{
    int i,n,ara[100000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>ara[i];
    int res=hist(ara,n);
    cout<<res;
}
