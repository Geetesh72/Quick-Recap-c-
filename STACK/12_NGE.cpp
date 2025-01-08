#include <bits/stdc++.h>
using namespace std;
/* ABOUT QUESTION
 It is question of monotonic stack -> store elements in specific order
 what in this question ??
 we have to tell the next greater element in given array
 like that
 arr->  6  0  8  1  3
 nge->  8  8 -1  3 -1  couse 6 nge is 8
      0 nge is 8 , 8 not nge so -1 , 1 3 is nge and so on

*/
// brute force
vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n,-1);
    for (int i = 0; i < n ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                ans[i] = nums[j];
                break;
            }else{
                ans[i]=-1;
            }
           
        }
    }
    return ans;
}



// Optimal one 
/*
Logic to this question in 5 steps 
1-> traverse from  the back of array  & intialize stack along with the ans array 
2-> put the -1 is stack is empty otherwise check for condition 
3-> if nums[i] <= st.top() them pop() untill condition fails 
4-> if greater the simply push the element in that stack 
5-> general bullet points ->1 this monotonic stack example in decreasing order 
                          -> imagine pole that is just next greater of yours behine that pole small with not be visible 
                          ->3 if stack is not empty ans nums[i]> st.top() so ans array store top element of stack 
                          -> 4 that will be the nge for that element okay ?
                          yes 


*/
vector<int>nextGreater(vector<int>&nums){
    int n = nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i] ){
            st.pop();
        }
        if(st.empty())ans[i]=-1;
        else{
            ans[i]=st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}
void photo(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {6, 0, 8, 1, 3};
    nums = nextGreaterElement(nums);
    photo(nums);
    vector<int>ans = nextGreater(nums);
    photo(ans);

    return 0;
}