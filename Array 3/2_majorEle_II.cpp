#include<bits/stdc++.h>
using namespace std;

/* 
Brute Force Approach:
1. Iterate through each element in the array.
2. Count the occurrences of the current element.
3. If the count exceeds n/3, add the element to the result.
4. Ensure no duplicates are added by checking the result array.
Time Complexity: O(n^2) - Nested loops to count occurrences.
Space Complexity: O(1) - No extra space except the result array.
*/
vector<int> mjoElbrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ans.size() == 0 || ans.back() != nums[i]) {
            cnt = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > n / 3) {
                ans.push_back(nums[i]);
            }

            if (ans.size() == 2) {
                break;
            }
        }     
    }
    return ans;
}

/* 
Better Approach:
1. Use an unordered_map to count the frequency of each element.
2. Iterate through the map to check which elements have frequency > n/3.
3. Add those elements to the result array.
Time Complexity: O(n) - Single traversal for counting and another traversal to collect results.
Space Complexity: O(n) - Space required for the unordered_map.
*/
vector<int> betterMjoEl(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> umap;
    int mm = (n / 3) + 1;
    vector<int> ans;

    for (int num : nums) {
        umap[num]++;
    }
    for (auto it : umap) {
        if (it.second > n / 3) {
            ans.push_back(it.first);
        }
    }
    return ans;
}

/* 
Optimal Approach (Boyer-Moore Voting Algorithm):
1. Maintain two potential majority elements (mjo1, mjo2) and their counts (cnt1, cnt2).
2. In the first pass, identify the two most frequent candidates by adjusting counts based on matches or mismatches.
3. In the second pass, validate the counts of the candidates to ensure they exceed n/3.
Time Complexity: O(n) - Two linear traversals of the array.
Space Complexity: O(1) - No extra data structures are used.
*/
vector<int> optimalMjoEl(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    int cnt1 = 0;
    int cnt2 = 0;
    int mjo1 = -1;
    int mjo2 = -1;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && nums[i] != mjo2) {
            cnt1 = 1;
            mjo1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != mjo1) {
            cnt2 = 1;
            mjo2 = nums[i];
        }
        else if (mjo1 == nums[i]) cnt1++;
        else if (mjo2 == nums[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == mjo1) cnt1++;
        if (nums[i] == mjo2) cnt2++;
    }
    int mini = (int)(n / 3) + 1;
    if (cnt1 >= mini) ans.push_back(mjo1);
    if (cnt2 >= mini) ans.push_back(mjo2);
    return ans;
}

int main() { 
    int t;
    cout << "\nEnter Number of Test Cases: ";
    cin >> t;

    while (t--) {
        cout << "\nEnter size of array: ";
        int n;
        cin >> n;
        vector<int> nums(n);

        cout << "\nEnter the elements of array: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // You can call the functions here to test
        // Example:
        vector<int> result = optimalMjoEl(nums);
        cout << "Majority Elements: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
