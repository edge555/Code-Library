/*
 Uses:
   (1) solving systems of linear equations (AX=B)
   (2) inverting matrices (AX=I)
   (3) computing determinants of square matrices
 Running time: O(n^3)
 INPUT:    a[][] = an nxn matrix
           b[][] = an nxm matrix
           A MUST BE INVERTIBLE!
 OUTPUT:   X      = an nxm matrix (stored in b[][])
           A^{-1} = an nxn matrix (stored in a[][])
          returns determinant of a[][]
*/
const double EPS=1e-10;
typedef vector<int>VI;
typedef double T;
typedef vector<T>VT;
typedef vector<VT>VVT;
T GaussJordan(VVT &a, VVT&b)
{
    const int n=a.size();
    const int m=b[0].size();
    VI irow(n),icol(n),ipiv(n);
    T det=1;
    int i,j,k;
    rep0(i,n)
    {
        int pj=-1,pk=-1;
        rep0(j,n)
        {
            if(!ipiv[j])
            {
                rep0(k,n)
                {
                    if(!ipiv[k])
                    {
                        if(pj==-1 || fabs(a[j][k])>fabs(a[pj][pk]))
                        {
                            pj=j;
                            pk=k;
                        }
                    }
                }
            }
        }
        if(fabs(a[pj][pk])<EPS)
            return 0;
        ipiv[pk]++;
        swap(a[pj],a[pk]);
        swap(b[pj],b[pk]);
        if(pj!=pk)
            det*=-1;
        irow[i]=pj;
        icol[i]=pk;
        T c=1.0/a[pk][pk];
        det*=a[pk][pk];
        a[pk][pk]=1.0;
        rep0(p,n)
            a[pk][p]*=c;
        rep0(p,m)
            b[pk][p]*=c;
        rep0(p,n)
        {
            if(p!=pk)
            {
                c=a[p][pk];
                a[p][pk]=0;
                rep0(q,n)
                    a[p][q]-=a[pk][q]*c;
                rep0(q,m)
                    b[p][q]-=b[pk][q]*c;
            }
        }
    }
    for(p=n-1;p>=0;p--)
    {
        if(irow[p]!=icol[p])
        {
            rep0(k,n)
                swap(a[k][irow[p]],a[k][icol[p]]);
        }
    }
    return det;
}
