struct Stack
{
    stack<int>s;
    int maxEle;
    void getMax()
    {
        if(s.empty())
            cout<<"Stack is empty\n";
        else
            cout<<maxEle<<"\n";
    }
    void peek()
    {
        if(s.empty())
        {
            cout<<"Stack is empty ";
            return;
        }
        int t=s.top();
        (t>maxEle)?cout<<maxEle:cout<<t;
    }
    void pop()
    {
        if(s.empty())
        {
            cout<<"Stack is empty\n";
            return;
        }
        int t=s.top();
        s.pop();
        if(t>maxEle)
        {
            cout<<maxEle<<"\n";
            maxEle=2*maxEle-t;
        }
        else
            cout<<t<<"\n";
    }
    void push(int x)
    {
        if(s.empty())
        {
            maxEle=x;
            s.push(x);
            return;
        }
        if(x>maxEle)
        {
            s.push(2*x-maxEle);
            maxEle=x;
        }
        else
            s.push(x);
    }
};
