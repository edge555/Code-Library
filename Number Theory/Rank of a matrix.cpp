/*
   INPUT:   a[][]=an nxn matrix
   OUTPUT:  rref[][]=an nxm matrix(stored in a[][])
            returns rank of a[][]
*/
const double EPSILON=1e-10;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
int rref(VVT &a)
{
    int n=a.size(),r=0,j;
    int m=a[0].size(),i,c;
    rep0(c,m)
    {
        j=r;
        for(i=r+1;i<n;i++)
        {
            if(fabs(a[i][c])>fabs(a[j][c]))
                j=i;
        }
        if(fabs(a[j][c])<EPSILON)
            continue;
        swap(a[j],a[r]);
        T s=1.0/a[r][c];
        rep0(j,m)
            a[r][j]*=s;
        rep0(i,n)
        {
            if(i!=r)
            {
                T t=a[i][c];
                rep0(j,m)
                    a[i][j]-=t*a[r][j];
            }
        }
        r++;
    }
    return r;
}
