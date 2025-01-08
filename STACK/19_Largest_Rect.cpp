#include <bits/stdc++.h>
using namespace std;
vector<int> findNse(vector<int>&nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i = n-1;i>=0;i--){
        if(!st.empty() && nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(st.empty())ans[i]=n;
        else{
          ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
    

}
vector<int>findPse(vector<int>&nums){
   int n = nums.size();
   vector<int>ans(n);
   stack<int>st;
   for(int i = 0;i<n;i++){
      if(!st.empty() && nums[st.top()]>nums[i]){
        st.pop();
      }
      if(st.empty())ans[i]=-1;
      else{
        ans[i]=st.top();
      }
      st.push(i);
   }
   return ans;

}

int maxiRectangle(vector<int>&nums){
    int n = nums.size();
    int maxi  = INT_MIN;
    vector<int>nse  = findNse(nums);
    vector<int>pse = findPse(nums);
    for(int i =0;i<n;i++){
        int width = nse[i] - pse[i] - 1;// Width of the rectangle.
        int area = nums[i] * width; // Area of the rectangle with height nums[i].
        maxi = max(maxi, area); // Update the maximum area.
    }
    return maxi;
}

/*OPTIMAL IDEA 
STEP JUST DOING FORWARD PASSING AND COMPUTE USE FORMULA WHILE POPING OUT 

*/

int maxiReact(vector<int>&nums){
    int n = nums.size();
    stack<int> st;  // Stack to store indices of the histogram bars.
    int maxiArea = INT_MIN;

    // Traverse through each bar in the histogram.
    for (int i = 0; i < n; i++) {
        // Process all bars in the stack that are taller than the current bar.
        while (!st.empty() && nums[st.top()] > nums[i]) {
            int element = st.top();  // Index of the bar being processed.
            st.pop();
            int nse = i;  // The current index is the Next Smaller Element (NSE).
            int pse = st.empty() ? -1 : st.top();  // Top of the stack is the Previous Smaller Element (PSE).
            // Calculate the area for the bar at 'element'.
            maxiArea = max(maxiArea, (nse - pse - 1) * nums[element]);
        }
        st.push(i);  // Push the current index onto the stack.
    }

    // Process remaining bars in the stack.
    while (!st.empty()) {
        int element = st.top();
        st.pop();
        int nse = n;  // NSE for remaining elements is the end of the array.
        int pse = st.empty() ? -1 : st.top();  // PSE is the top of the stack.
        maxiArea = max(maxiArea, (nse - pse - 1) * nums[element]);
    }

    return maxiArea;  
}

int main()
{
    vector<int> nums2 = {2, 1, 5, 6, 2, 3}; // Example histogram heights.
    vector<int>nums = nums2;
    cout << "Maximum Rectangle Area: " << maxiRectangle(nums) << endl;
    nums   = nums2;
    cout << "Maximum Rectangle Area: " << maxiReact(nums) << endl;
    
    return 0;
}