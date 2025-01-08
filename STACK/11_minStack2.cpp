#include <bits/stdc++.h>
using namespace std;

class minStack
{
private:
    stack<long long> st;
    long long minVal;

public:
    minStack()
    {
        minVal = LLONG_MAX;
    }

    void pushEle(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                st.push(2LL * val - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    void popEle()
    {
        if (st.empty())
        {
            cout << "Stack is empty.Cannot pop elements. " << endl;
            return;
        }
        long long topVal = st.top();
        st.pop();
        if (topVal < minVal)
        {
            minVal = 2 * minVal - topVal;
        }
    }

    int topEle()
    {
        if (st.empty())
        {
            cout << "Stack is empty. No top element. " << endl;
            return -1;
        }
        long long topVal = st.top();
        if (topVal < minVal)
        {
            return minVal;
        }
        return topVal;
    }
    int getMin()
    {
        if (st.empty())
        {
            cout << "Stack is empty. No minimum Element. " << endl;
            return -1;
        }
        return minVal;
    }
};
int main()
{
    minStack ms;

    ms.pushEle(5);
    ms.pushEle(3);
    ms.pushEle(7);
    ms.pushEle(2);

    cout << "Minimum element: " << ms.getMin() << endl; // Output: 2
    cout << "Top element: " << ms.topEle() << endl;     // Output: 2

    ms.popEle();

    cout << "Minimum element after pop: " << ms.getMin() << endl; // Output: 3
    cout << "Top element after pop: " << ms.topEle() << endl;
    return 0;
}