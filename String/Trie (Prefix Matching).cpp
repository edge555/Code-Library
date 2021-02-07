struct node
{
    bool endmark;
    int cnt=0;
    node* next[27];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void Insert(string& str)
{
    int len=str.size();
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
    curr->endmark = true;
}
string Search(string& str)
{
    int len=str.size();
    node* curr = root;
    string s;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        s.push_back(str[i]);
        if (curr->next[id] == NULL)
            return "No word found!";
        curr = curr->next[id];
    }
    if(curr->endmark)
        return s;
}
int CountOccur(string& str)
{
    if(str.size()==0)
        return 0;

    int len=str.size();
    node* curr = root;
    string s;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return 0;
        curr = curr->next[id];
    }
    return curr->cnt;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}
//root = new node();