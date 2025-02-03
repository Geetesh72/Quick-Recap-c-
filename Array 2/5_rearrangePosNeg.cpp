
#include <bits/stdc++.h>
using namespace std;

// similart question with variry 2  for this we have agian go back to optimal solution 
vector<int>varity2(vector<int>&nums){

    int n = nums.size();
    vector<int>pos;
    vector<int>neg;
    for(int i = 0;i<n;i++){
        if(nums[i]<0){
            neg.push_back(nums[i]);
        }
        else{
            pos.push_back(nums[i]);
        }
    }
    int cntPos = pos.size();
    int cntNeg  = neg.size();
    vector<int>ans;
    if(cntPos>cntNeg){
        for(int i = 0;i<cntNeg;i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];

        }
        int startPosIndexofAns = cntNeg*2;
        for(int i = cntNeg ; i<cntPos;i++){
            ans[startPosIndexofAns] = pos[i];
            startPosIndexofAns++;
        }
    }
    else{
        for(int i = 0;i<cntPos;i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];

        }
        int startPosIndexofAns = cntPos*2;
        for(int i = cntPos ; i<cntNeg;i++){
            ans[startPosIndexofAns] = neg[i];
            startPosIndexofAns++;
        }

    }
    return ans;

   

}

/* Rearrange array alternately with positive and negative numbers
   Approach: Use two separate arrays for positive and negative numbers, then merge them alternately.
*/
vector<int> rearrange(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            neg.push_back(nums[i]);
        } else {
            pos.push_back(nums[i]);
        }
    }

    // Merge them alternately
    for (int i = 0; i < n / 2; i++) {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
    }
    return nums;
}

/* Optimal approach with one pass
   Intuition:
   - Use a single pass to fill a new array with positive and negative numbers alternately.
   - Keep two pointers (`posIdx` and `negIdx`) for the next position of positive and negative numbers.
*/
vector<int> optimalRearrange(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0); // Resultant array initialized with 0
    int posIdx = 0;        // Pointer for positive index
    int negIdx = 1;        // Pointer for negative index

    // Traverse the array and place positive and negative numbers alternately
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[posIdx] = nums[i];
            posIdx += 2;
        } else if (nums[i] < 0) {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}

/* Varity 2: Handle cases where the count of positive and negative numbers is uneven
   Intuition:
   - Separate positive and negative numbers into two vectors.
   - Alternate between positive and negative numbers until one runs out.
   - Add the remaining numbers at the end.
*/
vector<int> varity2(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            neg.push_back(nums[i]);
        } else {
            pos.push_back(nums[i]);
        }
    }

    int cntPos = pos.size(); // Count of positive numbers
    int cntNeg = neg.size(); // Count of negative numbers
    vector<int> ans;

    // Alternate between positive and negative numbers
    int i = 0, j = 0;
    while (i < cntPos && j < cntNeg) {
        ans.push_back(pos[i++]);
        ans.push_back(neg[j++]);
    }

    // Add remaining positive numbers, if any
    while (i < cntPos) {
        ans.push_back(pos[i++]);
    }

    // Add remaining negative numbers, if any
    while (j < cntNeg) {
        ans.push_back(neg[j++]);
    }

    return ans;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter the elements of the array: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Test the rearrange function
        cout << "Rearranged array (Brute-force): ";
        vector<int> result1 = rearrange(nums);
        for (int num : result1) {
            cout << num << " ";
        }
        cout << endl;

        // Test the optimal rearrange function
        cout << "Rearranged array (Optimal): ";
        vector<int> result2 = optimalRearrange(nums);
        for (int num : result2) {
            cout << num << " ";
        }
        cout << endl;

        // Test the varity2 function
        cout << "Rearranged array (Varity 2): ";
        vector<int> result3 = varity2(nums);
        for (int num : result3) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
