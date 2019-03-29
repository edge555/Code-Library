int gcd(int a,int b);
int power(int x,unsigned int y,unsigned int m);
void modInverse(int a,int m)
{
    int g=gcd(a, m);
    if (g!=1)
        cout<<"Inverse doesn't exist";
    else
        cout<<"Modular multiplicative inverse is "<<power(a,m-2,m);
}
int power(int x,unsigned int y,unsigned int m)
{
    if (y == 0)
        return 1;
    int p=power(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int a,m;
    cin>>a>>m;
    modInverse(a,m);
}
