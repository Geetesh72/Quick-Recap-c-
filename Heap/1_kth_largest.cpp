#include <bits/stdc++.h>
using namespace std;

/*
    ===========================================
    ||       PRIORITY QUEUE IN C++          ||
    ===========================================

    1️⃣ **Definition of Priority Queue**:
       - **Max Heap** (Default): Largest element has the **highest priority** and appears on top.
         ```cpp
         priority_queue<int> maxHeap;
         ```
       - **Min Heap**: Smallest element has the **highest priority**.
         ```cpp
         priority_queue<int, vector<int>, greater<int>> minHeap;
         ```

    2️⃣ **Finding the K-th Largest Element**:
       ✅ **Method 1 (Using Max Heap)**:
          - Insert all elements into a **max heap**.
          - Remove the **top element K times** to get the K-th largest.

       ✅ **Method 2 (Using Min Heap - Optimized for Large Arrays)**:
          - Maintain a **min heap of size K**.
          - Only store the **K largest elements**.
          - The **top of the min heap is the K-th largest**.
*/

/**
 * Function: kthLargestElement
 * Finds the K-th largest element using a Max Heap.
 * Time Complexity: O(N log N) (Heap Insert: log N, repeated N times)
 */
int kthLargestElement(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int> maxHeap;

    // Insert all elements into the Max Heap
    for (int i = 0; i < n; i++) {
        maxHeap.push(nums[i]);
    }

    // Remove top element K-1 times
    while (--k) {
        maxHeap.pop();
    }

    return maxHeap.top(); // K-th largest element
}

/**
 * Function: kthLargest
 * Finds the K-th largest element using a Min Heap (Optimized).
 * Time Complexity: O(N log K) (Heap Insert/Delete: log K, repeated N times)
 */
int kthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert first K elements into the Min Heap
    for (int i = 0; i < k; i++) {
        minHeap.push(nums[i]);
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        if (nums[i] > minHeap.top()) {
            minHeap.pop();        // Remove the smallest element
            minHeap.push(nums[i]); // Insert the larger element
        }
    }

    return minHeap.top(); // K-th largest element
}

int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    int k = 3;

    cout << "K-th Largest Element (Using Max Heap): " << kthLargestElement(arr, k) << endl;
    cout << "K-th Largest Element (Using Min Heap - Optimized): " << kthLargest(arr, k) << endl;

    return 0;
}
