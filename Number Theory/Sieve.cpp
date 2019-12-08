bool mark[N];
void sieve()
{
    int i,j;
    memset(mark,true,sizeof(mark));
    for(i=4;i<N;i+=2)
        mark[i]=false;
    for(i=3;i*i<N;i+=2)
    {
        if(mark[i])
        {
            for(j=i*i;j<N;j+=i*2)
                mark[j]=false;
        }
    }
    mark[1]=false;
    //if(mark[n]) -> Prime
}
