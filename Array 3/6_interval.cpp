#include<bits/stdc++.h>
using namespace std;

/* 
Problem: Merge overlapping intervals.
*/

/* 
Brute Force Approach:
1. Sort the intervals by their starting times.
2. For each interval:
   - Check if it overlaps with subsequent intervals.
   - Extend the `end` time of the current interval to cover all overlapping intervals.
   - Skip intervals that are already merged into the current one.
3. Push the merged interval into the result.
Time Complexity: O(n^2) - Nested loop to compare and merge intervals.
Space Complexity: O(n) - For storing the resulting merged intervals.
*/
vector<pair<int, int>> mergeOverInterval(vector<pair<int, int>>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort by starting time.
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        int start = nums[i].first;
        int end = nums[i].second;

        // Skip intervals already merged.
        if (!ans.empty() && end <= ans.back().second) {
            continue;
        }

        // Merge all overlapping intervals.
        for (int j = i + 1; j < n; j++) {
            if (nums[j].first <= end) {
                end = max(end, nums[j].second);
            } else {
                break;
            }
        }

        // Add the merged interval to the result.
        ans.push_back({start, end});
    }

    return ans;
}

/* 
Optimal Approach:
1. Sort the intervals by their starting times.
2. Use a single pass to merge overlapping intervals:
   - If the current interval does not overlap with the last interval in the result, add it.
   - Otherwise, update the `end` of the last interval in the result to cover the current interval.
3. Return the result.
Time Complexity: O(n log n) - Sorting dominates the complexity.
Space Complexity: O(n) - For storing the resulting merged intervals.
*/
vector<pair<int, int>> mergeOverIntervalOptimal(vector<pair<int, int>>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort by starting time.
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        // If the result is empty or the current interval does not overlap, add it to the result.
        if (ans.empty() || ans.back().second < nums[i].first) {
            ans.push_back(nums[i]);
        } else {
            // Merge overlapping intervals by updating the `end`.
            ans.back().second = max(ans.back().second, nums[i].second);
        }
    }

    return ans;
}

int main() { 
    int t;
    cout << "\nEnter Number of Test Cases: ";
    cin >> t;

    while (t--) {
        cout << "\nEnter the number of intervals: ";
        int n;
        cin >> n;

        vector<pair<int, int>> intervals(n);
        cout << "\nEnter the intervals (start and end):\n";
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        // Example: Call the optimal solution for testing
        vector<pair<int, int>> result = mergeOverIntervalOptimal(intervals);

        cout << "\nMerged Intervals:\n";
        for (auto& interval : result) {
            cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        cout << endl;
    }

    return 0;
}
