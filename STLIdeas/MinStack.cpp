
#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {}

    void push(int x)
    {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    void pop()
    {
        if (s.empty())
            return;
        if (s.top() == minStack.top())
        {
            minStack.pop();
        }
        s.pop();
    }

    int top()
    {
        if (s.empty())
            return -1;
        return s.top();
    }

    int getMin()
    {
        if (minStack.empty())
            return -1;
        return minStack.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    MinStack s;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (op == "pop")
        {
            s.pop();
        }
        else if (op == "top")
        {
            cout << s.top() << "\n";
        }
        else if (op == "getMin")
        {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}
