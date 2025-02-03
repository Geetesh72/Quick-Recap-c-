#include <bits/stdc++.h>
using namespace std;

/*
    ===========================================
    ||     FIND MEDIAN OF DATA STREAM       ||
    ===========================================

    📝 **Problem Statement**:
    - Maintain a data stream and efficiently find the median of numbers added so far.
    - The median is the middle value in an ordered integer list. If the list size is even, the median is the average of the two middle numbers.

    ✅ **Efficient Approach (Using Two Heaps - MaxHeap & MinHeap)**:
       - Use a **max heap (left_maxHeap)** for the left half of numbers (stores smaller half).
       - Use a **min heap (right_minHeap)** for the right half (stores larger half).
       - Maintain **heap balance**: sizes should differ by at most 1.
       - Median:
         - If both heaps have equal size, the median is the average of top elements.
         - If not, the median is the top element of `left_maxHeap` (which has more elements).

    🔥 **Time Complexity**:
       - **Insertion (addNum)**: `O(log N)` (heap insertion)
       - **Finding Median (findMedian)**: `O(1)`
*/

/**
 * Class: MedianFinder
 * Maintains a dynamic stream of numbers and finds the median efficiently.
 */
class MedianFinder {
public:
    // Max Heap for the left half (stores smaller numbers)
    priority_queue<int> left_maxHeap;

    // Min Heap for the right half (stores larger numbers)
    priority_queue<int, vector<int>, greater<int>> right_minHeap;

    // Constructor
    MedianFinder() {}

    // Function to add a number to the data stream
    void addNum(int num) {
        // Insert into the correct heap
        if (left_maxHeap.empty() || num < left_maxHeap.top()) {
            left_maxHeap.push(num);
        } else {
            right_minHeap.push(num);
        }

        // Balance the heaps (size difference should be at most 1)
        if (left_maxHeap.size() > right_minHeap.size() + 1) {
            right_minHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        } else if (left_maxHeap.size() < right_minHeap.size()) {
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }

    // Function to return the median of the current data stream
    double findMedian() {
        if (left_maxHeap.size() == right_minHeap.size()) {
            return (left_maxHeap.top() + right_minHeap.top()) / 2.0; // Fix: Use both heaps' top
        } else {
            return left_maxHeap.top(); // Odd count, max heap has more elements
        }
    }
};

/**
 * Usage:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double median = obj->findMedian();
 */

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2

    return 0;
}
