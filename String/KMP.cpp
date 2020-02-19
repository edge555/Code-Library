int fail[N];
void failure(string a)
{
    int i=1,j=0;
    fail[0]=0;
    while(i<a.size())
    {
        if(a[i]==a[j])
        {
            j++;
            fail[i]=j;
            i++;
        }
        else
        {
            if(j>0)
                j=fail[j-1];
            else
            {
                fail[i]=0;
                i++;
            }
        }
    }
}
int kmp(string text,string pat)
{
    int i=0,j=0,ind=-1,cnt=0;
    while(i<text.size())
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
            if(j==pat.size())
            {
                ind=i-pat.size();
                cnt++;
                j=fail[j-1];
            }
        }
        else
        {
            if(j)
                j=fail[j-1];
            else
                i++;
        }
    }
    return cnt;
}
main:
    string text,pat;
    cin>>text>>pat;
    failure(pat);
    //found if kmp(a,b)>0