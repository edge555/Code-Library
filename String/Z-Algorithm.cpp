void getZarr(string str,int Z[])
{
    int n=str.length(),i,L,R,k;
    L=R=0;
    for(i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while (R<n && str[R-L]==str[R])
                R++;
            Z[i] = R-L;
            R--;
        }

         else
        {
            k = i-L;
            if(Z[k]<R-i+1)
                Z[i]=Z[k];
            else
            {
                L=i;
                while(R<n && str[R-L]==str[R])
                    R++;
                Z[i]=R-L;
                R--;
            }
        }
    }
}
void search(string text,string pattern)
{
    string concat=pattern+"$"+text;
    int l=concat.length(),Z[l];
    getZarr(concat,Z);
    for(i=0;i<l;++i)
    {
        if (Z[i]= pattern.length())
            cout<<"Pattern found at index "
                <<i -pattern.length()-1<<endl;
    }
}
//search(fullstring,substring)
