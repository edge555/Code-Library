string a;
int min(int a,int b)
{
    int res=a;
    if(b<a)
        res=b;
    return res;
}
void findLongestPalindromicString()
{
    int N=a.size();
    if(N==0)
        return;
    N=2*N+1;
    int L[N];
    L[0]=0;
    L[1]=1;
    int C=1,R=2,i=0;
    int iMirror,maxLPSLength=0,maxLPSCenterPosition=0;
    int start=-1,endd=-1,diff=-1;

    for (i=2;i<N;i++)
    {
        iMirror=2*C-i;
        L[i]=0;
        diff=R-i;
        if(diff>0)
            L[i]=min(L[iMirror],diff);
        while ( ( (i+L[i])<N && (i-L[i])>0) && ( ( (i+L[i] +1)%2==0) ||
            (a[(i+L[i]+1)/2]==a[(i-L[i]-1)/2]) ) )
           {
                L[i]++;
           }
        if(L[i]>maxLPSLength)
        {
            maxLPSLength=L[i];
            maxLPSCenterPosition=i;
        }
        if (i+L[i]>R)
        {
            C=i;
            R=i+L[i];
        }
    }
    start=(maxLPSCenterPosition-maxLPSLength)/2;
    endd=start+maxLPSLength-1;
    a=a.substr(start,endd);
    cout<<a<<endl;
}
int main()
{
    cin>>a;
    findLongestPalindromicString();
}
