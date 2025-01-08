#include <bits/stdc++.h>
using namespace std;

class minStack
{
public:
    stack<pair<int, int>> st;
    void pushEle(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }
    void popEle()
    {
        if (!st.empty())
        {
            st.pop();
        }
        else
        {
            cout << "Stack is empty : Cannot pop elements. " << endl;
        }
    }

    int topEle()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        else
        {
            cout << "Stack is empty. No top Element. " << endl;
            return -1;
        }
    }
    int getMin()
    {
        if (!st.empty())
        {
            return st.top().second;
        }
        else
        {
            cout << "Stack is empty. No minimum element. " << endl;
            return -1;
        }
    }
};
int main()
{
    minStack ms;

    ms.pushEle(5);
    ms.pushEle(3);
    ms.pushEle(7);
    ms.pushEle(2);

    cout << "Minimum element: " << ms.getMin() << endl;  // Output: 2
    cout << "Top element: " << ms.topEle() << endl;      // Output: 2

    ms.popEle();

    cout << "Minimum element after pop: " << ms.getMin() << endl;  // Output: 3
    cout << "Top element after pop: " << ms.topEle() << endl;      // Output: 7
    return 0;
}