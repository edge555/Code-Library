struct dysegtree
{
    ll Sum;
	dysegtree *left,*right;
    dysegtree(ll _Sum,dysegtree *_left,dysegtree *_right)
    {
        Sum=_Sum;
        left=_left;
        right=_right;
    }
};
void update(dysegtree *root,int l,int r,int s,int e,ll value)
{
    if(s>r || l>e)
        return;
    if(l>=s && r<=e)
    {
        root->Sum+=value;
        return;
    }
    if(root->left==NULL)
        root->left=new dysegtree(0,NULL,NULL);
    if(root->right==NULL)
        root->right=new dysegtree(0,NULL,NULL);
    update(root->left,l,(l+r)/2,s,e,value);
    update(root->right,(l+r)/2+1,r,s,e,value);
}
ll query(dysegtree *root,int l,int r,int idx)
{
    if(root==NULL || idx>r || l>idx)
        return 0;
    if(l==r)
        return root->Sum;
	return root->Sum+query(root->left,l,(l+r)/2,idx)+query(root->right,(l+r)/2+1,r,idx);
}
int main()
{
    int N,Q;
    cin>>N>>Q;
    dysegtree *root=new dysegtree(0,NULL,NULL);
    rep(i,N)
    {
        int x;
        cin>>x;
        update(root,1,N,i,i,x);
    }
    while(Q--)
    {
        int choice;
        cin>>choice;
        //choice 1 for update ,2 for query at index x
        if(choice==1)
        {
            int L,R,value;
            cin>>L>>R>>value;
            update(root,1,N,L,R,value);
        }
        else
        {
            int idx;
            cin>>idx;
            printf("%lld\n",query(root,1,N,idx));
        }
    }
}
