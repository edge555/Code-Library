int segcnt=0;
struct segment
{
    int l,r,lid,rid,sum;
}seg[2000000];
int build(int l,int r)
{
    if (l>r)
        return -1;
    int id=segcnt++;
    seg[id].l=l;
    seg[id].r=r;
    if(l==r)
    {
        seg[id].lid=-1;
        seg[id].rid=-1;
    }
    else
    {
        int m=(l+r)/2;
        seg[id].lid=build(l,m);
        seg[id].rid=build(m+1,r);
    }
    seg[id].sum=0;
    return id;
}
int update(int idx,int v,int id)
{
    if(id==-1)
        return -1;
    if(idx<seg[id].l || idx>seg[id].r)
        return id;
    int nid = segcnt++;
    seg[nid].l=seg[id].l;
    seg[nid].r=seg[id].r;
    seg[nid].lid=update(idx,v,seg[id].lid);
    seg[nid].rid=update(idx,v,seg[id].rid);
    seg[nid].sum=seg[id].sum+v;
    return nid;
}
int query(int id,int l,int r)
{
    if(r<seg[id].l || seg[id].r<l)
        return 0;
    if (l<=seg[id].l && seg[id].r<=r)
        return seg[id].sum;
    return query(seg[id].lid,l,r)+query(seg[id].rid,l,r);
}
