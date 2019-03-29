pi gcd(int a,int b)
{
    if(b==0)
        return {(1,0)};
    else
    {
        int p=a/b;
        pi q=gcd(b,a%b);
        return {(q.se,q.fi-q.se*p)};
    }
}
