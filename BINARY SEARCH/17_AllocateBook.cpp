#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
- Given an array `nums` where each element represents the number of pages in a book,
  allocate books to `books` students such that:
  1. Each student gets at least one book.
  2. The maximum number of pages allocated to a student is minimized.

Approach:
- Binary search on the answer (minimum possible maximum pages).
- Key insight: The search space is [max(nums), sum(nums)].
- Use a helper function to check if a given maximum page allocation (`pages`) is feasible.

*/

/*
Helper Function:
- Check if it is possible to allocate books such that no student gets more than `pages`.
- nums: Array of books' pages.
- pages: Maximum number of pages allowed for any student.
- Returns the number of students required for the allocation.
*/
int allocateBook(vector<int>& nums, int pages) {
    int n = nums.size();
    int allocation = 0;  // Pages allocated to the current student.
    int stuCnt = 1;      // Start with one student.

    for (int i = 0; i < n; i++) {
        // If adding the current book exceeds the limit, allocate to a new student.
        if (allocation + nums[i] > pages) {
            stuCnt++;
            allocation = nums[i];  // Start allocation for the new student.
        } else {
            allocation += nums[i];
        }
    }

    return stuCnt;
}

/*
Main Function:
- Minimize the maximum number of pages allocated to any student.
- nums: Array of books' pages.
- books: Number of students.
- Returns the minimized maximum pages.
*/
int allocatingBook(vector<int>& nums, int books) {
    int n = nums.size();

    // Edge case: If there are fewer books than students, allocation is not possible.
    if (books > n) return -1;

    int low = *max_element(nums.begin(), nums.end());  // Minimum possible maximum pages.
    int high = accumulate(nums.begin(), nums.end(), 0);  // Maximum possible pages (all books to one student).
    int ans = -1;

    // Binary search to find the optimal maximum pages.
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Middle point of the current range.

        // Check how many students are required for this maximum page allocation.
        int noOfStud = allocateBook(nums, mid);

        if (noOfStud <= books) {
            ans = mid;  // Update answer since fewer students are needed.
            high = mid - 1;  // Try for a smaller maximum allocation.
        } else {
            low = mid + 1;  // Try for a larger maximum allocation.
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {12, 34, 67, 90};  // Example input (pages in books).
    int books = 2;  // Number of students.

    cout << "Minimized Maximum Pages: " << allocatingBook(nums, books) << endl;

    return 0;
}
