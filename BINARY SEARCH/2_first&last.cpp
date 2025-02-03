#include <bits/stdc++.h>
using namespace std;

// Function to find the first and last occurrence of a target element
// Returns the count of occurrences of the element (ub - lb + 1)
// TC: O(log N), SC: O(1)
int firstLast(vector<int>& nums, int x) {
    int n = nums.size();

    // Find the lower bound (first occurrence of x)
    int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

    // Find the upper bound (index of first element greater than x)
    int ub = upper_bound(nums.begin(), nums.end(), x) - nums.begin() - 1;
    // If the element is not found, return 0
    if (lb > ub || lb >= n || nums[lb] != x) {
        return 0; // Element does not exist
    }
    // Return the count of occurrences of x
    return (ub - lb + 1);
}


// by using raw binary seach 
int fistOcc(vector<int>&nums,int x){
    int n = nums.size();
    int low= 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(nums[mid]==x){
            ans = mid;
            high = mid-1;
        }
        else if(nums[mid]<x){
            low = mid+1;
        }
        else {
            high = mid-1;
        }

    }
    return ans;
}
int lastOcc(vector<int>&nums , int x){
    int n = nums.size();
    int low= 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(nums[mid]==x){
            ans = mid;
            low = mid+1;
        }
        else if(nums[mid]<x){
            low = mid+1;
        }
        else {
            high = mid-1;
        }

    }
    return ans;

}
vector<int> optimal(vector<int>&nums, int k ){
    int first = fistOcc(nums,k);
    int last = lastOcc(nums,k);
    if(first==-1)return {-1,-1};
    return {first,last};
    /*if they say how many then (last-first+1)*/

}



int main() {
    // Example usage of the function
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    // Find the count of occurrences of x
    int count = firstLast(nums, x);
    cout << "Count of " << x << ": " << count << endl;

    return 0;
}
