#include <bits/stdc++.h>
using namespace std;

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

int maxiRectangle(vector<vector<int>>&nums){
    int n = nums.size();
    int m = nums[0].size();
    int maxArea = INT_MIN;
    vector<int>heights(m,0);
    for(int i = 0;i<n;i++)
    {   
        for(int j = 0;j<m;j++){
           // Update heights based on the current row.
            if (nums[i][j] == 0) {
                heights[j] = 0;  // Reset height if the cell is 0.
            } else {
                heights[j] += nums[i][j];  // Add 1 to height if the cell is 1.
            }

        }
        maxArea =max(maxArea,maxiReact(heights));

    }
    return maxArea;
}
int main()
{
    vector<vector<int>> nums = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    cout << "Maximum Rectangle Area: " << maxiRectangle(nums) << endl;
    return 0;
}