struct trie
{
	struct trie* ara[26];
	ll cnt;
};
trie* create()
{
	struct trie *root=NULL;
	root=(trie *)malloc(sizeof(struct trie));
	for(int i=0;i<26;i++)
		root->ara[i]=NULL;
	root->cnt=0;
	return root;
}
void add(trie *root,string s)
{
	if(s.size()==0)
		return ;
	ll ind=0;
	for(ind=0;ind<s.size();ind++)
	{
		if(root->ara[s[ind]-'a']==NULL)
			root->ara[s[ind]-'a']=create();

		root=root->ara[s[ind]-'a'];
		root->cnt++;
	}
}
ll findoccur(trie *root,string s)
{
	if(s.size()==0)
		return 0;
	ll ind;
	for(ind=0;ind<s.size();ind++)
	{
		if(root->ara[s[ind]-'a']==NULL)
			return 0;
		root=root->ara[s[ind]-'a'];
	}
	return root->cnt;
}
int main()
{
	ll n,q,i;
	sll(n,q);
	trie *root=create();
	rep(i,n)
    {
		string s;
		cin>>s;
        add(root,s);
	}
	while(q--)
	{
		string s;
		cin>>s;
		printf("%lld\n",findoccur(root,s));
	}
}
