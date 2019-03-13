int prefM[N][N],rankW[N][N];
int options[N],marriedTo[N];
queue<int>bachelor;
void stableMarriage()
{
    mem(marriedTo,-1);
    int man,woman,husband,j;
    while(!bachelor.empty())
    {
        man=bachelor.front();
        bachelor.pop();
        bool friendZoned=true;
        for(j=options[man]-1;j>=0;j--)
        {
            woman=prefM[man][j];
            options[man]--;
            if(marriedTo[woman]==-1)
            {
                marriedTo[woman]=man;
                friendZoned=false;
                break;
            }

          else
            {
                husband=marriedTo[woman];
                if(rankW[woman][man]>rankW[woman][husband])
                {
                    marriedTo[woman]=man;
                    bachelor.push(husband);
                    friendZoned=false;
                    break;
                }
            }
        }
        if(friendZoned)
            bachelor.push(man);
    }
}
int main()
{
    int i,j,n,tc;
    cin>>tc;
    int man,woman;
    while(tc--)
    {
        cin>>n;
        rep(i,n)
        {
            cin>>woman;
            for(j=n-1;j>=0;j--)
            {
                cin>>man;
                rankW[woman][man]=j;
            }
        }
        rep(i,n)
        {
            cin>>manl
            bachelor.push(man);
            options[man]=n;
            for(j=n-1;j>=0;j--)
                cin>>prefM[man][j];
        }
        stableMarriage();
        rep(i,n)
            printf("%d %d\n", marriedTo[i], i);
    }
}
