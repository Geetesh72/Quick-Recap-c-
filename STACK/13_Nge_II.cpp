#include <bits/stdc++.h>
using namespace std;

/*Idea
What i learned from this quesiton idea is simple
how to double the array and run inner loop
like this
0  1  2   3  4  5  6  7  8  9  index
2 10 12   1 11  2  10 12  1  11  fouble so that accesing in loop and get circular array is  going to easy
so what next how i get index
j = i+N-1 running loop till here

 */
vector<int> Nge_II(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + n - 1; j++)
        {
            int idx = j % n;
            if (nums[idx] > nums[i])
            {
                ans[i] = nums[idx];
                break;
            }
        }
    }
    return ans;
}
/* WHat are the mistake 
-> forgot to modulo so i am getting wrong indexs 
-> understand correctly but implement wrongly st.top()<=nums[i]
*/
vector<int> nge_II(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
        }
        st.push(nums[i % n]);
    }
    return ans;
}

/*Time big of O(4N) 
*/
void photo(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl
         << endl;
}
int main()
{
    vector<int> nums = {2, 10, 12, 1, 11};
    photo(nums);
    nums = nge_II(nums);
    photo(nums);
    nums = Nge_II(nums);
    photo(nums);
    return 0;
}