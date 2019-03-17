int dp[N][N],t;
set<string>seq;
map<string,bool>done[N][N];
void backtrack(string s1,string s2,int i,int j,string word)
{
    if(done[i][j].find(word)!=done[i][j].end())
        return;
    if(i==0 || j==0)
        seq.insert(word);
    else if(s1[i-1]==s2[j-1])
    {
        word=s1[i-1]+word;
        backtrack(s1,s2,i-1,j-1,word);
    }
    else if(dp[i][j-1]>dp[i-1][j])
        backtrack(s1,s2,i,j-1,word);
    else if(dp[i-1][j]>dp[i][j-1])
        backtrack(s1,s2,i-1,j,word);
    else
    {
        backtrack(s1,s2,i,j-1,word);
        backtrack(s1,s2,i-1,j,word);
    }
    done[i][j][word]=true;
}
void lcs(string a,string b)
{
    int n=a.length(),i;
    int m=b.length(),j;

    rep0(i,n+1)
        dp[i][0]=0;
    rep0(i,m+1)
        dp[0][i]=0;
    rep(i,n)
    {
        rep(j,m)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
           else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    backtrack(a,b,n,m,"");
}
int main()
{
    cin>>t;
    char c_s1[81],c_s2[81];
    string s1,s2;
    while(t--)
    {
        seq.clear();
        scanf("%s %s", c_s1, c_s2);
        s1=c_s1;
        s2=c_s2;
        lcs(s1,s2);
        for(auto it=seq.begin();it!=seq.end();it++)
            printf("%s\n",it->c_str());
    }
}
