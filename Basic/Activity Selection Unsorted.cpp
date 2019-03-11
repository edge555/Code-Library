struct act
{
    int st;
    int fn;
}s[100000];
bool func(act a,act b)
{
    return (a.fn < b.fn);
}
void acu(act a[],int n)
{
    int i=0,j;
    sort (a,a+n,func);
    cout<<endl<<"Selected activities:"<<endl<<endl;
    cout<<" Start"<<"   "<<"End"<<endl;
    cout<<a[i].st<<" ---> "<<a[i].fn<<endl;
    for (j=1;j<n;j++)
    {
        if (a[j].st>=a[i].fn)
        {
            cout<<a[j].st<<" ---> "<<a[j].fn<<endl;
            i=j;
        }
    }
}
int main(){
    int n,i;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>s[i].st;
    for (i=0;i<n;i++)
        cin>>s[i].fn;
    acu(s,n);
}
