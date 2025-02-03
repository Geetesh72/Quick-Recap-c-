#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the top K most frequent elements in an array.
 * 
 * Approach:
 * 1. Use an unordered_map to count the frequency of each element.
 * 2. Use a min-heap (priority_queue with greater comparator) to store the top K elements.
 * 3. Push elements into the heap, and maintain only K elements in the heap.
 * 4. Extract the top K elements from the heap and return them as the result.
 *
 * Time Complexity: O(N log K) where N is the size of nums, and we maintain a heap of size K.
 * Space Complexity: O(N) due to hash map storage.
 */

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Min-heap to store the K most frequent elements (sorted by frequency)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    
    // Hash map to store the frequency of each element
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Push elements into the min-heap, keeping only the K most frequent elements
    for (auto it : frequencyMap) {
        int val = it.first;
        int freq = it.second;
        minHeap.push({freq, val});
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the least frequent element
        }
    }

    // Extract top K elements from the heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    return 0;
}
