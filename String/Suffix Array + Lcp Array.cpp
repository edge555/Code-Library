int SA[N],tempSA[N],n;
int RA[N],tempRA[N],c[N];
int LCP[N],PLCP[N],Phi[N];
char str[N];
void counting_sort(int k)
{
    int i,sum,maxi=max(300,n);
    mem(c,0);
    rep0(i,n)
    {
        int a=i+k<n?RA[i+k]:0;
        c[a]++;
    }
    for(i=0,sum=0;i<maxi;i++)
    {
        int x=c[i];
        c[i]=sum;
        sum+=x;
    }
    rep0(i,n)
    {
        int a=SA[i]+k<n?RA[SA[i]+k]:0;
        int b=c[a];
        c[a]++;
        tempSA[b]=SA[i];
    }
    rep0(i,n)
        SA[i]=tempSA[i];
}
void build_Suffix_Array()
{
    int i,k;
    rep0(i,n)
    {
        RA[i]=str[i];
        SA[i]=i;
    }
    for(k=1;k<n;k*=2)
    {
        counting_sort(k);
        counting_sort(0);
        int r=0;
        tempRA[SA[0]]=r=0;
        for(i=1; i<n; i++)
        {
            if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])
                tempRA[SA[i]]=r;
            else
                tempRA[SA[i]]=++r;
        }
        rep0(i,n)
            RA[i]=tempRA[i];
        if(RA[SA[n-1]]==n-1)
            break;
    }
}
void build_LCP()
{
    int i,L;
    Phi[SA[0]]=-1;
    for(i=1; i<n; i++)
        Phi[SA[i]]=SA[i-1];
    for(i=0,L=0;i<n; i++)
    {
        if(Phi[i]==-1)
        {
            PLCP[i]=0;
            continue;
        }
        while(str[i+L]==str[Phi[i]+L])
            L++;
        PLCP[i]=L;
        L=max(L-1,0);
    }
    rep0(i,n)
        LCP[i]=PLCP[SA[i]];
}
 int main()
{
    int t,tc;
    sf(tc);
    rep(t,tc)
    {
        scanf("%s",str);
        strcat(str,"$");
        n=strlen(str);
        build_Suffix_Array();
        build_LCP();
    }
}
