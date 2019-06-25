const int MAX=100000000;
const int LMT=10000;
int flag[MAX>>6];
#define chkbit(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define setbit(x) (flag[x>>6]|=(1<<((x>>1)&31)))
bool prime(int n)
{
    return (n&1 && n!=1 && !chkbit(n)) || n==2;
}
void sieve()
{
    long long int i,j,k;
    for(i=3;i<LMT;i+=2)
    {
        if(!chkbit(i))
        {
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setbit(j);
        }
    }
    /// if(prime(i))=prime
}
