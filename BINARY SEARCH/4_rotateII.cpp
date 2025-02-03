#include<bits/stdc++.h>
using namespace std;
int rotatedSorted(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the target is found
        if (nums[mid] == target) {
            return 1;
        }
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }


        // Check if the left part is sorted
        if (nums[mid] >= nums[low]) {
            // If the target lies in the sorted left part
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // Search in the left part
            } else {
                low = mid + 1;  // Search in the right part
            }
        } else { // Otherwise, the right part is sorted
            // If the target lies in the sorted right part
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Search in the right part
            } else {
                high = mid - 1; // Search in the left part
            }
        }
    }

    // If the target is not found
    return -1;
}
int main(){ 
return 0;
}