#include <bits/stdc++.h>
using namespace std;

/*  
    ==============================
    ||       HEAP CONCEPTS       ||
    ==============================

    1️⃣ **Complete Binary Tree**:
       - A binary tree where every level is **fully filled** except possibly the last.
       - The last level is **filled from left to right**.

    2️⃣ **Max Heap & Min Heap**:
       - **Max Heap**: Each **parent node is greater** than or equal to its children.
       - **Min Heap**: Each **parent node is smaller** than or equal to its children.

    3️⃣ **Operations in Max Heap**:
       ✅ **Insertion**:
          - Insert the element at the **leftmost available position**.
          - Perform **Heapify Up (Bubble Up)**: Swap with parent until heap property is restored.

       ✅ **Deletion (Extract Max)**:
          - Remove the **root (maximum element)**.
          - Replace it with the **last node**.
          - Perform **Heapify Down**: Swap with the **largest child** until heap property is restored.

       ✅ **Heap Sort**:
          - Extract elements one by one.
          - Results in a **sorted array in descending order**.

    4️⃣ **Heapify & Priority Queue**:
       - **Heapify**: Converts an **unordered array into a heap efficiently**.
       - **Priority Queue**:
         - **Min Heap** → Smallest element has **highest priority**.
         - **Max Heap** → Largest element has **highest priority**.
*/

/**
 * Class: MaxHeap
 * Implements a Max Heap with insertion, deletion, and heapify operations.
 */
class MaxHeap {
public:
    vector<int> heap;

    /**
     * Inserts a value into the heap.
     * Time Complexity: O(log N)
     */
    void insert(int val) {
        heap.push_back(val); // Insert at the end
        int i = heap.size() - 1;

        // Heapify Up (Bubble Up)
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]); // Swap with parent
            i = (i - 1) / 2; // Move up the tree
        }
    }

    /**
     * Prints the heap elements.
     */
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

/**
 * Class: MaxHeap_N
 * Builds a Max Heap efficiently from an existing array using Heapify.
 */
class MaxHeap_N {
public:
    vector<int> heap;

    /**
     * Constructor: Builds the Max Heap from an array.
     * Time Complexity: O(N)
     */
    MaxHeap_N(vector<int>& nums) {
        heap = nums;
        int n = heap.size();

        // Heapify all non-leaf nodes
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    /**
     * Heapify function to maintain max heap property.
     * Time Complexity: O(log N)
     */
    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child is larger
        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        // Check if right child is larger
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        // Swap if needed and recursively heapify
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest, n);
        }
    }

    /**
     * Prints the heap elements.
     */
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    // Example Usage of MaxHeap
    MaxHeap h;
    h.insert(10);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.insert(4);
    h.insert(0);

    cout << "Max Heap using insertions: ";
    h.printHeap(); // Expected Output: 10 5 4 2 1 3 0

    // Example Usage of MaxHeap_N (Heapify an existing array)
    vector<int> arr = {2, 10, 1, 5, 3, 4, 0};
    MaxHeap_N heapFromArray(arr);

    cout << "Max Heap built using Heapify: ";
    heapFromArray.printHeap(); // Expected Output: 10 5 4 2 3 1 0

    return 0;
}
