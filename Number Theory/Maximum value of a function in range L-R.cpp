const double eps = 1e-9;
long double f(double x)
{
    return //a*x*x+b*x+c.;
}
long double ternary_search(double l,double r)
{
    double m1,m2;
    while(r-l>eps)
    {
        m1=l+(r-l)/3.0;
        m2=r-(r-l)/3.0;
        f(m1)<f(m2)?r=m2:l=m1;
    }
    return f(l);
}
