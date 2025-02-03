#include <bits/stdc++.h>
using namespace std;

/*
Koko Eating Bananas Problem:
- Koko can only move to the next pile after finishing the current one.
- Objective: Minimize the eating speed such that she finishes all bananas within k hours.

Approach:
1. Use binary search on the answer (eating speed).
2. Range of search: [1, max element in the array].
3. For a given eating speed (mid), calculate the total time required using a helper function.
4. If total time is <= k, minimize the eating speed (search in the left half).
5. If total time is > k, increase the eating speed (search in the right half).
*/

/*
Helper Function:
Calculates the total hours Koko needs to eat all bananas at a given eating speed.
- nums: Array representing the piles of bananas.
- mid: Current eating speed.
- Returns the total hours required.
*/
int calculateTime(vector<int>& nums, int mid) {
    int totalHours = 0;
    for (int i = 0; i < nums.size(); i++) {
        totalHours += ceil((double)nums[i] / (double)mid); // Ceil to account for partial piles.
    }
    return totalHours;
}

/*
Binary Search Function:
Finds the minimum eating speed such that Koko finishes all bananas within k hours.
- nums: Array representing the piles of bananas.
- k: Maximum number of hours Koko has to eat all bananas.
*/
int kokoEatingBanana(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 1;
    int high = *max_element(nums.begin(), nums.end()); // Maximum pile size.
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Current eating speed.
        int time = calculateTime(nums, mid);

        if (time <= k) {
            ans = mid;       // Valid eating speed found, try minimizing further.
            high = mid - 1;  // Search in the left half.
        } else {
            low = mid + 1;   // Increase eating speed, search in the right half.
        }
    }
    return ans; // Minimum eating speed to finish within k hours.
}

int main() {
    vector<int> piles = {3, 6, 7, 11}; // Example input.
    int k = 8; // Maximum hours Koko has.

    int result = kokoEatingBanana(piles, k);
    cout << "Minimum eating speed: " << result << endl; // Output the result.

    return 0;
}
