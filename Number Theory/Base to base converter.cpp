#include <bits/stdc++.h>
using namespace std;
int val(char c)
{
    if(c>='0' && c<='9')
        return(int)c-'0';
    else
        return(int)c-'A'+10;
}
char reVal(int num)
{
    if(num>=0 && num<=9)
        return(char)(num+'0');
    else
        return(char)(num-10+'A');
}
int toDeci(string str,int base)
{
    int i,len=str.size();
    int power=1,num=0;
    for(i=len-1;i>=0;i--)
    {
        if(val(str[i])>=base)
        {
           printf("Invalid Number");
           return -1;
        }
        num+=val(str[i])*power;
        power=power*base;
    }

    return num;
}
string fromDeci(int base,int num)
{
    int index=0;
    string res="";
    while(num>0)
    {
        res+=reVal(num%base);
        num/=base;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int frombase,tobase;
    string a;
    cin>>a>>frombase>>tobase;
    cout<<fromDeci(tobase,toDeci(a,frombase));
}
