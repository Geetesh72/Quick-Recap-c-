#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Design a Number Containers System
    
    Operations:
    - `change(index, number)`: Insert or replace a number at the given index.
    - `find(number)`: Return the smallest index that contains the given number, or -1 if none exist.
    
    Constraints:
    - 1 <= index, number <= 10^9
    - At most 10^5 calls to `change` and `find` combined.

    Approach:
    - Since `index` values can be large (up to 10^9), using an array of this size is impractical.
    - Instead, we use two hash maps:
      1. `idxToNum`: Maps an index to its assigned number.
      2. `numToIdx`: Maps a number to a set of indices containing that number (sorted automatically).
    - We use `set<int>` inside `numToIdx` to efficiently track the smallest index for each number.

    **Why use `set<int>`?**
    - The `set` keeps indices sorted, allowing `begin()` to return the smallest index in O(1).
    - Efficient insertions and deletions in O(log n) due to `set` properties.

    Time Complexity:
    - `change()` → O(log n) (insertion and deletion in a `set`).
    - `find()` → O(1) (fetching the smallest index).
*/

class NumberContainers {
public:
    unordered_map<int, int> idxToNum;  // Maps index → number
    unordered_map<int, set<int>> numToIdx;  // Maps number → sorted indices

    NumberContainers() {}

    void change(int index, int number) {
        // If index already contains a number, remove its old mapping
        if (idxToNum.count(index)) {
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index);  // Remove the index from old number's set

            // If the old number has no indices left, remove it from the map
            if (numToIdx[prevNum].empty()) {
                numToIdx.erase(prevNum);
            }
        }

        // Assign the new number to the index
        idxToNum[index] = number;
        numToIdx[number].insert(index);  // Insert the index into the set of the new number
    }

    int find(int number) {
        // If the number exists, return the smallest index
        if (numToIdx.count(number)) {
            return *numToIdx[number].begin();
        }
        return -1;  // Number not found
    }
};

int main() {
    NumberContainers nc;
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 20);
    cout << nc.find(10) << endl;  // Output: 1 (smallest index for 10)
    nc.change(1, 15);
    cout << nc.find(10) << endl;  // Output: 2 (smallest index after 1 is removed from 10)
    return 0;
}
