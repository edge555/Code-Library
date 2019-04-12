struct fenwick
{
    int x;
    vector<int>tree;
    fenwick(int n):x(n)
    {
        tree.resize(n+1);
    }
    void update(int pos,int val)
    {
        while(pos<=x)
        {
            tree[pos]+=val;
            pos+=(pos&-pos);
        }
    }
    void update(int l,int r,int val)
    {
        update(l,val);
        update(r+1,-val);
    }
    int query(int pos)
    {
        int sum=0;
        while(pos)
        {
            sum+=tree[pos];
            pos-=(pos&-pos);
        }
        return sum;
    }
};
main:
{
    fenwick fnw(n);
    fnw.update(l,r,value);
    fnw.query(index)
}
